// Driver
#include <iostream>
#include "kdset.h"
#include "integer_sum.h"

void testRBT()
{
	kd::RBTree<int> rbTree;

	rbTree.insert(1);
	rbTree.insert(2);
	rbTree.insert(3);
	rbTree.insert(4);
	rbTree.insert(5);
	rbTree.insert(6);
	rbTree.insert(2);

	auto rbtElemList = rbTree.getElementList(kd::RBTree<int>::Traversal::InOrder);

	std::cout << "Tree contents:" << std::endl;
	for (auto elem : rbtElemList)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}


void testSet()
{
	kd::Set<int> kdSet;
	kdSet.insert(1);
	kdSet.insert(2);
	kdSet.insert(3);
	kdSet.insert(4);
	kdSet.insert(5);
	kdSet.insert(6);
	
	auto setElemList = kdSet.getElementList(kd::Set<int>::Traversal::InOrder);

	std::cout << "Tree contents:" << std::endl;
	for (auto elem : setElemList)
	{
		std::cout << elem << " ";
	}
	
	std::cout << std::endl << "Random tree element: " << kdSet.getRandom() << std::endl;

	std::cout << std::endl;
}


void testIntegerSum()
{
	std::vector<int> numbers{ 4, 5, 8, 1, 2, 3 };
	std::cout << "Can we get a sum of 6 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 6) << std::endl;
	std::cout << "Can we get a sum of 8 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 21) << std::endl;
	std::cout << "Can we get a sum of 2 from the array?: " << std::boolalpha << kd::canGetIntegerFromArray(numbers, 2) << std::endl;
	std::cout << std::endl;
}


int main(int argc, char *argv[])
{
	testSet();
	testIntegerSum();

	std::cout << std::endl << std::endl << "> Done...press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}
