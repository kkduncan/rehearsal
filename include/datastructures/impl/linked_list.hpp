// Implementation of linked_list.h

#include <datastructures/linked_list.h>
#include <cstddef>
#include <iostream>

template <typename T>
kd::SinglyLinkedList<T>::SinglyLinkedList() : mHead(), mSize(0)
{
	std::cout << __FUNCTION__ << ": Constructed\n";
}

template <typename T>
kd::SinglyLinkedList<T>::~SinglyLinkedList()
{
	this->clear();
}

template <typename T>
void kd::SinglyLinkedList<T>::addToFront(const T& val)
{
	NodePtr newNode ( new Node(val, nullptr) );

	if (mHead == nullptr)
	{
		mHead = std::move(newNode);
	}
	else
	{
		newNode->next = std::move(mHead);
		mHead = std::move(newNode);
	}
}

template <typename T>
void kd::SinglyLinkedList<T>::print() const
{
	NodePtr curr = mHead;

	std::cout << __FUNCTION__ << ": List contents" << std::endl;
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next;
	}

	std::cout << "\n-- End --" <<  std::endl;
}


template <typename T>
void kd::SinglyLinkedList<T>::clear()
{
	NodePtr curr = mHead;
	NodePtr nullShared;
	while (curr != nullptr)
	{
		NodePtr next = curr->next;
		curr.reset();

		curr = next;
	}
	std::cout << __FUNCTION__ << ": Destroyed\n";
}

