#pragma once
#include "List.h"

template<typename T>
class DoubleLinkedList : public List<T> {
public:
	DoubleLinkedList() {}
	DoubleLinkedList(std::initializer_list<T> args)
	{
		for (const T& arg : args) push_back(arg);
	}

	inline void insert(const T value, const size_t& index) override
	{
		if (index < 0 || index >= count) return;
		if (index == 0)
		{
			push_front(value);
			return;
		}

		Node* node = head;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		Node* newNode = new Node(value);
	}

	inline void push_front(const T value) override
	{
		Node* newNode = new Node(value);
		if (head)
		{
			newNode->next = head;
			head->prev = newNode;
		}
		if (!tail) tail = newNode;
		head = newNode;
		count++;
	}

	inline T pop_front() override
	{
		if (!head)
		{
			throw std::out_of_range("Cannot pop from an empty list");
			return NULL;
		}

		T output = head->value;
		Node* node = head->next;
		delete head;
		if (node) node->prev = nullptr;
		head = node;
		count--;
		return output;
	}

	inline void push_back(const T value) override
	{
		Node* newNode = new Node(value);
		if (tail)
		{
			tail->next = newNode;
			newNode->prev = tail;
		}
		if (!head) head = newNode;
		tail = newNode;
		count++;
	}

	inline T pop_back() override
	{
		if (!tail)
		{
			throw std::out_of_range("Cannot pop from an empty list");
			return NULL;
		}

		T output = tail->value;
		Node* node = tail->prev;
		delete tail;
		if (node) node->next = nullptr;
		tail = node;
		count--;
		return output;
	}

	inline T remove(const size_t& index) override
	{
		if (index < 0 || index >= count)
		{
			throw std::out_of_range("index out of bounds");
			return NULL;
		}
		if (index == 0) return pop_front();
		if (index == count - 1) return pop_back();

		Node* node = head;
		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
		T output = node->value;
		node->next->prev = node->prev;
		node->prev->next = node->next;
		delete node;
		count--;
		return output;
	}
};