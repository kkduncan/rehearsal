// Implementation of tree.h

#include <collections/rbtree.h>
#include <functional>
#include <algorithm>

template <typename T>
kd::RBTree<T>::RBTree() : mRoot(nullptr), mSize(0)
{
    
}

template <typename T>
kd::RBTree<T>::~RBTree()
{
	this->clear();
}

template <typename T>
void kd::RBTree<T>::insert(const T& val)
{
    // Lambda to assist with insertions
    static std::function <bool (typename RBNode::Ptr&, const typename RBNode::Ptr)> insertHelper = [&] (typename RBNode::Ptr& currNode,
                                                                                                        const typename RBNode::Ptr newNode)
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
    
    typename RBNode::Ptr newNode = new RBNode(val);
    if (insertHelper(this->mRoot, newNode))
    {
        ++mSize;
    }
}

template <typename T>
bool kd::RBTree<T>::remove(const T& val)
{
	static std::function<bool(typename RBNode::Ptr, typename RBNode::Ptr, const T&)> removeHelper =
		[&](typename RBNode::Ptr parentNode, typename RBNode::Ptr currNode, const int& val)
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
					typename RBNode::Ptr tempNode = currNode->mLeft;

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
bool kd::RBTree<T>::find(const T& val) const
{
	static std::function <bool(typename RBNode::Ptr, const T&)> findHelper = [&](typename RBNode::Ptr node,
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
const T kd::RBTree<T>::getMax(typename RBNode::Ptr aNode) const
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
const T kd::RBTree<T>::getMax() const
{
	return getMax(this->mRoot);
}

template <typename T>
const T kd::RBTree<T>::getMin(typename RBNode::Ptr aNode) const
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
const T kd::RBTree<T>::getMin() const
{
	return getMin(this->mRoot);
}

template <typename T>
bool kd::RBTree<T>::isEmpty() const
{
    return this->mRoot == nullptr;
}

template <typename T>
size_t kd::RBTree<T>::size() const
{
    return mSize;
}

template <typename T>
int kd::RBTree<T>::height() const
{
    static std::function<int (typename RBNode::Ptr)> heightHelper = [&](typename RBNode::Ptr node)
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
void kd::RBTree<T>::clear()
{
	static std::function<void(typename RBNode::Ptr&)> clearHelper = [&](typename RBNode::Ptr& aNode)
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
void kd::RBTree<T>::getElementsPreOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
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
void kd::RBTree<T>::getElementsInOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
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
void kd::RBTree<T>::getElementsPostOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
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
void kd::RBTree<T>::getElementsLevelOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
{
    std::function<void (typename RBNode::Ptr, int, std::vector<T>&)> getLevelElems = [&] (typename RBNode::Ptr node,
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
std::vector<T> kd::RBTree<T>::getElementList(const Traversal& traversal /* = InOrder */) const
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

