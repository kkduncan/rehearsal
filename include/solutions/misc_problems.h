/**
 * A Collection of Solutions to some miscellaneous computer science problems
 *
 * \file misc_problems.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_MISC_PROBLEMS_H_
#define KD_MISC_PROBLEMS_H_

#include <cstdlib>
#include <ctime>
#include <vector>
#include <functional>

namespace kd
{

    /**
     * Create and initialize array of N elements with unifrom distribution. The
     * numbers are random with no repetition
     *
     * @param[in] n The length of the array (vector) to generate
     * @return The vector with randomly arranged elements
     */
    std::vector<int> getRandomArray(int n)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        std::vector<int> numberArr;
        numberArr.reserve(n);

        static std::function<void(std::vector<int>&, int, int)> swapElems = [] (std::vector<int>& vec, int left, int right)
        {
            int temp = vec[left];
            vec[left] = vec[right];
            vec[right] = temp;
        };

        for (auto count = 0; count < n; ++count)
        {
            numberArr.push_back(count + 1);
        }

        for (auto count = 0; count < n; ++count)
        {
            int indexToSwap = rand() % n;
            swapElems(numberArr, count, indexToSwap);
        }

        return std::move(numberArr);
    }

} // namespace kd
