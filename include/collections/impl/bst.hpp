// Implementation of Binary Search Tree
#include <collections/bst.h>
#include <functional>
#include <algorithm>

template <typename T>
kd::BSTree<T>::BSTree() : mRoot(nullptr), mSize(0)
{

}

template <typename T>
kd::BSTree<T>::~BSTree()
{
	this->clear();
}

template <typename T>
void kd::BSTree<T>::insert(const T& val)
{
    // Lambda to assist with insertions
    static std::function<bool (typename Node::Ptr&, const typename Node::Ptr)> insertHelper = [&] (typename Node::Ptr& currNode,
                                                                                                   const typename Node::Ptr newNode)
    {
        if (currNode == nullptr)
        {
            currNode = newNode;
        }
        else
        {
            if (newNode->mValue == currNode->mValue)
            {
                // Avoid duplicates
                return false;
            }
            else if (newNode->mValue < currNode->mValue)
            {
                return insertHelper(currNode->mLeft, newNode);
            }
            else
            {
                return insertHelper(currNode->mRight, newNode);
            }
        }
        
        return true;
    };
    
    typename Node::Ptr newNode = new Node(val);
    if (insertHelper(this->mRoot, newNode))
    {
        ++mSize;
    }
}

template <typename T>
bool kd::BSTree<T>::remove(const T& val)
{
	static std::function<bool(typename Node::Ptr, typename Node::Ptr, const T&)> removeHelper = 
		[&](typename Node::Ptr parentNode, typename Node::Ptr currNode, const int& val)
	{
		if (currNode == nullptr)
		{
			return false;
		}
		else
		{
			if (currNode->mValue == val)
			{
				// Case 1: Node is a leaf  --AND--
				// Case 2: Node has one child
				if (currNode->mLeft == nullptr || currNode->mRight == nullptr)
				{
#ifdef _WIN32
					kd::BSTree<T>::Node::Ptr tempNode = currNode->mLeft;
#else
                    typename kd::BSTree<T>::Node::Ptr tempNode = currNode->mLeft;
#endif

					if (currNode->mRight != nullptr)
					{
						tempNode = currNode->mRight;
					}

					if (parentNode != nullptr)
					{
						if (parentNode->mLeft == currNode)
						{
							parentNode->mLeft = tempNode;
						}
						else
						{
							parentNode->mRight = tempNode;
						}
					}
					else
					{
						this->mRoot = tempNode;
					}
				}
				// Case 3: Has two children
				else
				{
					const T& minRightTreeVal = this->getMin(currNode->mRight);
					currNode->mValue = minRightTreeVal;
					removeHelper(currNode, currNode->mRight, minRightTreeVal);
				}

				delete currNode;
				--mSize;
				return true;
			}
			else
			{
				return removeHelper(currNode, currNode->mLeft, val) || removeHelper(currNode, currNode->mRight, val);
			}
		}
	};

	return removeHelper(nullptr, this->mRoot, val);
}

template <typename T>
bool kd::BSTree<T>::find(const T& val) const
{
	static std::function <bool(typename Node::Ptr, const T&)> findHelper = [&](typename Node::Ptr node, 
																			   const T& val)
	{
		if (node == nullptr)
		{
			return false;
		}
		else
		{
			if (node->mValue == val)
			{
				return true;
			}
			else if (node->mValue > val)
			{
				return findHelper(node->mLeft, val);
			}
			else
			{
				return findHelper(node->mRight, val);
			}
		}
	};

	return findHelper(this->mRoot, val);	
}

template <typename T>
const T kd::BSTree<T>::getMax(typename Node::Ptr aNode) const
{
	if (aNode == nullptr)
	{
		return std::numeric_limits<T>::min();
	}
	else
	{
		if (aNode->mRight == nullptr)
		{
			return aNode->mValue;
		}
		else
		{
			return getMax(aNode->mRight);
		}
	}
};

template <typename T>
const T kd::BSTree<T>::getMax() const
{
	return getMax(this->mRoot);
}

