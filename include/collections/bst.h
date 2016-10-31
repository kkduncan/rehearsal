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
#ifndef KD_REHEARSAL_BST_H_
#define KD_REHEARSAL_BST_H_

#include <vector>

namespace kd
{
    /**
     * \brief Binary Search Tree
     */
    template <typename T>
    class BSTree
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
        std::vector<T> getElementList(const Traversal& traversal = InOrder) const;

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

} // namespace kd


// Include implementation
#include <collections/impl/bst.hpp>


#endif /* KD_REHEARSAL_BST_H_ */
