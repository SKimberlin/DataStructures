#pragma once
#include <cmath>
#include "Queue.h"
#include "BinarySearchTree.h"

template<typename T>
class AVLTree : public BinarySearchTree<T>
{
public:
	AVLTree() {}
	AVLTree(std::initializer_list<T> args)
	{
		for (const T& arg : args) Add(arg);
	}

	void Add(const T& value) override
	{
		Add(root, value);
	}

	void Remove(const T& value) override
	{
		Remove(root, value);
	}

	std::vector<T> ToArray() override
	{
		
		std::vector<T> array;
		Queue<Node*> queue;
		queue.Enqueue(root);
		while (!queue.empty())
		{
			Node* current = queue.Dequeue();
			array.push_back(current->value);
			if (current->left) queue.Enqueue(current->left);
			if (current->right) queue.Enqueue(current->right);

		}

		return array;
	}

private:

	void Add(Node*& node, const T& value)
	{
		if (node)
		{
			if (node->value < value)
			{
				Add(node->right, value);
			}
			else
			{
				Add(node->left, value);
			}
			UpdateHeight(node);
		}
		else node = new Node(value);

		Balance(node);
	}

	void Remove(Node*& node, const T& value)
	{
		if (!node) return;
		if (node->value == value)
		{
			if (!node->right)
			{
				Node* temp = node;
				node = node->left;
				delete temp;
			}
			else if (!node->left)
			{
				Node* temp = node;
				node = node->right;
				delete temp;
			}
			else
			{
				Node*& replacer = FindReplace(node->left);
				node->value = replacer->value;
				delete replacer;
			}
			numberOfNodes--;
		}
		else if (node->value < value) Remove(node->right, value);
		else Remove(node->left, value);

		UpdateHeight(node);
		Balance(node);
	}

	void Balance(Node*& node)
	{
		short balance = (node->right ? node->right->height : 0) - (node->left ? node->left->height : 0);
		if (balance > 1) {
			short subBalance = (node->right->left ? node->right->left->height : 0) - (node->right->right ? node->right->right->height : 0);
			if (subBalance > 0) {
				RightRotation(node->right);
			}
			LeftRotation(node);
		}
		else if (balance < -1) {
			short subBalance = (node->left->left ? node->left->left->height : 0) - (node->left->right ? node->left->right->height : 0);
			if (subBalance < 0) {
				LeftRotation(node->left);
			}
			RightRotation(node);
		}
	}

	void LeftRotation(Node*& node)
	{
		Node* newRoot = node->right;
		node->right = newRoot->left;
		newRoot->left = node;
		UpdateHeight(node);
		node = newRoot;
		UpdateHeight(node);
	}

	void RightRotation(Node*& node)
	{
		Node* newRoot = node->left;
		node->left = newRoot->right;
		newRoot->right = node;
		UpdateHeight(node);
		node = newRoot;
		UpdateHeight(node);
	}

	void UpdateHeight(Node*& node)
	{
		node->height = std::max((node->left ? node->left->height : 0), (node->right ? node->right->height : 0)) + 1;
	}

};