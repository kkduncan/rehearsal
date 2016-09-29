#include <iostream>
#include <cstdlib>
#include "datastructures/linked_list.h"

int main(int argc, char *argv[])
{
	std::cout << "In full effect" << std::endl;
	std::cout << "Ready..." << std::endl;

	kd::SinglyLinkedList<float> list;

	list.addToFront(1);
	list.addToFront(2);
	list.addToFront(3);
	list.addToFront(4);
	list.addToFront(5);

	list.print();
	list.clear();
	list.print();

	return 0;
}
