// Tests String Problems
#include <cstdlib>
#include <iostream>
#include "solutions/string_problems.h"


static inline void testUniqueString()
{
    const char* str1 = "taco cat";
    const char* str2 = "kester";
    const char* str3 = "andrew";

    printf("Is '%s' a unique string?\t--> %s\n", str1, (kd::isUnique(str1, strlen(str1)))? "YES" : "NO");
    printf("Is '%s' a unique string?\t--> %s\n", str2, (kd::isUnique(str2, strlen(str2)))? "YES" : "NO");
    printf("Is '%s' a unique string?\t--> %s\n", str3, (kd::isUnique(str3, strlen(str3)))? "YES" : "NO");
    printf("\n");
}


static inline void testPalindromePermutation()
{
    std::string palindromeTestStr1 = "taco cat";
    std::string palindromeTestStr2 = "atco cta";
    std::string palindromeTestStr3 = "atcatca";

    printf("Is '%s' a palindrome permutation?\t--> %s\n", palindromeTestStr1.c_str(), (kd::isPalindromePermutation(palindromeTestStr1))? "YES" : "NO");
    printf("Is '%s' a palindrome permutation?\t--> %s\n", palindromeTestStr2.c_str(), (kd::isPalindromePermutation(palindromeTestStr2))? "YES" : "NO");
    printf("Is '%s' a palindrome permutation?\t--> %s\n", palindromeTestStr3.c_str(), (kd::isPalindromePermutation(palindromeTestStr3))? "YES" : "NO");
    printf("\n");
}


static inline void testReplaceSpaces()
{
    const char* str1 = "Hello, how are you?      ";
    const char* str2 = "Superstar";
    const char* str3 = "            ";

    char* str1Copy = new char[strlen(str1)];
    strcpy(str1Copy, str1);

    char* str2Copy = new char[strlen(str2)];
    strcpy(str2Copy, str2);

    char* str3Copy = new char[strlen(str3)];
    strcpy(str3Copy, str3);

    kd::replaceSpaces(str1Copy, strlen(str1) - 6);
    printf("[ %s ] with spaces replaced --> %s\n", str1, str1Copy);

    kd::replaceSpaces(str2Copy, strlen(str2));
    printf("[ %s ] with spaces replaced --> %s\n", str2, str2Copy);

    kd::replaceSpaces(str3Copy, strlen(str3) - 8);
    printf("[ %s ] with spaces replaced --> %s\n", str3, str3Copy);

    delete[] str1Copy;
    delete[] str2Copy;
    delete[] str3Copy;

    printf("\n");
}


static inline void testFindSubstring()
{
    std::string str1 = "I went to the club with Sammy yesterday. Did you see her?";
    std::string str2 = "Sam";

    auto idx = kd::findSubstring(str1, str2);
    printf("Is the substring %s found in %s? --> %s\n", str2.c_str(), str1.c_str(), (idx != std::string::npos) ? "YES" : "NO");
}


/**
 * \brief Test the String problems
 */
void kd::testStringProblems()
{
	std::cout << "==========================================================\n";
	std::cout << __FUNCTION__ << ": Commencing Test" << std::endl;
	std::cout << "==========================================================\n";

	testPalindromePermutation();
	testUniqueString();
	testReplaceSpaces();
	testFindSubstring();

	std::cout << "**********************************************************\n";
	std::cout << __FUNCTION__ << ": Test Complete" << std::endl;
	std::cout << "**********************************************************\n\n";
}
