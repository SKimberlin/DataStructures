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
	/*
	* @brief Uses recursion to find where to put value, while unwinding it automatically balances the tree
	* @brief This method has a time complexity of O(log n)
	* @param Value to be added
	*/
	void Add(const T& value) override
	{
		Add(root, value);
		numberOfNodes++;
	}
	/*
	* @brief Uses recursion to find what node to remove, while unwinding it automatically balances the tree
	* @brief This method has a time complexity of O(log n)
	* @param Value to be removed
	*/
	void Remove(const T& value) override
	{
		Remove(root, value);
	}
	/*
	* @brief Uses a queue to add nodes the first time it sees them, breadth first
	* @brief This method has a time complexity of O(n)
	* @return A vector of the values in breadth first order
	*/
	std::vector<T> ToArray() override
	{
		
		std::vector<T> array;
		Queue<Node*> queue;
		if (root) queue.Enqueue(root);
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
	// Add and remove are O(log n) because each time it compares, it halves the current data set size
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

	/*
	* @brief This method has a time complexity of O(1)
	* @param Node to balance
	*/
	void Balance(Node*& node)
	{
		if (!node) return;
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
	
	/*
	* @brief This method has a time complexity of O(1)
	* @param Parent of pivot node
	*/
	void LeftRotation(Node*& node)
	{
		Node* newRoot = node->right;
		node->right = newRoot->left;
		newRoot->left = node;
		UpdateHeight(node);
		node = newRoot;
		UpdateHeight(node);
	}

	/*
	* @brief This method has a time complexity of O(1)
	* @param Parent of pivot node
	*/
	void RightRotation(Node*& node)
	{
		Node* newRoot = node->left;
		node->left = newRoot->right;
		newRoot->right = node;
		UpdateHeight(node);
		node = newRoot;
		UpdateHeight(node);
	}

	/*
	* @brief sets the height of the given node to its greatest childs height +1
	* @brief This method has a time complexity of O(1)
	* @param Node to update the height for
	*/
	void UpdateHeight(Node*& node)
	{
		if (node) node->height = std::max((node->left ? node->left->height : 0), (node->right ? node->right->height : 0)) + 1;
	}

};