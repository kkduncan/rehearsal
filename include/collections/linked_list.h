/**
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * trial is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with trial.  If not, see <http://www.gnu.org/licenses/>.
 *
 * \file linked_list.h
 * \author KDuncan
 */
#pragma once
#ifndef KD_TRIAL_LINKED_LIST_H_
#define KD_TRIAL_LINKED_LIST_H_

/**
 * \brief Namespace containing all functionality
 */
namespace kd
{
/**
 * \brief Singly-Linked List (or Forward List)
 */
template <typename T>
class SinglyLinkedList
{
public:
	/// Singly-linked Node
	class Node
	{
		friend class SinglyLinkedList;				

	public:
		Node() : mValue(), mNext(nullptr) {}
		Node(T v) : mValue(v), mNext(nullptr) {}
		const T& value() const { return mValue; }
		T& value() { return mValue; }

	private:
		using Ptr = Node*;
		T mValue;
		Ptr mNext;
	};

public:
	/// Constructor
	SinglyLinkedList();

	/// Destructor
	virtual ~SinglyLinkedList();

	/// Adds an item to the front of the list
	void pushToFront(const T& val);

	/// Adds an item to the end of the list
	void pushToBack(const T& val);

	/// Removes the first occurrence of an item from the list (if it exists)
	bool remove(const T& val);

	/// Removes the item at the specified index
	bool remove(const size_t& idx);

	/// Indicates whether the list is empty
	bool empty() const;

	/// Print the contents of the list
	void print() const;

	/// Delete this list
	void clear();

	/// Returns the number of items in the list
	size_t size() const;

	/// Returns a reference to the first element of this list
	const Node& head();

	/// Returns a reference to the last element of this list
	const Node& tail();

private:
	typename Node::Ptr mHead;	// Head of the list
	typename Node::Ptr mTail;	// End of the list
	size_t mSize;	// Keeps a record of the list's size

};

} // namespace kd

// Include implementation
#include <collections/impl/linked_list.hpp>

#endif /* KD_TRIAL_LINKED_LIST_H_ */