template <typename T>
const T kd::BSTree<T>::getMin(typename Node::Ptr aNode) const
{
	if(aNode == nullptr)
	{
		return std::numeric_limits<T>::max();
	}
		else
		{
			if (aNode->mLeft == nullptr)
			{
				return aNode->mValue;
			}
			else
			{
				return getMin(aNode->mLeft);
			}
		}
};

template <typename T>
const T kd::BSTree<T>::getMin() const
{
	return getMin(this->mRoot);
}

template <typename T>
bool kd::BSTree<T>::isEmpty() const
{
    return this->mRoot == nullptr;
}

template <typename T>
size_t kd::BSTree<T>::size() const
{
    return mSize;
}

template <typename T>
int kd::BSTree<T>::height() const
{
    static std::function<int (typename Node::Ptr)> heightHelper = [&](typename Node::Ptr node)
    {
        if (node == nullptr)
        {
            return static_cast<int>(-1);
        }
        else
        {
            return 1 + std::max(heightHelper(node->mLeft), heightHelper(node->mRight));
        }
    };
    
    auto h = heightHelper(this->mRoot);
    return h >= 0 ? h : 0;
}

template <typename T>
void kd::BSTree<T>::clear()
{
	static std::function<void(typename Node::Ptr&)> clearHelper = [&](typename Node::Ptr& aNode)
	{
		if (aNode == nullptr)
		{
			return;
		}

		clearHelper(aNode->mLeft);
		clearHelper(aNode->mRight);
		delete aNode;
		aNode = nullptr;

		--mSize;		
	};

	clearHelper(this->mRoot);
}

template <typename T>
void kd::BSTree<T>::getElementsPreOrder(typename Node::Ptr node, std::vector<T>& elems) const
{
    if (node == nullptr)
    {
        return;
    }
    
    elems.push_back(node->mValue);
    getElementsPreOrder(node->mLeft, elems);
    getElementsPreOrder(node->mRight, elems);
}

template <typename T>
void kd::BSTree<T>::getElementsInOrder(typename Node::Ptr node, std::vector<T>& elems) const
{
    if (node == nullptr)
    {
        return;
    }
    
    getElementsInOrder(node->mLeft, elems);
    elems.push_back(node->mValue);
    getElementsInOrder(node->mRight, elems);
}

template <typename T>
void kd::BSTree<T>::getElementsPostOrder(typename Node::Ptr node, std::vector<T>& elems) const
{
    if (node == nullptr)
    {
        return;
    }
    
    getElementsPostOrder(node->mLeft, elems);
    getElementsPostOrder(node->mRight, elems);
    elems.push_back(node->mValue);
}

template <typename T>
void kd::BSTree<T>::getElementsLevelOrder(typename Node::Ptr node, std::vector<T>& elems) const
{
    std::function<void (typename Node::Ptr, int, std::vector<T>&)> getLevelElems = [&] (typename Node::Ptr node,
                                                                                        int level,
                                                                                        std::vector<T>& elems)
    {
        if (node == nullptr)
        {
            return;
        }
        
        if (level == 1)
        {
            elems.push_back(node->mValue);
        }
        else if (level > 1)
        {
            getLevelElems(node->mLeft,  level - 1, elems);
            getLevelElems(node->mRight, level - 1, elems);
        }
    };
    
    auto levels = this->height() + 1;
    for (auto level = 1; level <= levels; ++level)
    {
        getLevelElems(this->mRoot, level, elems);
    }
}


template <typename T>
std::vector<T> kd::BSTree<T>::getElementList(const Traversal& traversal /* = InOrder */) const
{
    std::vector<T> elems;
    elems.reserve(mSize);
    
    switch(traversal)
    {
        case PreOrder:
            this->getElementsPreOrder(this->mRoot, elems);
            break;
            
        case PostOrder:
            this->getElementsPostOrder(this->mRoot, elems);
            break;
            
        case LevelOrder:
            this->getElementsLevelOrder(this->mRoot, elems);
            break;
            
        default:
            this->getElementsInOrder(this->mRoot, elems);
            break;
    }
    
    return std::move(elems);    
}

