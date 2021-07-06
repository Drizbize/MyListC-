// MyListC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
	int value;
	Node* next = nullptr;
	Node* previous = nullptr;
};

class List {
public:
	Node* first = nullptr;
	Node* last = nullptr;
	int size = 0;
	void Push(int value)
	{
		Node* newNode = new Node;
		newNode->value = value;
		if (!first)
		{
			first = newNode;
		}
		else
		{
			last->next = newNode;
			newNode->previous = last;
		}
		last = newNode;
		size++;
	}

	void insert(int value, int index)
	{
		if (index == size)
		{
			Push(value);
			return;
		}

		Node* next = FindAt(index);

		if (!next)
		{
			std::cout << "wrong index\n";
			return;
		}

		Node* newNode = new Node;
		newNode->value = value;
		if (index > 0)
		{
			Node* previous = next->previous;
			newNode->previous = previous;
			newNode->next = next;
			previous->next = newNode;
			next->previous = newNode;
		}
		else
		{
			newNode->next = first;
			first->previous = newNode;
			first = newNode;
		}
		size++;
	}

	void DeleteList()
	{
		Node* current = last;
		
		while (current)
		{
			current = last;
			if (current == nullptr)
			{
				first = nullptr;
				last = nullptr;
				size = 0;
				return;
			}
			last = current->previous;
			delete current;
		}
	}

	Node* FindAt(int index)
	{
		Node* current = first;
		if (index < 0)
		{
			return nullptr;
		}
		else if (index + 1 > size)
		{
			return nullptr;
		}
		for (int i = 0; i < index; i++)
		{
			current = current->next;
			if (!current)
			{
				return nullptr;
			}
		}
		return current;
	}

	Node* Find(int findnumber)
	{
		Node* current = first;
		while (current)
		{
			if (current->value == findnumber)
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

	void Print()
	{
		Node* current = first;
		if (!current)
		{
			std::cout << "List is empty";
		}
		while (current)
		{
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << "\n";
	}

	void PrintSize()
	{
		std::cout << size << "\n";
	}
};

int main()
{
	List list;
	list.Push(10);
	list.Push(20);
	list.Push(30);

	list.insert(5, 0);
	list.insert(6, 0);

	list.Print();
	list.DeleteList();
	list.Print();
}