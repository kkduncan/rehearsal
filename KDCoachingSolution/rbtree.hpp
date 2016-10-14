// Implementation of RBTree.h
#include "rbtree.h"
#include <functional>
#include <algorithm>

using namespace kd;

template <typename T>
RBTree<T>::RBTree() : mNilNode(new RBTree<T>::RBNode(std::numeric_limits<T>::max())), mRoot(mNilNode), mSize(0)
{
	mNilNode->mColor = Color::Black;
}


template <typename T>
RBTree<T>::~RBTree()
{
	this->clear();
}


template <typename T>
void RBTree<T>::leftRotate(typename RBTree<T>::RBNode::Ptr rotatingNode)
{
	RBTree<T>::RBNode::Ptr rightChild = rotatingNode->mRight;
	if (rotatingNode->mParent == this->mNilNode)
	{
		this->mRoot = rightChild;
	}
	else
	{
		if (rotatingNode == rotatingNode->mParent->mLeft)
		{
			rotatingNode->mParent->mLeft = rightChild;
		}
		else
		{
			rotatingNode->mParent->mRight = rightChild;
		}
	}

	rightChild->mParent = rotatingNode->mParent;
	rotatingNode->mRight = rightChild->mLeft;
	rightChild->mLeft->mParent = rotatingNode;
	rightChild->mLeft = rotatingNode;
	rotatingNode->mParent = rightChild;
}


template <typename T>
void RBTree<T>::rightRotate(typename RBTree<T>::RBNode::Ptr rotatingNode)
{
	RBTree<T>::RBNode::Ptr leftChild = rotatingNode->mLeft;
	if (rotatingNode->mParent == this->mNilNode)
	{
		this->mRoot = leftChild;
	}
	else
	{
		if (rotatingNode->mParent->mLeft == rotatingNode)
		{
			rotatingNode->mParent->mLeft = leftChild;
		}
		else
		{
			rotatingNode->mParent->mRight = leftChild;
		}
	}

	leftChild->mParent = rotatingNode->mParent;
	rotatingNode->mLeft = leftChild->mRight;
	leftChild->mRight->mParent = rotatingNode;
	leftChild->mRight = rotatingNode;
	rotatingNode->mParent = leftChild;
}


template <typename T>
void RBTree<T>::insert(const T& val)
{
	RBTree<T>::RBNode::Ptr newNode = new RBTree<T>::RBNode(val);
	RBTree<T>::RBNode::Ptr currNode = this->mRoot;
	RBTree<T>::RBNode::Ptr prevNode = this->mNilNode;
	
	while (currNode != this->mNilNode)
	{
		prevNode = currNode;

		if (val == currNode->mValue)
		{
			// Avoids duplicates
			return;
		}
		else if (val < currNode->mValue)
		{
			currNode = currNode->mLeft;
		}
		else
		{
			currNode = currNode->mRight;
		}
	}

	// Set the parent of this node
	newNode->mParent = prevNode;
	if (prevNode == this->mNilNode)
	{
		this->mRoot = newNode;
	}
	else
	{
		if (newNode->mValue < prevNode->mValue)
		{
			prevNode->mLeft = newNode;
		}
		else
		{
			prevNode->mRight = newNode;
		}
	}

	// Set the children of this new node and its color
	newNode->mLeft = mNilNode;
	newNode->mRight = mNilNode;
	newNode->mColor = Color::Red;

	// Increment size
	++mSize;

	// Balance the tree
	fixAfterInsert(newNode);
}


template <typename T>
void RBTree<T>::fixAfterInsert(typename RBTree<T>::RBNode::Ptr currNode)
{
	if (currNode->mParent != this->mNilNode)
	{
		// If there is a Red-Red violation
		while (currNode->mParent != this->mNilNode && currNode->mParent->mColor == Color::Red)
		{
			// If the current node's parent is a LEFT CHILD
			if (currNode->mParent == currNode->mParent->mParent->mLeft)
			{
				RBTree<T>::RBNode::Ptr uncleNode = currNode->mParent->mParent->mRight;

				// Case 1: If uncle node is Red
				if (uncleNode->mColor == Color::Red)
				{
					// Fix: Switch colors
					currNode->mParent->mColor = Color::Black;
					uncleNode->mColor = Color::Black;
					currNode->mParent->mParent->mColor = Color::Red;
					currNode = currNode->mParent->mParent;
				}
				// If uncle node is Black,
				else
				{
					// Case 2: Violating node is in opposite location of parent
					if (currNode == currNode->mParent->mRight)
					{
						// Fix: rotate around parent
						currNode = currNode->mParent;
						leftRotate(currNode);
					}

					// Fix: switch colors
					currNode->mParent->mColor = Color::Black;
					currNode->mParent->mParent->mColor = Color::Red;
					currNode->mParent->mRight->mColor = Color::Black;

					// Fix: rotate around grandparent
					rightRotate(currNode->mParent->mParent);
				}
			}
			// If the current node's parent is a RIGHT CHILD
			else
			{
				RBTree<T>::RBNode::Ptr uncleNode = currNode->mParent->mParent->mLeft;
				if (uncleNode->mColor == Color::Red)
				{
					currNode->mParent->mColor = Color::Black;
					uncleNode->mColor = Color::Black;
					currNode->mParent->mParent->mColor = Color::Red;
					currNode = currNode->mParent->mParent;
				}
				else
				{
					if (currNode == currNode->mParent->mLeft)
					{
						currNode = currNode->mParent;
						rightRotate(currNode);
					}

					currNode->mParent->mColor = Color::Black;
					currNode->mParent->mParent->mColor = Color::Red;
					currNode->mParent->mLeft->mColor = Color::Black;
					leftRotate(currNode->mParent->mParent);
				}
			}
		}
	}

	// Root must always be black
	this->mRoot->mColor = Color::Black;
}


