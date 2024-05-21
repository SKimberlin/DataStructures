#pragma once
#include "SingleLinkedList.h"

template<typename T>
class Queue
{
private:
	SingleLinkedList<T> queue;

public:
	Queue()
	{
		queue = SingleLinkedList<T>();
	}

	/**
	* Finds and returns value at specified index
	*
	* This has a time complexity of O(n)
	*
	* @param Index of the value
	* @return Value at the specified index
	*/
	inline T Get(const size_t& index)
	{
		return queue.get(index);
	}

	/**
	* Checks if queue contains a specific value
	*
	* This has a time complexity of O(n)
	*
	* @param The value to search for
	* @return True if value exists in queue, otherwise false
	*/
	inline bool Contains(const T& value)
	{
		return queue.search(value) != -1;
	}

	/**
	* Retrieves the value at the bottom of the queue without removing it
	*
	* This has a time complexity of O(1)
	*
	* @return The value at the bottom of the queue
	*/
	inline T Peek()
	{
		return queue.Head()->value;
	}

	/**
	* Removes and returns the value at the bottom of the queue
	*
	* This has a time complexity of O(1)
	*
	* @return The value at the bottom of the queue
	*/
	inline T Dequeue()
	{
		return queue.pop_front();
	}

	/**
	* Adds a value to the top of the queue
	*
	* This has a time complexity of O(1)
	*
	* @param The value to enqueue
	*/
	inline void Enqueue(const T value)
	{
		queue.push_back(value);
	}

	inline bool empty()
	{
		return queue.Count() == 0;
	}
};