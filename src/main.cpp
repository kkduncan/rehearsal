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

	kd::SinglyLinkedList<int>::Node head = list.head();	
	std::cout << "Head value (1): " << head.value() << std::endl;
	head.value() = 3;
	std::cout << "Head value (2): " << head.value() << std::endl;

	list.remove(1);
	list.print();

	kd::SinglyLinkedList<int>::Node tail = list.tail();
	std::cout << "Tail value (1): " << tail.value() << std::endl;
	tail.value() = 3;
	std::cout << "Tail value (2): " << tail.value() << std::endl;
	
	list.remove(5);
	list.print();

	list.remove(4);
	list.print();
 
 	list.remove(0);

	list.print();
	list.clear();
	list.print();

	std::cout << std::endl << std::endl << "> Done...press enter to exit" << std::endl;
	std::cin.get();
	return 0;
}
