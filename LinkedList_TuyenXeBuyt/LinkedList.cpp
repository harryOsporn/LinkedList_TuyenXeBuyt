#include <iostream>
using namespace std;

class Node {
public:
	Node* link;
	int value;
};
typedef class Node* node;
node makeNode(int data)
{
	node temp = new Node();
	temp->value = data;
	temp->link = NULL;
	return temp;
}
void insertFirst(node& main, int a)
{
	if (main == NULL)
		main = makeNode(a);
	node temp = new Node();
	temp->value = a;
	temp->link = main;
	main = temp;
}
void insertLast(node& main, int value)
{
	if (main == NULL)
		main = makeNode(value);
	else {
		node temp = makeNode(value);
		node last = main;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = temp;
		last = temp;
	}
}
void pushFront(node& main, int value)
{
	node newNode = makeNode(value);
	newNode->link = main;
	main = newNode;
}
void pushBack(node& main, int value)
{
	node newNode = makeNode(value);
	if (main == NULL)
	{
		main = newNode;
	}
	else
	{
		node last = main;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = newNode;
	}
}
void import(node & main)
{

	int x;
	do
	{
		cout << "Nhap gia tri linked list: ";
		cin >> x;
		if (x == -99)
			break;
		insertLast(main, x);
	} while (true);
}
int size(node& main)
{
	int length = 0;
	while (main != NULL)
	{
		main = main->link;
		length++;
	}
	return length;
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
void insertValueAtPosition(node& current, int value, int pos)
{
	if (pos < 1 || pos > size(current))
	{
		cout << "Invalid position.";
		return;
	}
	else
	{
		if (pos == 1)
		{
			pushFront(current, value);
		}
		else
		{
			node newNode = makeNode(value);
			node temp = current;
			for (int i = 1; i < pos - 1; i++)
			{
				temp = temp->link;
			}
			newNode->link = temp->link;
			temp->link = newNode;
		}
	}

}
void loadData(node& current) {

	insertLast(current, 20);
	insertLast(current, 30);
	insertLast(current, 40);
	insertLast(current, 60);

}
bool findData(node current, int x)
{
	while (current != NULL)
	{
		if (current->value == x)
			return true;
		current = current->link;
	}
	return false;
}
void deleteNode(node& current, int x) {
	//Tạo hàm xóa cuối và xóa đầu

	node tmp = new Node();
	for (node k = current; k != NULL; k= k->link)
	{
		if (k->value == x)
		{
			
		} 
		tmp = k;
	}
}

int menu()
{
	int luaChon;
	node head = NULL;

	do
	{
		cout << "* * * * * \n";
		cout << "*  MENU *\n";
		cout << "* * * * * \n";
		cout << "\n0. Thoat.";
		cout << "\n1. Nhap gia tri.";
		cout << "\n2. Them gia tri tai vi tri bat ky.";
		cout << "\n3. Print dslk.";
		cout << "\n4. Tim kiem Node's position bang data.";
		cout << "\n5. Xoa 1 node chua data.";
		cout << "\n6. Sap xep dslk theo gia tri tang dan.";
		cout << "\n\t Chon tai day: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 0:
			exit(0);
		case 1:
			import(head);
			break;
		case 2:
			insertValueAtPosition(head, 69, 1);
			break;
		case 3:
			printOutcome(head);
			break;
		case 4:
			int x; cout << "Nhap gia tri can tim: ";
			cin >> x;
			if (findData(head, x) == true)
				cout << "YES";
			else cout << "NO";
			break;
		case 1010:
			loadData(head);
			break;
		}
		cout << "\n---------------------------------------------------------------\n";
	} while (true);
}

void main() {
	menu();
	cout << endl;
	system("pause");
}