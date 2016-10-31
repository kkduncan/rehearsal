// Tests Random Element Set Solution
#include <iostream>
#include "solutions/random_element_set.h"

/**
 * \brief Test the random element set solution
 */
void kd::testRandomElementSet()
{
	std::cout << "==========================================================\n";
	std::cout << __FUNCTION__ << ": Commencing Test" << std::endl;
	std::cout << "==========================================================\n";

	kd::RSet<int> randomElemSet;

	// Insert elements
	randomElemSet.insert(72);
	randomElemSet.insert(29);
	randomElemSet.insert(33);
	randomElemSet.insert(1);
	randomElemSet.insert(6);
	randomElemSet.insert(8);
	randomElemSet.insert(10);
	randomElemSet.insert(3);

	std::cout << "Set elements after insertion -->" << std::endl;
	for (auto elem : randomElemSet.toVector())
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// Remove an element
	randomElemSet.remove(6);
	std::cout << "Set elements after removal -->" << std::endl;
	for (auto elem : randomElemSet.toVector())
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	// Get a random element
	std::cout << "Random set element(1): " << randomElemSet.getRandomElement() << std::endl;
	std::cout << "Random set element(2): " << randomElemSet.getRandomElement() << std::endl;
	std::cout << "Random set element(3): " << randomElemSet.getRandomElement() << std::endl;

	std::cout << "**********************************************************\n";
	std::cout << __FUNCTION__ << ": Test Complete" << std::endl;
	std::cout << "**********************************************************\n\n";
}





