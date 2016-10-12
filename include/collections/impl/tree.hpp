// Implementation of tree.h

#include <collections/tree.h>
#include <functional>

template <typename T>
kd::BSTree<T>::BSTree() : mRoot(nullptr), mSize(0)
{
    
}

template <typename T>
kd::BSTree<T>::~BSTree()
{
	
}

template <typename T>
void kd::BSTree<T>::insert(const T& val)
{
    // Lambda to assist with insertions
    static std::function <bool (typename Node::Ptr&, const typename Node::Ptr)> insertHelper = [&] (typename Node::Ptr& currNode,
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
            auto leftHeight = heightHelper(node->mLeft);
            auto rightHeight = heightHelper(node->mRight);
            
            if (leftHeight > rightHeight)
            {
                return leftHeight + 1;
            }
            else
            {
                return rightHeight + 1;
            }
        }
    };
    
    auto h = heightHelper(this->mRoot);
    return h >= 0 ? h : 0;
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
std::vector<T> kd::BSTree<T>::getElementList(const TreeTraversal& traversal /* = InOrder */) const
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



