// Tests Two Element Set Solution
#include <iostream>
#include "solutions/two_element_sum.h"

/**
 * \brief Test the two element sum solution
 */
void kd::testTwoElementSum()
{
	std::cout << "==========================================================\n";
	std::cout << __FUNCTION__ << ": Commencing Test" << std::endl;
	std::cout << "==========================================================\n";

	std::vector<int> numbers{ 4, 5, 8, 1, 2, 3 };
	std::cout << "Can we get a sum of 6 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 6) << std::endl;
	std::cout << "Can we get a sum of 8 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 21) << std::endl;
	std::cout << "Can we get a sum of 2 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 2) << std::endl;

	std::cout << "**********************************************************\n";
	std::cout << __FUNCTION__ << ": Test Complete" << std::endl;
	std::cout << "**********************************************************\n\n";
}
