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

#include <memory>

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
	using NodePtr = std::shared_ptr<Node>;

	/// Singly-linked Node
	struct Node
	{
		Node() : value(), next() {}
		Node(T v, NodePtr n) : value(v), next(n) {}
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

	/// Removes an item from the list (if it exists)
	bool remove(const T& val);

	/// Indicates whether the list is empty
	bool empty() const;

	/// Print the contents of the list
	void print() const;

	/// Delete the list
	void clear();

	/// Returns the number of items in the list
	size_t size() const;

	/// Returns a reference to the head of this list
	const NodePtr& head();

private:
	NodePtr mHead;	// Head of the list
	size_t mSize;		// Keeps a record of the list's size

};

} // namespace kd

// Include implementation
#include <datastructures/impl/linked_list.hpp>

#endif /* KD_TRIAL_LINKED_LIST_H_ */
