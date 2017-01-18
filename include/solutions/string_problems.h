/**
 * A Collection of Solutions to some String Problems
 *
 * \file string_problems.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_STRING_PROBLEMS_H_
#define KD_STRING_PROBLEMS_H_

#include <set>
#include <string>
#include <sstream>

namespace kd
{

    /**
     * \brief Determines if a string is a permutation of a palindrome
     * \param str The string to investigate
     *
     * This function implements a solution to the following problem:
     *
     * Given a string, write a functoin to check if it is a permutation of a
     * palindrome. A palindrom is a word or phrase that is the same forwards
     * and backwards. A permutation is a rearrangement of letters. The
     * palindrome does not need to be limited to just dictionary words.
     *
     * Example:
     * Input:   Tact Coa
     * Output:  true (permutations: "taco cat", "atco cta")
     */
    bool isPalindromePermutation(const std::string& str)
    {
        bool isPalindromePerm = true;
        auto size = str.size();
        std::multiset<char> charSet;
        auto charLen = 0;

        for (auto i = 0; i < size; ++i)
        {
            if (str[i] != ' ')
            {
                charSet.insert(std::tolower(str[i]));
                ++charLen;
            }
        }

        bool isEven = (charLen % 2) == 0;

        if (isEven)
        {
            for (auto it = charSet.begin(); it != charSet.end(); ++it)
            {
                if (charSet.count(*it) % 2 != 0)
                {
                    isPalindromePerm = false;
                    break;
                }
            }
        }
        else
        {
            int oddCount = 0;
            for (auto it = charSet.begin(); it != charSet.end(); ++it)
            {
                if (charSet.count(*it) % 2 != 0)
                {
                    ++oddCount;
                    if (oddCount > 1)
                    {
                        isPalindromePerm = false;
                        break;
                    }
                }
            }
        }
        return isPalindromePerm;
    }


    /**
     * \brief Determines if two strings are one edit away from another
     *
     * This function implements a solution to the following problem:
     *
     * There are three types of edits that can be performed on strings: insert
     * a character, remove a character, or replace a character. Given two
     * strings, write a function to check if they are one edit (or zero edits)
     * away.
     *
     * @param left The first string
     * @param right The second string
     * @return true if the strings are one or zero edits away
     */
    bool isOneEditAway (const std::string& left, const std::string& right)
    {
        if (left.size() == 0 || right.size() == 0) return false;
        if (std::abs(static_cast<long>(left.size() - right.size())) > 1) return false;

        bool oneAway = false;

        if (left.size() != right.size())
        {
            auto simCharCnt = 0;
            auto len = std::max(left.size(), right.size());
            auto leftIdx = 0;
            auto rightIdx = 0;

            for (auto i = 0; i < len; ++i)
            {
                if (rightIdx < right.size() && leftIdx < left.size())
                {
                    if (left[leftIdx] == right[rightIdx])
                    {
                        ++simCharCnt;
                        ++leftIdx;
                        ++rightIdx;
                    }
                    else
                    {
                        if (len == left.size()) ++leftIdx;
                        else ++rightIdx;
                    }
                }
            }

            if (simCharCnt == left.size() || simCharCnt == right.size())
            {
                oneAway = true;
            }
        }
        else
        {
            int simCharCnt = 0;
            for (auto i = 0; i < left.size(); ++i)
            {
                if (left[i] == right[i]) ++simCharCnt;
            }

            if (simCharCnt == (left.size() - 1) || simCharCnt == left.size())
            {
                oneAway = true;
            }

        }

        return oneAway;
    }


    /**
     * \brief Compress a string by counts of repeated characters
     *
     * This function implements a solution to the following problem:
     *
     * Implement a method to perform basic string compression using the counts
     * of repeated characters. For example, the string aabcccccaaa would become
     * a2b1c5a3. If the compressed string would not become smaller than the
     * original string, your method should return the original string. You can
     * assume the string has only uppercase and lowercase letters (a - z)
     */
    std::string compressString (const std::string& str)
    {
        if (str.empty()) return str;

        char prevChar = str[0];
        char currChar = str[0];
        int currCharCnt = 1;
        std::stringstream compStr;

        compStr << prevChar;

        for (auto i = 1; i < str.size(); ++i)
        {
            currChar = str[i];
            if (currChar == prevChar)
            {
                ++currCharCnt;
            }
            else
            {
                compStr << currCharCnt << currChar;
                prevChar = currChar;
                currCharCnt = 1;
            }
        }

        compStr << currCharCnt;

        auto newStr = compStr.str();

        if (newStr.size() < str.size())
        {
            return newStr;
        }
        else
        {
            return str;
        }
    }

    /**
     * \biref Rotates a square matrix (4x4 in this case) in a clockwise direction
     *
     */
    void rotateMatrix (const int src[][4], int dst[][4], int n)
    {
        if (src == nullptr || dst == nullptr) return;

        for (auto i = 0; i < n; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                const int &a = src[i][j];
                int &b = dst[j][(n - 1) - i];
                b = a;
            }
        }
    }


    void rotateMatrixInPlace (int src[][4], int n)
    {
        if (src == nullptr) return;

        int halfN = n / 2;

        for (auto i = 0; i < halfN; ++i)
        {
            for (auto j = 0; j < halfN; ++j)
            {
                int temp                        = src[i][j];
                src[i][j]                       = src[(n - 1) - j][i];
                src[(n - 1) - j][i]             = src[(n - 1) - i][(n - 1) - j];
                src[(n - 1) - i][(n - 1) - j]   = src[j][(n - 1) - i];
                src[j][(n - 1) - i]             = temp;
            }
        }
    }

    /**
     * \brief Zero Matrix: Write an algorithm such that if an element in an MxM matrix
     *        is 0, its entire row and column are set to 0.
     */
    // TODO: Implement Zero Matrix algorithm

    /**
     * \brief Determine if a string has all unique characters
     * \param[in] str The C-string to check uniqueness
     * \param[in] len The length of the C-string provided
     * \return true if the string is unique
     */
    bool isUnique(const char* str, int len)
    {
        std::set<char> charSet;
        bool unique = true;

        for (auto idx = 0; idx < len; ++idx)
        {
            auto ch = str[idx];
            if (charSet.count(ch) == 0)
            {
                charSet.insert(str[idx]);
            }
            else
            {
                unique = false;
                break;
            }
        }
        return unique;
    }

} // namespace kd



#endif /* KD_STRING_PROBLEMS_H_ */
