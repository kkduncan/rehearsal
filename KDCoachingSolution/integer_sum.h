/**
 * Integer Sum
 * \file integer_sum.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_INTSUM_H_
#define KD_INTSUM_H_

#include <vector>
#include <set>

namespace kd
{
	static bool canGetIntegerFromArray(const std::vector<int>& numbers, const int queryNum)
	{
		std::multiset<int> numberSet{ numbers.begin(), numbers.end() };
		bool success = false;

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

		return success;
	}

} // namespace kd

#endif /* KD_INTSUM_H_ */
