#pragma once
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>


template<typename T>
class List {
protected:
	struct Node
	{
		Node(const T& value) : value{ value } {}
		T value;
		Node* next{ nullptr };
		Node* prev{ nullptr };
	};

	size_t count = 0;
	Node* head{ nullptr };
	Node* tail{ nullptr };

	
public:
	
	List() {}

	inline Node* Head()
	{
		return head;
	}
	inline Node* Tail()
	{
		return tail;
	}

	inline size_t& Count()
	{
		return count;
	}

	virtual void insert(const T value, const size_t& index) = 0;
	virtual void push_front(const T value) = 0;
	virtual T pop_front() = 0;
	virtual void push_back(const T value) = 0;
	virtual T pop_back() = 0;
	virtual T remove(const size_t& index) = 0;

	inline void clear()
	{
		Node* node = head;
		while (node)
		{
			Node* temp = node->next;
			delete node;
			node = temp;
		}
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	inline T get(const size_t& index)
	{
		if (index < 0 || index >= count)
		{
			throw std::out_of_range("index out of bounds");
			return NULL;
		}
		Node* node = head;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		return node->value;
	}

	inline int search(const T& value)
	{
		Node* node = head;
		int index = 0;
		while (node)
		{
			if (node->value == value) return index;
			index++;
			node = node->next;
		}
		return -1;
	}

	inline std::string ToString()
	{
		std::stringstream ss;

		Node* node = head;
		while (node)
		{
			ss << node->value;
			if (node != tail) ss << ", ";
			node = node->next;
		}
		return ss.str();
	}
};

