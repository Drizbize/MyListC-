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
		if (index < 0)
		{
			Node* previous = next->previous;
			newNode->previous = previous;
			newNode->next = next;
		}
		else
		{
			newNode->next = first;
			first = newNode;
			first->previous = newNode;
			newNode->previous = nullptr;
		}
		size++;
	}

	void DeleteList()
	{
		Node* current = last;
		while (current)
		{
			//current->value = nullptr;
			current = current->previous;			
		}
		size = 0;
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
	list.Push(2);
	list.Push(7);
	list.Push(32);

	list.insert(5, 3);  // 10 , 20 , 30

	list.Print();
}