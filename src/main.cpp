#include <iostream>
#include <cstdlib>
#include "collections/linked_list.h"

int main(int argc, char *argv[])
{
	std::cout << "[    Commencing    ]" << std::endl;
	kd::SinglyLinkedList<int> list;

	list.pushToFront(1);
	list.pushToFront(2);
	list.pushToFront(3);
	list.pushToFront(4);
 	list.pushToFront(5);
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
