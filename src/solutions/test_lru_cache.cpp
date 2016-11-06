// Tests LRU Cache
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "solutions/lru_cache.h"

/**
 * \brief Test the Least Recently Used Cache
 */
void kd::testLRUCache()
{
	std::cout << "==========================================================\n";
	std::cout << __FUNCTION__ << ": Commencing Test" << std::endl;
	std::cout << "==========================================================\n";

	srand(static_cast<unsigned int>(time(nullptr)));

	kd::LRUCache<int, int> cache(10);
	int numRange = 99;

	for (int idx = 0; idx < numRange; ++idx)
	{
	    int key = rand() % numRange + 1;
	    int val = rand() % 999 + 1;

	    cache[key] = val;
	   	printf("#%02d: Cache size after inserting: (%02d, %03d) --> %02d\n", idx + 1, key, val, static_cast<int>(cache.size()));
	}

	auto elemVector = cache.toVector();

	std::cout << "Cache after use: " << std::endl;
	int counter = 0;
	for (auto elem : elemVector)
	{
	    ++counter;
	    printf("\t(%02d): (%02d, %03d)\n", counter, elem.first, elem.second);
	}

	std::cout << "**********************************************************\n";
	std::cout << __FUNCTION__ << ": Test Complete" << std::endl;
	std::cout << "**********************************************************\n\n";
}
