// Implementation of linked_list.h

#include <collections/linked_list.h>
#include <cstddef>
#include <iostream>

template <typename T>
kd::SinglyLinkedList<T>::SinglyLinkedList() : mHead(nullptr), mTail(nullptr), mSize(0)
{

}

template <typename T>
kd::SinglyLinkedList<T>::~SinglyLinkedList()
{
	this->clear();	
}

template <typename T>
void kd::SinglyLinkedList<T>::addToFront(const T& val)
{
	NodePtr newNode (new Node(val));

	if (mHead == nullptr)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		newNode->next = mHead;
		mHead = newNode;
	}
	++mSize;
}

template <typename T>
void kd::SinglyLinkedList<T>::addToBack(const T& val)
{
	NodePtr newNode(new Node(val));

	if (mTail == nullptr)
	{
		mTail = newNode;
		mHead = newNode;
	}
	else
	{
		mTail->next = newNode;
		mTail = mTail->next;
	}
	++mSize;
}

template <typename T>
bool kd::SinglyLinkedList<T>::remove(const T& val)
{
	NodePtr prev(mHead);
	NodePtr curr(mHead);	
	bool found = false;

	while (curr != nullptr && !found)
	{
		if (curr->value == val)
		{
			if (curr == mHead)
			{
				mHead = curr->next;
				
				if (curr == mTail)
				{
					mTail = curr->next;
				}
				delete curr;
			}
			else if (curr == mTail)
			{
				mTail = prev;
				mTail->next = nullptr;
				delete curr;
			}			
			else
			{
				prev->next = curr->next;
				delete curr;				
			}
			
			--mSize;
			found = true;
		}
		
		prev = curr;
		curr = curr->next;		
	}

	return found;
}

template <typename T>
bool kd::SinglyLinkedList<T>::empty() const
{
	return mHead == nullptr;
}

template <typename T>
void kd::SinglyLinkedList<T>::print() const
{
	NodePtr curr (mHead);	

	std::cout << std::endl << __FUNCTION__ << ": List contents(" << mSize << ")" << std::endl;
	
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
	while (mHead != nullptr)
	{
		NodePtr nodeToDelete(mHead);
		mHead = mHead->next;
		delete nodeToDelete;
	}

	mTail = nullptr;
	mSize = 0;
}

template <typename T>
size_t kd::SinglyLinkedList<T>::size() const
{
	return mSize;
}

template <typename T>
const typename kd::SinglyLinkedList<T>::Node& kd::SinglyLinkedList<T>::head()
{
	if (mHead != nullptr)
	{
		return *mHead;
	}
	else
	{
		return std::move(Node());
	}
}

template <typename T>
const typename kd::SinglyLinkedList<T>::Node& kd::SinglyLinkedList<T>::end()
{
	if (mTail != nullptr)
	{
		return *mTail;
	}
	else
	{
		return std::move(Node());
	}
}