template <typename T>
typename RBTree<T>::RBNode::Ptr RBTree<T>::search(const T& val) const
{
	typename RBTree<T>::RBNode::Ptr currNode = this->mRoot;

	while (currNode != this->mNilNode && val != currNode->mValue)
	{
		if (val < currNode->mValue)
		{
			currNode = currNode->mLeft;
		}
		else
		{
			currNode = currNode->mRight;
		}
	}
	return currNode;
}


template <typename T>
bool RBTree<T>::exists(const T& val) const
{
	return this->search(val) != this->mNilNode;
}


template <typename T>
typename RBTree<T>::RBNode::Ptr RBTree<T>::findSuccessor(typename RBTree<T>::RBNode::Ptr node)
{
	if (node->mRight != this->mNilNode)
	{
		while (node->mLeft != this->mNilNode)
		{
			node = node->mLeft;
		}
		return node;
	}

	RBTree<T>::RBNode::Ptr y = node->mParent;
	while (y != this->mNilNode && node == y->mRight)
	{
		node = y;
		y = y->mParent;
	}

	return y;
}


template <typename T>
void RBTree<T>::fixAfterDelete(typename RBTree<T>::RBNode::Ptr currNode)
{
	while (currNode != this->mRoot && currNode->mColor == false)
	{
		RBTree<T>::RBNode::Ptr replacementChild = nullptr;

		if (currNode->mParent->mLeft == currNode)
		{
			replacementChild = currNode->mParent->mRight;

			if (replacementChild->mColor == Color::Red)
			{
				replacementChild->mColor = Color::Black;
				currNode->mParent->mColor = Color::Red;

				this->leftRotate(currNode->mParent);
				replacementChild = currNode->mParent->mRight;
			}

			if (replacementChild->mLeft->mColor == Color::Black && replacementChild->mRight->mColor == Color::Black)
			{
				replacementChild->mColor = Color::Red;
				currNode = currNode->mParent;
			}
			else
			{
				if (replacementChild->mRight->mColor == Color::Black)
				{
					replacementChild->mLeft->mColor = Color::Black;
					replacementChild->mColor = Color::Red;

					this->rightRotate(replacementChild);
					replacementChild = currNode->mParent->mRight;
				}

				replacementChild->mColor = currNode->mParent->mColor;
				currNode->mParent->mColor = Color::Black;
				replacementChild->mRight->mColor = Color::Black;

				this->leftRotate(currNode->mParent);
				currNode = this->mRoot;
			}
		}
		else
		{
			replacementChild = currNode->mParent->mLeft;

			if (replacementChild->mColor == Color::Red)
			{
				replacementChild->mColor = Color::Black;
				currNode->mParent->mColor = Color::Red;
				this->rightRotate(currNode->mParent);
				replacementChild = currNode->mParent->mLeft;
			}

			if (replacementChild->mRight->mColor == Color::Black && replacementChild->mLeft->mColor == Color::Black)
			{
				replacementChild->mColor = Color::Red;
				currNode = currNode->mParent;
			}
			else
			{
				if (replacementChild->mLeft->mColor == Color::Black)
				{
					replacementChild->mRight->mColor = Color::Black;
					replacementChild->mColor = Color::Red;

					this->leftRotate(replacementChild);
					replacementChild = currNode->mParent->mLeft;
				}

				replacementChild->mColor = currNode->mParent->mColor;
				currNode->mParent->mColor = Color::Black;
				replacementChild->mLeft->mColor = Color::Black;

				this->rightRotate(currNode->mParent);
				currNode = this->mRoot;
			}
		}
	}
	currNode->mColor = Color::Black;
}


