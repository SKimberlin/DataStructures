#pragma once
#include <string>
#include <sstream>

template<typename T>
class Tree
{
public:
	struct Node
	{
		Node(const T value) : value{ value } {}
		T value;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* prev = nullptr;
	};

	Tree() {}

	void Add(const T& value)
	{
		size_t counter = 0;
		Add(root, value, counter);
		if (counter > height) height = counter;
		numberOfNodes++;
	}

	bool Contains(const T& value)
	{
		return Contains(root, value);
	}

	size_t Count()
	{
		return numberOfNodes;
	}

	void Clear()
	{
		if (root)
		{
			Clear(root);
			numberOfNodes = 0;
			root = nullptr;
		}
	}

	std::string ToString()
	{
		std::stringstream ss;
		ToString(root, ss);
		return ss.str();
	}

private:

	void Add(Node*& node, const T& value, size_t& counter)
	{
		counter++;
		if (!node)
		{
			node = new Node(value);
			return;
		}
		if (node->value < value) Add(node->right, value, counter);
		else Add(node->left, value, counter);
	}

	bool Contains(Node*& node, const T& value)
	{
		if (!node) return false;
		if (node->value == value) return true;
		if (node->value < value) return Contains(node->right, value);
		else return Contains(node->left, value);
	}

	void Clear(Node*& node)
	{
		if (node->left) Clear(node->left);
		if (node->right) Clear(node->right);
		delete node;
	}

	void ToString(Node*& node, std::stringstream& ss)
	{
		if (node->left) ToString(node->left, ss);
		if (node->right) ToString(node->right, ss);
		ss << node->value << ", ";
	}

	size_t height = 0;
	size_t numberOfNodes = 0;
	Node* root = nullptr;
	
};