/**
 * trial
 *
 * This file is part of "trial."
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
 * \file linked_list.hpp
 * \author KDuncan
 */
#pragma once
#ifndef KD_TRIAL_LINKED_LIST_HPP_
#define KD_TRIAL_LINKED_LIST_HPP_


/**
 * \brief Singly-Linked List
 */
template <typename ValueType>
class SinglyLinkedList
{
public:
	// Forward declaration
	struct Node;

	// Convenience definitions
	using NodePtr = std::shared_ptr<Node>;

	struct Node
	{
		ValueType value;
		NodePtr next;
	};

public:
	void addToFront(const ValueType& val);
	void addToBack(const ValueType& val);
	bool remove(const ValueType& val);
	bool empty() const;
	size_t size() const;
	NodePtr& head();

private:
	NodePtr mHead;	// Head of the list
	size_t mSize;		// Keeps a record of the list's size

};

#endif /* KD_TRIAL_LINKED_LIST_HPP_ */
