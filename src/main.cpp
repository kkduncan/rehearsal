#include <iostream>
#include <cstdlib>
#include "collections/linked_list.h"

int main(int argc, char *argv[])
{
	std::cout << "[    Commencing    ]" << std::endl;
	kd::SinglyLinkedList<int> list;

	list.addToFront(1);
	list.addToFront(2);
	list.addToFront(3);
	list.addToFront(4);
	list.addToFront(5);
	list.print();

	list.remove(1);
	list.print();
	
	list.remove(5);
	list.print();

	list.remove(4);
	list.print();
 
 	list.remove(0);

	list.print();
	list.clear();
	list.print();

	std::cout << "Done...press enter to exit" << std::endl;
	std::cin.get();
	return 0;
}
