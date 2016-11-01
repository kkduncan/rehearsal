/**
 * Random Element set
 * \file random_element_set.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_RANDOM_ELEMENT_SET_H_
#define KD_RANDOM_ELEMENT_SET_H_

#include <set>
#include <vector>
#include <ctime>

namespace kd
{
	/**
	 * \brief This class adds functionality to the standard set in order to retrieve a random element
	 *
	 * This class implements a solution for the following problem:
	 *
	 * Implement a set-like data structure that supports Insert, Remove, and
	 * GetRandomElement efficiently.
	 *
	 * Example: If you insert the elements 1, 3, 6, 8 and remove 6, the
	 * structure should contain [1, 3, 8]. Now, GetRandomElement should return
	 * one of 1, 3 or 8 with equal probability.
	 */
	template <typename T>
	class RSet : public std::set<T>
	{
	public:
		/**
		 * \brief Augmented default constructor
		 */
		RSet() : std::set<T>::set()
		{
			srand(static_cast<int>(time(nullptr)));
		}

		/**
		 * \brief Insert an element in the set
		 * \param[in] elem Element to be inserted
		 */
		inline void insert(const T& elem)
		{
			std::set<T>::insert(elem);
		}

		/**
		 * \brief Remove an element from the set
		 * \param[in] elem Element to be removed
		 * \return true if the element was removed, false otherwise
		 */
		inline bool remove(const T& elem)
		{
			return std::set<T>::erase(elem) > 0;
		}

		/**
		 * \brief Retrieves a random element from the set
		 * \return A random element if the set has elements
		 * \note Worst case run time: O(n)
		 */
		inline T getRandomElement()
		{
			T elem;

			if (!this->empty())
			{
				auto numElems = this->size();
				auto randomIdx = rand() % numElems;
				auto it = this->begin();

				std::advance(it, randomIdx);
				elem = *it;
			}

			return elem;
		}

		/**
		 * \brief Get the elements of this set as a vector
		 * \return A vector of type T
		 */
		inline std::vector<T> toVector() const
		{
			return std::move(std::vector<T>(this->begin(), this->end()));
		}
	};

	/**
	 * \brief Function to test the class above
	 */
	void testRandomElementSet();

} // namespace kd

#endif /* KD_RANDOM_ELEMENT_SET_H_ */
