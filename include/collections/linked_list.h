/**
 * trial
 *
 *  trial is free software: you can redistribute it and/or modify
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
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
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
 * \brief Singly-Linked List
 */
template <typename T>
class SinglyLinkedList
{
public:
	// Forward declaration
	struct Node;

	// Convenience definitions
	using NodePtr = Node*;


protected:
	/// Singly-linked Node
	struct Node
	{
		Node() : value(), next(nullptr) {}
		Node(T v) : value(v), next(nullptr) {}
		T value;
		NodePtr next;
	};

public:
	/// Constructor
	SinglyLinkedList();

	/// Destructor
	virtual ~SinglyLinkedList();

	/// Adds an item to the front of the list
	void addToFront(const T& val);

	/// Adds an item to the end of the list
	void addToBack(const T& val);

	/// Removes the first occurrence of an item from the list (if it exists)
	bool remove(const T& val);

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
	const Node& end();

private:
	NodePtr mHead;	// Head of the list
	NodePtr mTail;	// End of the list
	size_t mSize;	// Keeps a record of the list's size

};

} // namespace kd

// Include implementation
#include <collections/impl/linked_list.hpp>

#endif /* KD_TRIAL_LINKED_LIST_H_ */
