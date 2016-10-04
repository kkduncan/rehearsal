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
	Node::Ptr newNode (new Node(val));

	if (mHead == nullptr)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		newNode->mNext = mHead;
		mHead = newNode;
	}
	++mSize;
}

template <typename T>
void kd::SinglyLinkedList<T>::addToBack(const T& val)
{
	Node::Ptr newNode(new Node(val));

	if (mTail == nullptr)
	{
		mTail = newNode;
		mHead = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = mTail->mNext;
	}
	++mSize;
}

template <typename T>
bool kd::SinglyLinkedList<T>::remove(const T& val)
{
	Node::Ptr prev(mHead);
	Node::Ptr curr(mHead);	
	bool found = false;

	while (curr != nullptr && !found)
	{
		if (curr->mValue == val)
		{
			if (curr == mHead)
			{
				mHead = curr->mNext;
				
				if (curr == mTail)
				{
					mTail = curr->mNext;
				}
				delete curr;
			}
			else if (curr == mTail)
			{
				mTail = prev;
				mTail->mNext = nullptr;
				delete curr;
			}			
			else
			{
				prev->mNext = curr->mNext;
				delete curr;				
			}
			
			--mSize;
			found = true;
		}
		
		prev = curr;
		curr = curr->mNext;		
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
	if (this->empty())
	{
		std::cout << std::endl << __FUNCTION__ << ": This list is empty." << std::endl;
		return;
	}

	Node::Ptr curr (mHead);	

	std::cout << std::endl << __FUNCTION__ << ": List contents(" << mSize << ")" << std::endl;
	
	while (curr != nullptr)
	{
		std::cout << curr->mValue << " ";
		curr = curr->mNext;
	}

	std::cout << "\n-- End --" <<  std::endl;
}


template <typename T>
void kd::SinglyLinkedList<T>::clear()
{
	while (mHead != nullptr)
	{
		Node::Ptr nodeToDelete(mHead);
		mHead = mHead->mNext;
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
const typename kd::SinglyLinkedList<T>::Node& kd::SinglyLinkedList<T>::tail()
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

