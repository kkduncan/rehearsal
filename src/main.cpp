#include <iostream>
#include <cstdlib>
#include "collections/linked_list.h"

int main(int argc, char *argv[])
{
	std::cout << "In full effect" << std::endl;
	std::cout << "Ready..." << std::endl;

	kd::SinglyLinkedList<int> list;

	list.addToFront(1);
	list.addToFront(2);
	list.addToFront(3);
	list.addToFront(4);
	list.addToFront(5);

	list.print();

	list.remove(3);

	list.print();
	
	list.clear();
	list.print();

	std::cout << "Done...press enter to exit" << std::endl;
	std::cin.get();
	return 0;
}
