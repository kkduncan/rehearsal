
#include <iostream>
#include <cstdlib>
#include "collections/linked_list.h"
#include "collections/tree.h"

int main(int argc, char *argv[])
{
	std::cout << "[  Commencing Linked List Eval  ]" << std::endl;
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
    
    std::cout << "---- DONE WITH LINKED LIST ----" << std::endl << std::endl;
    
    std::cout << "[  Commencing Tree Eval  ]" << std::endl;
    kd::BSTree<int> tree;
    
    tree.insert(2);
    tree.insert(1);
    tree.insert(3);
    
    
    std::cout << "Size of tree before adding a duplicate: " << tree.size() << std::endl;
    tree.insert(2);
    std::cout << "Size of tree after  adding a duplicate: " << tree.size() << std::endl;
    
    auto elemList = tree.getElementList(kd::TreeTraversal::LevelOrder);
    
    std::cout << "Tree Height: " << tree.height() << std::endl;
    
    std::cout << "Tree contents:" << std::endl;
    for (auto e : elemList)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    
    

	std::cout << std::endl << std::endl << "> Done...press enter to exit" << std::endl;
	std::cin.get();
	return 0;
}
