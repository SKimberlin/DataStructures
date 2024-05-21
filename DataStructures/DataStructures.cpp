#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructures
{
	TEST_CLASS(Single_Linked_List)
	{
	public:
		TEST_METHOD(count_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::IsTrue(list.Count() == 0);
		}
		TEST_METHOD(count_pop)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.push_back(4);
			list.push_back(8);
			list.push_back(99);
			Assert::IsTrue(list.Count() == 3);
			list.pop_back();
			list.pop_back();
			Assert::IsTrue(list.Count() == 1);
		}
		TEST_METHOD(push_front)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.push_front(4);
			Assert::IsTrue(list.Head()->value == 4);
			list.push_front(8);
			Assert::IsTrue(list.Head()->value == 8);
			list.push_front(99);
			Assert::IsTrue(list.Head()->value == 99);
		}
		TEST_METHOD(push_front_null)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.push_front(NULL);
			Assert::IsTrue(list.Head()->value == NULL);
		}
		TEST_METHOD(pop_front)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.push_front(4);
			list.push_front(8);
			list.push_front(99);
			Assert::IsTrue(list.Head()->value == 99);
			list.pop_front();
			Assert::IsTrue(list.Head()->value == 8);
			list.pop_front();
			Assert::IsTrue(list.Head()->value == 4);
		}
		TEST_METHOD(pop_front_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::IsTrue(list.Head() == nullptr);
			Assert::IsTrue(list.Count() == 0);
			Assert::ExpectException<std::out_of_range>([&list] { list.pop_front(); });

		}
		TEST_METHOD(push_back)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.push_back(4);
			Assert::IsTrue(list.Tail()->value == 4);
			list.push_back(8);
			Assert::IsTrue(list.Tail()->value == 8);
			list.push_back(99);
			Assert::IsTrue(list.Tail()->value == 99);
		}
		TEST_METHOD(push_back_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::IsTrue(list.Tail() == nullptr);
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");
			list.push_back(232);
			Assert::IsTrue(list.ToString() == "232");
			Assert::IsTrue(list.Count() == 1);
			Assert::IsTrue(list.Tail()->value == 232);
			Assert::IsTrue(list.Head()->value == 232);
		}
		TEST_METHOD(remove)
		{
			SingleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.ToString() == "2, 5, 69, 29, 39");
			Assert::IsTrue(list.Count() == 5);
			Assert::IsTrue(list.remove(2) == 69);
			Assert::IsTrue(list.ToString() == "2, 5, 29, 39");
			Assert::IsTrue(list.Count() == 4);
		}
		TEST_METHOD(remove_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::ExpectException<std::out_of_range>([&list] { list.remove(54); });
		}
		TEST_METHOD(clear)
		{
			SingleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.Count() == 5);
			list.clear();
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");

		}
		TEST_METHOD(clear_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			list.clear();
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");
		}
		TEST_METHOD(get)
		{
			SingleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.get(0) == 2);
			Assert::IsTrue(list.get(2) == 69);
			Assert::IsTrue(list.get(4) == 39);
		}
		TEST_METHOD(get_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::ExpectException<std::out_of_range>([&list] { list.get(45); });
		}
		TEST_METHOD(search)
		{
			SingleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.search(2) == 0);
			Assert::IsTrue(list.search(69) == 2);
			Assert::IsTrue(list.search(39) == 4);
		}
		TEST_METHOD(search_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::IsTrue(list.search(49) == -1);
		}
		TEST_METHOD(ToString)
		{
			SingleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.ToString() == "2, 5, 69, 29, 39");
		}
		TEST_METHOD(ToString_empty)
		{
			SingleLinkedList<int> list = SingleLinkedList<int>();
			Assert::IsTrue(list.ToString() == "");
		}
	};

	TEST_CLASS(Double_Linked_List)
	{
	public:
		TEST_METHOD(count_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::IsTrue(list.Count() == 0);
		}
		TEST_METHOD(count_pop)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.push_back(4);
			list.push_back(8);
			list.push_back(99);
			Assert::IsTrue(list.Count() == 3);
			list.pop_back();
			list.pop_back();
			Assert::IsTrue(list.Count() == 1);
		}
		TEST_METHOD(push_front)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.push_front(4);
			Assert::IsTrue(list.Head()->value == 4);
			list.push_front(8);
			Assert::IsTrue(list.Head()->value == 8);
			list.push_front(99);
			Assert::IsTrue(list.Head()->value == 99);
		}
		TEST_METHOD(push_front_null)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.push_front(NULL);
			Assert::IsTrue(list.Head()->value == NULL);
		}
		TEST_METHOD(pop_front)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.push_front(4);
			list.push_front(8);
			list.push_front(99);
			Assert::IsTrue(list.Head()->value == 99);
			list.pop_front();
			Assert::IsTrue(list.Head()->value == 8);
			list.pop_front();
			Assert::IsTrue(list.Head()->value == 4);
		}
		TEST_METHOD(pop_front_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::IsTrue(list.Head() == nullptr);
			Assert::IsTrue(list.Count() == 0);
			Assert::ExpectException<std::out_of_range>([&list] { list.pop_front(); });

		}
		TEST_METHOD(push_back)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.push_back(4);
			Assert::IsTrue(list.Tail()->value == 4);
			list.push_back(8);
			Assert::IsTrue(list.Tail()->value == 8);
			list.push_back(99);
			Assert::IsTrue(list.Tail()->value == 99);
		}
		TEST_METHOD(push_back_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::IsTrue(list.Tail() == nullptr);
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");
			list.push_back(232);
			Assert::IsTrue(list.ToString() == "232");
			Assert::IsTrue(list.Count() == 1);
			Assert::IsTrue(list.Tail()->value == 232);
			Assert::IsTrue(list.Head()->value == 232);
		}
		TEST_METHOD(remove)
		{
			DoubleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.ToString() == "2, 5, 69, 29, 39");
			Assert::IsTrue(list.Count() == 5);
			Assert::IsTrue(list.remove(2) == 69);
			Assert::IsTrue(list.ToString() == "2, 5, 29, 39");
			Assert::IsTrue(list.Count() == 4);
		}
		TEST_METHOD(remove_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::ExpectException<std::out_of_range>([&list] { list.remove(54); });
		}
		TEST_METHOD(clear)
		{
			DoubleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.Count() == 5);
			list.clear();
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");

		}
		TEST_METHOD(clear_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			list.clear();
			Assert::IsTrue(list.Count() == 0);
			Assert::IsTrue(list.ToString() == "");
		}
		TEST_METHOD(get)
		{
			DoubleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.get(0) == 2);
			Assert::IsTrue(list.get(2) == 69);
			Assert::IsTrue(list.get(4) == 39);
		}
		TEST_METHOD(get_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::ExpectException<std::out_of_range>([&list] { list.get(45); });
		}
		TEST_METHOD(search)
		{
			DoubleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.search(2) == 0);
			Assert::IsTrue(list.search(69) == 2);
			Assert::IsTrue(list.search(39) == 4);
		}
		TEST_METHOD(search_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::IsTrue(list.search(49) == -1);
		}
		TEST_METHOD(ToString)
		{
			DoubleLinkedList<int> list = { 2, 5, 69, 29, 39 };
			Assert::IsTrue(list.ToString() == "2, 5, 69, 29, 39");
		}
		TEST_METHOD(ToString_empty)
		{
			DoubleLinkedList<int> list = DoubleLinkedList<int>();
			Assert::IsTrue(list.ToString() == "");
		}
	};

	TEST_CLASS(Stack_Tests)
	{
		TEST_METHOD(Peek_Test)
		{
			Stack<int> stack;
			stack.Push(10);
			Assert::IsTrue(stack.Peek() == 10);

			stack.Push(20);
			Assert::IsTrue(stack.Peek() == 20);
			Assert::IsTrue(stack.Peek() == 20);
		}
		TEST_METHOD(Get_Test)
		{
			Stack<int> stack;
			stack.Push(10);
			Assert::IsTrue(stack.Get(0) == 10);

			stack.Push(20);
			Assert::IsTrue(stack.Get(0) == 20);

			stack.Push(30);
			Assert::IsTrue(stack.Get(0) == 30);
		}
		TEST_METHOD(PushPop_Test)
		{
			Stack<int> stack;
			stack.Push(10);
			stack.Push(20);
			stack.Push(30);

			Assert::IsTrue(stack.Pop() == 30);
			Assert::IsTrue(stack.Pop() == 20);
			Assert::IsTrue(stack.Pop() == 10);
		}
		TEST_METHOD(Contain_Test)
		{
			Stack<int> stack;
			stack.Push(10);
			stack.Push(20);
			stack.Push(30);

			Assert::IsTrue(stack.Contains(10));
			Assert::IsTrue(stack.Contains(20));
			Assert::IsTrue(stack.Contains(30));
			Assert::IsFalse(stack.Contains(40));
		}
	};

	TEST_CLASS(Queue_Tests)
	{
		TEST_METHOD(Peek_Test)
		{
			Queue<int> queue;
			queue.Enqueue(10);
			Assert::IsTrue(queue.Peek() == 10);

			queue.Enqueue(20);
			Assert::IsTrue(queue.Peek() == 10);
			Assert::IsTrue(queue.Peek() == 10);
		}
		TEST_METHOD(Get_Test)
		{
			Queue<int> queue;
			queue.Enqueue(10);
			Assert::IsTrue(queue.Get(0) == 10);

			queue.Enqueue(20);
			Assert::IsTrue(queue.Get(0) == 10);

			queue.Enqueue(30);
			Assert::IsTrue(queue.Get(0) == 10);

		}
		TEST_METHOD(EnqueueDequeue_Test)
		{
			Queue<int> queue;
			queue.Enqueue(10);
			queue.Enqueue(20);
			queue.Enqueue(30);

			Assert::IsTrue(queue.Dequeue() == 10);
			Assert::IsTrue(queue.Dequeue() == 20);
			Assert::IsTrue(queue.Dequeue() == 30);
		}
		TEST_METHOD(Contain_Test)
		{
			Queue<int> queue;
			queue.Enqueue(10);
			queue.Enqueue(20);
			queue.Enqueue(30);

			Assert::IsTrue(queue.Contains(10));
			Assert::IsTrue(queue.Contains(20));
			Assert::IsTrue(queue.Contains(30));
			Assert::IsFalse(queue.Contains(40));
		}
	};

	TEST_CLASS(BinaryTree_Tests)
	{

		// Add Tests
		TEST_METHOD(Add_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.Count() == 0);

			tree.Add(23);
			Assert::IsTrue(tree.Count() == 1);
			
			tree.Add(12);
			Assert::IsTrue(tree.Count() == 2);

			tree.Add(55);
			Assert::IsTrue(tree.Count() == 3);

			tree.Add(12);
			Assert::IsTrue(tree.Count() == 4);

			tree.Add(40);
			Assert::IsTrue(tree.Count() == 5);

			tree.Add(100);
			Assert::IsTrue(tree.Count() == 6);

			tree.Add(49);
			Assert::IsTrue(tree.Count() == 7);

			tree.Add(66);
			Assert::IsTrue(tree.Count() == 8);

			tree.Add(1);
			Assert::IsTrue(tree.Count() == 9);

			tree.Add(21);
			Assert::IsTrue(tree.Count() == 10);
		}

		TEST_METHOD(AddNull_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.Count() == 0);

			tree.Add(NULL);
			Assert::IsTrue(tree.Count() == 1);

			Assert::IsTrue(tree.Contains(0));
		}
		
		// Clear Tests
		TEST_METHOD(Clear_Test)
		{
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40 };
			Assert::IsTrue(tree.Count() == 5);
			Assert::IsTrue(tree.Contains(55));

			tree.Clear();
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsFalse(tree.Contains(55));
		}

		TEST_METHOD(ClearEmpty_Test)
		{
			BinarySearchTree<int> tree;

			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);

			tree.Clear();

			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);
		}

		// Height Tests

		TEST_METHOD(Height_Test)
		{
			BinarySearchTree<int> tree = BinarySearchTree<int>();
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);

			tree.Add(23);
			Assert::IsTrue(tree.Count() == 1);
			Assert::IsTrue(tree.Height() == 1);

			tree.Add(12);
			tree.Add(55);
			Assert::IsTrue(tree.Count() == 3);
			Assert::IsTrue(tree.Height() == 2);

			tree.Add(12);
			Assert::IsTrue(tree.Count() == 4);
			Assert::IsTrue(tree.Height() == 3);

			tree.Add(12);
			Assert::IsTrue(tree.Count() == 5);
			Assert::IsTrue(tree.Height() == 4);

			tree.Add(66);
			Assert::IsTrue(tree.Count() == 6);
			Assert::IsTrue(tree.Height() == 4);

			tree.Clear();
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);
		}

		// Remove Tests

		TEST_METHOD(RemoveTwoChildren_Test)
		{
			//        23
			//     12    55
			//   12    40  60
			//           45
			//         44
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40, 45, 44, 60 };
			Assert::IsTrue(tree.InOrder() == "12, 12, 23, 40, 44, 45, 55, 60");
			Assert::IsTrue(tree.PreOrder() == "23, 12, 12, 55, 40, 45, 44, 60");
			Assert::IsTrue(tree.PostOrder() == "12, 12, 44, 45, 40, 60, 55, 23");
			tree.Remove(55);

			
			//        23
			//     12    45
			//   12    40  60
			//          44
			Assert::IsTrue(tree.InOrder() == "12, 12, 23, 40, 44, 45, 60");
			Assert::IsTrue(tree.PreOrder() == "23, 12, 12, 45, 40, 44, 60");
			Assert::IsTrue(tree.PostOrder() == "12, 12, 44, 40, 60, 45, 23");

		}

		TEST_METHOD(RemoveEmpty_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);
			tree.Remove(400);
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsTrue(tree.Height() == 0);
		}

		// To Array Tests

		TEST_METHOD(ToArray_Test)
		{
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40 };
			std::vector<int> arr{ 12, 12, 23, 40, 55 };
			Assert::IsTrue(tree.ToArray() == arr);
		}

		TEST_METHOD(ToArrayEmpty_Test)
		{
			BinarySearchTree<int> tree = BinarySearchTree<int>();
			std::vector<int> arr;
			Assert::IsTrue(tree.ToArray() == arr);
		}

		// In Order Tests

		TEST_METHOD(InOrder_Test)
		{
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40 };
			Assert::IsTrue(tree.InOrder() == "12, 12, 23, 40, 55");
		}

		TEST_METHOD(InOrderEmpty_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.InOrder() == "");
		}

		// Pre Order Tests

		TEST_METHOD(PreOrder_Test)
		{
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40 };
			Assert::IsTrue(tree.PreOrder() == "23, 12, 12, 55, 40");
		}

		TEST_METHOD(PreOrderEmpty_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.PreOrder() == "");
		}

		// Post Order Tests

		TEST_METHOD(PostOrder_Test)
		{
			BinarySearchTree<int> tree{ 23, 12, 55, 12, 40 };
			Assert::IsTrue(tree.PostOrder() == "12, 12, 40, 55, 23");
		}

		TEST_METHOD(PostOrderEmpty_Test)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.PostOrder() == "");
		}
	};

	TEST_CLASS(AVLTree_Tests)
	{
		TEST_METHOD(LeftRotation_Test)
		{
			AVLTree<int> tree = AVLTree<int>();
			tree.Add(15);
			tree.Add(25);
			tree.Add(35);

			Logger::WriteMessage(tree.PostOrder().c_str());

			Assert::IsTrue("15, 35, 25" == tree.PostOrder());
		}

		TEST_METHOD(RightLeftRotation_Test)
		{
			AVLTree<int> tree = AVLTree<int>();
			tree.Add(15);
			tree.Add(25);
			tree.Add(20);

			Logger::WriteMessage(tree.PostOrder().c_str());

			Assert::IsTrue("15, 25, 20" == tree.PostOrder());
		}

		TEST_METHOD(ToArray_Test)
		{
			AVLTree<int> tree = { 23, 5, 15, 42, 3, 7, 9, 27, 35, 18 };

			std::vector<int> arr = tree.ToArray();
			std::vector<int> breadth = { 15, 5, 27, 3, 7, 23, 42, 9, 18, 35 };

			Assert::IsTrue(arr == breadth);
		}

		TEST_METHOD(Remove_Test)
		{
			AVLTree<int> tree = { 23, 5, 15, 42, 3, 7, 9, 27, 35, 18 };

			tree.Remove(5);

			std::vector<int> expected = { 15, 7, 27, 3, 9, 23, 42, 18, 35 };
			std::vector<int> result = tree.ToArray();
			Assert::IsTrue(expected == result);
		}
	};
}
