/**
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * trial is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with trial.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \file tree.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_TRIAL_TREE_H_
#define KD_TRIAL_TREE_H_

#include <vector>

namespace kd
{
    /**
     * \brief Tree traversal methods
     */
    enum TreeTraversal
    {
        PreOrder = 0,
        InOrder,
        PostOrder,
        LevelOrder
    };
    
    /*
     * Binary Search Tree
     */
    template <typename T>
    class BSTree
    {
    public:
        /// Tree Node
        class Node
        {
            friend class BSTree;
            
        public:
            Node() : mValue(), mLeft(nullptr), mRight(nullptr) {}
            Node(T v) : mValue(v), mLeft(nullptr), mRight(nullptr) {}
            const T& value() const { return mValue; }
            T& value() { return mValue; }
            
        protected:
            /// Alias for a pointer to a BST node
            using Ptr = Node*;
            T mValue;
            Ptr mLeft;
            Ptr mRight;
        };
        
    public:
        /// Constructor
        BSTree();
        
        /// Destructor
        virtual ~BSTree();
        
        /// Insert an element in the tree
        void insert(const T& val);
        
        /// Search for an element
        bool search(const T& val) const;
        
        /// Remove an element from the tree (if it exists)
        bool remove(const T& val);
        
        /// Check to see if the tree is empty
        bool isEmpty() const;
        
        /// Get the number of elements in the tree
        size_t size() const;
        
        /// Get the height of the tree
        int height() const;
        
        // Clear the contents of the tree
        void clear();
        
        /// Get a list of the elements in the tree according to the traversal method
        std::vector<T> getElementList(const TreeTraversal& traversal = InOrder) const;
        
    private:
        /// Get the elements of the tree via Pre-Order traversal
        void getElementsPreOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via In-Order traversal
        void getElementsInOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Post-Order traversal
        void getElementsPostOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Level-Order traversal
        void getElementsLevelOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        
    private:
        /// The root of the tree
        typename Node::Ptr mRoot;
        
        /// The number of elements in the tree
        size_t mSize;
        
    };
    
    
    /*
     * Red-Black Tree (balanced binary tree)
     *
     * Properties:
     *  1. Every node has a color, either red or black
     *  2. The root of the tree is always black.
     *  3. There are no two adjacent red nodes. Therefore, a red node can't have a red parent or red child.
     *  4. Every path from the root node to a leaf node (NULL node) has the same number of black nodes.
     *
     * The height of a red black tree is always O(logN)
     * Red-Black Tree Operations:
     *  o insert
     *  o search
     *  o remove / delete
     *  o max / min
     *  o getList
     *
     * Site List:
     *  o https://www.topcoder.com/community/data-science/data-science-tutorials/an-introduction-to-binary-search-and-red-black-trees/
     *  o http://code.geeksforgeeks.org/NtLnIk
     *  o http://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/
     *  o https://gist.github.com/mgechev/5911348
     *  o 
     */
    template <typename T>
    class RBTree
    {
        // TODO: Implement
    };
}


// Include implementation
#include <collections/impl/tree.hpp>


#endif /* KD_TRIAL_TREE_H_ */
