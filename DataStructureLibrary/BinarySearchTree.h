#pragma once
#include <vector>
#include <string>
#include <sstream>

template<typename T>
class BinarySearchTree
{
public:
	struct Node
	{
		Node(const T& value) : value{ value } {}
		T value;
		Node* left = nullptr;
		Node* right = nullptr;
		size_t height = 1;
	};

	BinarySearchTree() {}
	BinarySearchTree(std::initializer_list<T> args)
	{
		for (const T& arg : args) Add(arg);
	}

	~BinarySearchTree()
	{
		Clear();
	}

	/**
	* @brief Adds the specified value to the tree, compares node values to given value to find right position
	* 
	* @brief This has a worst case time complexity of O(n) with n being number of nodes, average case is O(logn)
	* 
	* @param the value to add to the tree
	*/
	virtual void Add(const T& value)
	{
		Add(root, value);
		numberOfNodes++;
	}

	/**
	* @brief Removes the specified value from the tree, compares node values to given value to find node to remove
	* 
	* @brief This has a worst case time complexity of O(n) with n being number of nodes, average case is O(logn)
	* 
	* @param The value to remove
	*/
	virtual void Remove(const T& value)
	{
		Remove(root, value);
	}

	/**
	* @brief This has a worst case time complexity of O(n) with n being number of nodes, average case is O(logn)
	* 
	* @param Value to search for
	* 
	* @return True if values exists in tree, otherwise false
	*/
	bool Contains(const T& value)
	{
		return Contains(root, value);
	}

	/**
	* @brief This has a time complexity of O(1)
	* 
	* @return The number of nodes
	*/
	size_t Count()
	{
		return numberOfNodes;
	}

	/**
	* @brief This has a time complexity of O(n)
	* 
	* @return The height of the tree
	*/
	size_t Height()
	{
		return Height(root);
	}

	/**
	* @brief This has a time complexity of O(n) with n being number of nodes
	* 
	* @brief Deletes every node from the tree
	*/
	void Clear()
	{
		if (root)
		{
			Clear(root);
			numberOfNodes = 0;
			height = 0;
			root = nullptr;
		}
	}
	
	/**
	* @brief This has a time complexity of O(n) with n being number of nodes
	* 
	* @return A sorted vector representation of the tree
	*/
	virtual std::vector<T> ToArray()
	{
		std::vector<T> array;

		if (root) ToArray(root, array);

		return array;
	}

	/**
	* @brief This has a time complexity of O(n) with n being number of nodes
	* 
	* @return A sorted string representation of the tree left->root->right
	*/
	std::string InOrder()
	{
		std::stringstream ss;
		if (root) InOrder(root, ss);
		std::string result = ss.str();
		if (!result.empty())
		{
			result.pop_back();
			result.pop_back();
		}
		return result;
	}

	/**
	* @brief This has a time complexity of O(n) with n being number of nodes
	*
	* @return A string representation of the tree that can be used to remake this exact tree root->left->right
	*/
	std::string PreOrder()
	{
		std::stringstream ss;
		if (root) PreOrder(root, ss);
		std::string result = ss.str();
		if (!result.empty())
		{
			result.pop_back();
			result.pop_back();
		}
		return result;
	}

	/**
	* @brief This has a time complexity of O(n) with n being number of nodes
	*
	* @return A string representation of the tree that follows the nodes from left->right->root
	*/
	std::string PostOrder()
	{
		std::stringstream ss;
		if (root) PostOrder(root, ss);
		std::string result = ss.str();
		if (!result.empty())
		{
			result.pop_back();
			result.pop_back();
		}
		return result;
	}

private:

	void Add(Node*& node, const T& value)
	{
		if (!node)
		{
			node = new Node(value);
			return;
		}
		if (node->value < value) Add(node->right, value);
		else Add(node->left, value);
	}

	size_t Height(Node*& node)
	{
		if (!node) return 0;
		size_t heightLeft = Height(node->left);
		size_t heightRight = Height(node->right);
		return std::max(heightLeft, heightRight) + 1;
	}


	/**
	* @brief The recursive function to remove a value
	* @brief if the node has only one child, it replaces this node with that child
	* @brief if the node has two children, it replaces this node with the largest node in the left subtree
	*/
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
	}

	void Clear(Node*& node)
	{
		if (node->left) Clear(node->left);
		if (node->right) Clear(node->right);
		delete node;
	}

	void ToArray(Node*& node, std::vector<T>& arr)
	{
		if (node->left) ToArray(node->left, arr);
		arr.push_back(node->value);
		if (node->right) ToArray(node->right, arr);
	}

	void InOrder(Node*& node, std::stringstream& ss)
	{
		if (node->left) InOrder(node->left, ss);
		ss << node->value << ", ";
		if (node->right) InOrder(node->right, ss);
	}

	void PreOrder(Node*& node, std::stringstream& ss)
	{
		ss << node->value << ", ";
		if (node->left) PreOrder(node->left, ss);
		if (node->right) PreOrder(node->right, ss);
	}

	void PostOrder(Node*& node, std::stringstream& ss)
	{
		if (node->left) PostOrder(node->left, ss);
		if (node->right) PostOrder(node->right, ss);
		ss << node->value << ", ";
	}

	bool Contains(Node*& node, const T& value)
	{
		if (!node) return false;
		if (node->value == value) return true;
		if (node->value < value) return Contains(node->right, value);
		else return Contains(node->left, value);
	}

	protected:

	/**
	* @brief Find the greatest value of the left subtree and returns a reference to it
	* 
	* @param The lesser subtree node, then in recursion the greater nodes
	* 
	* @return A reference to the node that will replace the removed node
	*/
	Node*& FindReplace(Node*& node)
	{
		if (node->right) return FindReplace(node->right);
		else
		{
			Node* temp = node;
			node = node->left;
			return temp;
		}
	}

	Node* root = nullptr;
	size_t numberOfNodes = 0;
	size_t height = 0;
	
};