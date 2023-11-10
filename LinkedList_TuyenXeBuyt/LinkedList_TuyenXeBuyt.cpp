#include <iostream>
using namespace std;

struct Node
{
	Node* link;
	int value;
};
typedef struct Node* node;

node init(node& a) {
	return	a = NULL;
}

void insertFirst(node& main, int a)
{
	node temp = new Node();
	temp->value = a;
	temp->link = main;
	main = temp;
}

void insertLast(node& main, int value)
{
	node newnode = new Node();
	newnode->value = value;
	newnode->link = NULL;
	if (main == NULL)
		main = newnode;
	else
	{
		node last = main;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = newnode;
		last = newnode;
	}
}

void insertAfter(node main, int value)
{
	node newNode = new Node();
	newNode->value = value;
	newNode->link = NULL;
	if (main == NULL)
	{
		cout << "There is no linked list.";
		return;
	}
	else
	{
		newNode->link = main->link;
		main->link = newNode;
	}
}

bool findValue(node a, int valueSearching)
{
	node temp = a;
	while (temp != NULL)
	{
		if (temp->value == valueSearching)
			return true;
		temp = temp->link;
	}
	return false;
}

void insertAfterSpecificNode(node& main, int value, int search)
{
	node temp = main;
	while (temp->value != search)
	{
		temp = temp->link;
	}
	if (temp == NULL)
	{
		cout << "Khong tim thay gia tri can them.";
	}
	else
	{
		node newNode = new Node();
		newNode->value = value;
		newNode->link = temp->link;
		temp->link = newNode;
	}
}

void import(node & main)
{
	do
	{
		int x;
		cout << "Nhap gia tri linked list: ";
		cin >> x;
		if (x == -99)
			insertLast(main, x);
		main = main->link;
	} while (true);
}

void printOutcome(node a)
{
	while (a != NULL)
	{
		cout << a->value << " -> ";
		a = a->link;
	}
	cout << "NULL \n";
}



void main() {
	/*node a, b, c;
	init(a); init(b); init(c);
	a = new Node();
	b = new Node();
	c = new Node();*/

	/*a->value = 10;
	a->link = NULL;
	b->value = 20;
	b->link = a;
	c->value = 30;
	c->link = b;*/

	/*cout << "Insert after node 2: \n";
	insertAfter(b, 15);
	printOutcome(c);

	cout << "Insert after node 3:\n";
	insertAfter(c, 25);
	printOutcome(c);*/
	node head;
	init(head);



	int search, valueAdding;
	cout << "Nhap gia tri can tim: ";
	cin >> search;
	cout << "Nhap gia tri can them: ";
	cin >> valueAdding;
	insertAfterSpecificNode(head, valueAdding, search);

	printOutcome(head);


	
	system("pause");
}