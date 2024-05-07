#pragma once
#include "SingleLinkedList.h"

template<typename T>
class Stack
{
private:
	SingleLinkedList<T> stack;
public:
	Stack()
	{
		stack = SingleLinkedList<T>();
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
		return stack.get(index);
	}

	/**
	* Checks if stack contains a specific value
	*
	* This has a time complexity of O(n)
	* 
	* @param The value to search for
	* @return True if value exists in stack, otherwise false
	*/
	inline bool Contains(const T& value)
	{
		return stack.search(value) != -1;
	}

	/**
	* Retrieves the value at the top of the stack without removing it
	*
	* This has a time complexity of O(1)
	* 
	* @return The value at the top of the stack
	*/
	inline T Peek()
	{
		return stack.Head()->value;
	}

	/**
	* Removes and returns the value at the top of the stack	
	*
	* This has a time complexity of O(1)
	* 
	* @return The value at the top of the stack
	*/
	inline T Pop()
	{
		return stack.pop_front();
	}

	/**
	* Adds a value to the top of the stack
	*
	* This has a time complexity of O(1)
	* 
	* @param The value to push
	*/
	inline void Push(const T value)
	{
		stack.push_front(value);
	}
};