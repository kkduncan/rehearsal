/**
 * Two Element Sum
 * \file two_element_sum.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_TWO_INTEGER_SUM_H
#define KD_TWO_INTEGER_SUM_H

#include <vector>
#include <set>

namespace kd
{
	/**
	 * \brief Determines if the specified integer can be calculated from the sum of two distinct numbers in a vector
	 *
	 * This function implements a solution for the following problem:
	 *
	 * Given an array of integers, determine whether or not there exists two elements
	 * in the array (at different positions) whose sum is equal to some target value.
	 * Examples:
	 * 		[5, 4, 2, 4], 8 --> true
	 * 		[5, 1, 2, 4], 8 --> false
	 */
	inline static bool canGetIntegerFromArray(const std::vector<int>& numbers, const int queryNum)
	{
		bool success = false;

		if (!numbers.empty())
		{
			std::multiset<int> numberSet{ numbers.begin(), numbers.end() };
			for (auto num : numberSet)
			{
				if (num > queryNum) continue;

				int numDiff = queryNum - num;

				if (numDiff == num) continue;

				// Look for difference in set
				auto foundNum = numberSet.count(numDiff);

				if (foundNum > 0)
				{
					success = true;
					break;
				}
			}
		}
		return success;
	}

	/**
	 * \brief Function to test the above method
	 */
	void testTwoElementSum();

} // namespace kd

#endif /* KD_TWO_INTEGER_SUM_H */
