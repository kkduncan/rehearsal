/**
 * Set Interface
 * \file kdset.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_SET_H_
#define KD_SET_H_

#include <ctime>
#include <cstdlib>
#include "rbtree.h"

namespace kd
{
    /*
     * Class that represents a Set-like datastructure
     */
    template <typename T>
	class Set : public RBTree < T >
	{
	public:
		/// Constructor
		Set() : RBTree<T>::RBTree()
		{
			srand(static_cast<unsigned int>(time(nullptr)));
		}

		/// Gets a random key from the set with equal probability
		T getRandom()
		{
			int randomIdx = static_cast<int>(rand() % this->mSize);

			auto currIdx = 0;
			T currValue = static_cast<T>(0);

			/*
			 * Gets the key associated with the node at the random index if 
			 * traversing the tree in order
			 */
			static std::function<void (RBTree<T>::RBNode*)> traverseInOrder = [&](RBTree<T>::RBNode* node)
			{
				if (node == mNilNode)
				{
					return;
				}

				if (currIdx >= randomIdx)
				{
					currValue = node->value();
					return;
				}
				
				traverseInOrder(node->left());
				++currIdx;
				traverseInOrder(node->right());
			};
						
			traverseInOrder(this->mRoot);

			return currValue;
		}
	};        

} // namespace kd

#endif /* KD_SET_H_ */
