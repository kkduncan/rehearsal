/**
 * Red Black Tree Interface
 * \file rbtree.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_RBTREE_H_
#define KD_RBTREE_H_

#include <vector>

namespace kd
{
    /*
     * Red-Black Tree (balanced binary tree)
     *
     * Properties:
     *  1. Every node has a color, either red or black
     *  2. The root of the tree is always black.
     *  3. There are no two adjacent red nodes. Therefore, a red node can't have a red parent or red child.
     *  4. Every path from the root node to a leaf node (NULL node) has the same number of black nodes.
     *
     */
    template <typename T>
    class RBTree
    {
	public:
        /**
         * \brief Tree traversal methods
         */
        enum Traversal
        {
            PreOrder = 0,
            InOrder,
            PostOrder,
            LevelOrder
        };
        
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
            
            RBNode() : mValue(), mParent(nullptr), mLeft(nullptr), mRight(nullptr), mColor(Red) {}
			RBNode(T v) : mValue(v), mParent(nullptr), mLeft(nullptr), mRight(nullptr), mColor(Red)  {}
            
            const T& value() const { return mValue; }
            T& value() { return mValue; }
            
            const bool& color() const { return mColor; }
			Color& color() { return mColor; }

			RBNode* left() const { return mLeft; }
			RBNode* left() { return mLeft; }

			RBNode* right() const { return mRight; }
			RBNode* right() { return mRight; }
 
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
        
        /// Indicate whether an element exists in the tree
        virtual bool exists(const T& val) const;
        
        /// Get the maximum value
        virtual const T getMax() const;
        
        /// Get the minimum value
        virtual const T getMin() const;
        
        /// Check to see if the tree is empty
        virtual bool isEmpty() const;
        
        /// Get the number of elements in the tree
        virtual size_t size() const;
        
        /// Get the height of the tree
        virtual int height() const;
        
        // Clear the contents of the tree
        virtual void clear();
        
        /// Get a list of the elements in the tree according to the traversal method
        virtual std::vector<T> getElementList(const Traversal& traversal = InOrder) const;
        
    protected:
		/// Alias for Node color
		using Color = typename RBNode::Color;

		/// Search for a key and return its node if found
		virtual typename RBNode::Ptr search(const T& val) const;

		/// Left rotate
		virtual void leftRotate(typename RBNode::Ptr node);

		/// Right rotate
		virtual void rightRotate(typename RBNode::Ptr node);

		/// Balance the tree after insertion
		virtual void fixAfterInsert(typename RBNode::Ptr node);

		/// Balance the tree after deletion
		virtual void fixAfterDelete(typename RBNode::Ptr node);

		/// Find the successor for an deletion candidate
		virtual typename RBNode::Ptr findSuccessor(typename RBNode::Ptr node);

		/// Removes a node from the tree
		virtual void remove(typename RBNode::Ptr node);

        /// Get the maximum value
		virtual const T getMax(typename RBNode::Ptr node) const;
        
        /// Get the minimum value
		virtual const T getMin(typename RBNode::Ptr node) const;
        
        /// Get the elements of the tree via Pre-Order traversal
		virtual void getElementsPreOrder(typename RBNode::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via In-Order traversal
		virtual void getElementsInOrder(typename RBNode::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Post-Order traversal
		virtual void getElementsPostOrder(typename RBNode::Ptr node, std::vector<T>& elems) const;
        
        /// Get the elements of the tree via Level-Order traversal
		virtual void getElementsLevelOrder(typename RBNode::Ptr node, std::vector<T>& elems) const;
        
    protected:
		/// The nil node
		typename RBNode::Ptr mNilNode;

        /// The root of the tree
        typename RBNode::Ptr mRoot;		
        
        /// The number of elements in the tree
        size_t mSize;
    };
}


// Include implementation
#include "rbtree.hpp"


#endif /* KD_RBTREE_H_ */
