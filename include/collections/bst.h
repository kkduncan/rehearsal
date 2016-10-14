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
    
    /**
     * \brief Binary Search Tree
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
        virtual void insert(const T& val);

		/// Delete an element from the tree (if it exists)
		virtual bool remove(const T& val);
        
        /// Search for an element
        bool find(const T& val) const;

		/// Get the maximum value
		const T getMax() const;

		/// Get the minimum value
		const T getMin() const;

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
        
    protected:
		/// Get the maximum value
		const T getMax(typename Node::Ptr node) const;

		/// Get the minimum value
		const T getMin(typename Node::Ptr node) const;

        /// Get the elements of the tree via Pre-Order traversal
        void getElementsPreOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via In-Order traversal
        void getElementsInOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Post-Order traversal
        void getElementsPostOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Level-Order traversal
        void getElementsLevelOrder(typename Node::Ptr node, std::vector<T>& elems) const;
        
        
    protected:
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
     * The height of a red black tree is always O(logN), therefore all the operations are O(logN)
     *
     */
    template <typename T>
    class RBTree
    {
	public:
		/// Red-Black Tree Node
		class RBNode
		{
			friend class RBTree;
            
        public:
            /// Node color
            enum Color
            {
                Red,
                Black
            };
            
            RBNode() : mValue(), mLeft(nullptr), mRight(nullptr), mParent(nullptr), mColor(Red) {}
			RBNode(T v) : mValue(v), mLeft(nullptr), mRight(nullptr), mParent(nullptr), mColor(Red)  {}
            
            const T& value() const { return mValue; }
            T& value() { return mValue; }
            
            const bool& color() const { return mColor; }
			Color& color() { return mColor; }
            
            
        public:
            

		protected:
            /// Alias for a pointer to a BST node
			using Ptr = RBNode*;
            
            /// Stored data at node
            T mValue;
            
            /// Parent node
            Ptr mParent;
            
            /// Left child
            Ptr mLeft;
            
            /// Right child
            Ptr mRight;

			/// Node color
			Color mColor;
		};

	public:
		/// Constructor
		RBTree();

		/// Destructor
		virtual ~RBTree();

		/// Insert an element in the tree (with automatic balancing)
		virtual void insert(const T& val);

		/// Delete an element from the tree with (with automatic balancing)
		virtual bool remove(const T& val);
    };
}


// Include implementation
#include <collections/impl/tree.hpp>


#endif /* KD_TRIAL_TREE_H_ */
