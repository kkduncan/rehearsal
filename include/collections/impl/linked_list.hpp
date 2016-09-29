// Implementation of linked_list.h

#include <collections/linked_list.h>
#include <cstddef>
#include <iostream>

template <typename T>
kd::SinglyLinkedList<T>::SinglyLinkedList() : mHead(), mSize(0)
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
		mHead = std::move(newNode);
	}
	else
	{
		newNode->next = std::move(mHead);
		mHead = std::move(newNode);
	}
	++mSize;
}

template <typename T>
void kd::SinglyLinkedList<T>::addToBack(const T& val)
{
	// TODO: Finish adding to end of list
// 	NodePtr newNode(new Node(val));
// 
// 	if (mHead == nullptr)
// 	{
// 		mHead = std::move(newNode);
// 	}
// 	else
// 	{
// 		newNode->next = std::move(mHead);
// 		mHead = std::move(newNode);
// 	}
// 	++mSize;
}

template <typename T>
bool kd::SinglyLinkedList<T>::remove(const T& val)
{
	RawNodePtr prev(mHead.get());
	RawNodePtr curr(mHead.get());	
	bool found = false;

	while (curr != nullptr && !found)
	{
		if (curr->value == val)
		{
			if (prev == mHead.get())
			{
				mHead = std::move(mHead->next);
				curr = nullptr;
			}
			else
			{
				prev->next = std::move(curr->next);		
				curr = nullptr;
			}
			--mSize;
			found = true;
		}
		else
		{
			prev = curr;
			curr = curr->next.get();
		}
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
	RawNodePtr curr (mHead.get());	

	std::cout << std::endl << __FUNCTION__ << ": List contents(" << mSize << ")" << std::endl;
	
	while (curr != nullptr)
	{
		std::cout << curr->value << " ";
		curr = curr->next.get();
	}

	std::cout << "\n-- End --" <<  std::endl;
}


template <typename T>
void kd::SinglyLinkedList<T>::clear()
{
	mHead.reset();	
	mTail.reset();
	mSize = 0;
}

template <typename T>
size_t kd::SinglyLinkedList<T>::size() const
{
	return mSize;
}

template <typename T>
const typename kd::SinglyLinkedList<T>::NodePtr& kd::SinglyLinkedList<T>::head()
{
	return mHead;
}

template <typename T>
const typename kd::SinglyLinkedList<T>::NodePtr& kd::SinglyLinkedList<T>::end()
{
	return mTail;
}


