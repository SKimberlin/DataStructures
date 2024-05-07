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

	TEST_CLASS(Tree_Tests)
	{
		TEST_METHOD(Add_Test)
		{
			Tree<int> tree;
			tree.Add(23);
			tree.Add(12);
			tree.Add(55);
			tree.Add(12);
			tree.Add(40);
			tree.Add(100);
			tree.Add(49);
			tree.Add(66);
			tree.Add(1);
			tree.Add(21);

			Logger::WriteMessage(tree.ToString().c_str());
		}

		TEST_METHOD(Clear_Test)
		{
			Tree<int> tree;
			Assert::IsTrue(tree.Count() == 0);

			tree.Add(23);
			tree.Add(12);
			tree.Add(55);
			tree.Add(12);
			tree.Add(40);
			Assert::IsTrue(tree.Count() == 5);
			Assert::IsTrue(tree.Contains(55));

			tree.Clear();
			Assert::IsTrue(tree.Count() == 0);
			Assert::IsFalse(tree.Contains(55));
		}
	};
}