template <typename T>
void RBTree<T>::remove(typename RBTree<T>::RBNode::Ptr nodeToDelete)
{
	RBTree<T>::RBNode::Ptr replacementNode = this->mNilNode;
	RBTree<T>::RBNode::Ptr replacementNodeChild = this->mNilNode;
	
	if (nodeToDelete->mLeft == this->mNilNode || nodeToDelete->mRight == this->mNilNode)
	{
		replacementNode = nodeToDelete;
	}
	else
	{
		replacementNode = this->findSuccessor(nodeToDelete);
	}

	if (replacementNode->mLeft != this->mNilNode)
	{
		replacementNodeChild = replacementNode->mLeft;
	}
	else
	{
		replacementNodeChild = replacementNode->mRight;
	}

	replacementNodeChild->mParent = replacementNode->mParent;
	
	if (replacementNode->mParent == this->mNilNode)
	{
		this->mRoot = replacementNodeChild;
	}
	else
	{
		if (replacementNode == replacementNode->mParent->mLeft)
		{
			replacementNode->mParent->mLeft = replacementNodeChild;
		}
		else
		{
			replacementNode->mParent->mRight = replacementNodeChild;
		}
	}

	// Swap data from replacement node
	if (replacementNode != nodeToDelete)
	{
		nodeToDelete->mValue = replacementNode->mValue;
	}

	if (replacementNode->mColor == Color::Black)
	{
		this->fixAfterDelete(replacementNodeChild);
	}

	delete replacementNode;	
}


template <typename T>
bool RBTree<T>::remove(const T& val)
{
	RBTree<T>::RBNode::Ptr foundNode = this->search(val);
	if (foundNode != this->mNilNode)
	{
		this->remove(foundNode);
		--mSize;
		return true;
	}
	return false;
}


template <typename T>
const T RBTree<T>::getMax(typename RBNode::Ptr node) const
{
	if (node == this->mNilNode)
	{
		return std::numeric_limits<T>::min();
	}
	else
	{
		if (node->mRight == this->mNilNode)
		{
			return node->mValue;
		}
		else
		{
			return getMax(node->mRight);
		}
	}
};


template <typename T>
const T RBTree<T>::getMax() const
{
	return getMax(this->mRoot);
}


template <typename T>
const T RBTree<T>::getMin(typename RBNode::Ptr node) const
{
	if(node == this->mNilNode)
	{
		return std::numeric_limits<T>::max();
	}
		else
		{
			if (node->mLeft == this->mNilNode)
			{
				return node->mValue;
			}
			else
			{
				return getMin(node->mLeft);
			}
		}
};


template <typename T>
const T RBTree<T>::getMin() const
{
	return getMin(this->mRoot);
}


template <typename T>
bool RBTree<T>::isEmpty() const
{
    return this->mRoot == mNilNode;
}


template <typename T>
size_t RBTree<T>::size() const
{
    return mSize;
}


template <typename T>
int RBTree<T>::height() const
{
    static std::function<int (typename RBNode::Ptr)> heightHelper = [&](typename RBNode::Ptr node)
    {
        if (node == mNilNode)
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
void RBTree<T>::clear()
{
	static std::function<void(typename RBNode::Ptr&)> clearHelper = [&](typename RBNode::Ptr& node)
	{
		if (node == mNilNode)
		{
			return;
		}

		clearHelper(node->mLeft);
		clearHelper(node->mRight);
		delete node;
		node = nullptr;
		--mSize;		
	};

	clearHelper(this->mRoot);

	// Delete nil node
	delete mNilNode;
	mNilNode = nullptr;
}


template <typename T>
void RBTree<T>::getElementsPreOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
{
    if (node == mNilNode)
    {
        return;
    }
    
    elems.push_back(node->mValue);
    getElementsPreOrder(node->mLeft, elems);
    getElementsPreOrder(node->mRight, elems);
}


template <typename T>
void RBTree<T>::getElementsInOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
{
    if (node == mNilNode)
    {
        return;
    }
    
    getElementsInOrder(node->mLeft, elems);
    elems.push_back(node->mValue);
    getElementsInOrder(node->mRight, elems);
}


template <typename T>
void RBTree<T>::getElementsPostOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
{
    if (node == mNilNode)
    {
        return;
    }
    
    getElementsPostOrder(node->mLeft, elems);
    getElementsPostOrder(node->mRight, elems);
    elems.push_back(node->mValue);
}


template <typename T>
void RBTree<T>::getElementsLevelOrder(typename RBNode::Ptr node, std::vector<T>& elems) const
{
    std::function<void (typename RBNode::Ptr, int, std::vector<T>&)> getLevelElems = [&] (typename RBNode::Ptr node,
                                                                                          int level,
                                                                                          std::vector<T>& elems)
    {
        if (node == mNilNode)
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
std::vector<T> RBTree<T>::getElementList(const Traversal& traversal /* = InOrder */) const
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

