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
		Node* current = FindAt(index);

		if (!current || index < 0)
		{
			std::cout << "wrong index\n";
			return;
		}

		Node* newNode = new Node;
		newNode->value = value;
		if (index > 0)
		{
			current = current->previous;
			newNode->next = current->next;
			current->next = newNode;
			newNode->previous = current;
		}
		else
		{
			newNode->next = first;
			first = newNode;
			first->previous = newNode;
			newNode->previous = nullptr;
		}	
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
	list.Push(60);

	list.insert(555, 7);

	list.Print();
}