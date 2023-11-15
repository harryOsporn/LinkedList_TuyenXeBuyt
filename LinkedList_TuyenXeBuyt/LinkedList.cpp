#include <iostream>
using namespace std;

class Node {
public:
	Node* link;
	int value;
};

typedef class Node* node;
node makeNode(int data)
{//
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
void insertTaiViTri(node& list, int value, int pos) {
	node newNode = makeNode(value);
	if (pos == 1)
	{
		newNode->link = list;
		list = newNode;
		return;
	}
	node temp = list;
	int i = 1;
	while (temp != NULL)
	{
		if (i == pos - 1)
			break;
		i++;
		temp = temp->link;
	}
	newNode->link = temp->link;
	temp->link = newNode;
}
void deleteFront(node& list)
{
	if (list == NULL)
		return;
	list = list->link;
}
void deleteLast(node& list)
{
	if (list == NULL)
		return;
	node prev = NULL, next = list;
	while (next->link != NULL)
	{
		prev = next;
		next = next->link;
	}
	prev->link = next->link;
}
void loadData(node& current) {
	insertLast(current, 30);
	insertLast(current, 20);
	insertLast(current, 10);
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
void sapXep(node& list) {
	for (node p = list; p->link != NULL; p = p->link) {
		node min = p;
		for (node q = p->link; q != NULL; q = q->link) {
			if (q->value < min->value)
			{
				min = q;
			}
		}
		int temp = min->value;
		min->value = p->value;
		p->value = temp;
	}
}
void deleteMiddle(node& list, int pos)
{
	if (pos == 1)
		deleteFront(list);
	else {
		node temp = list;
		for (int i = 1; i <= pos - 2; i++) {
			temp = temp->link;
		}
		node remove = temp->link;
		temp->link = remove->link;
		delete remove;
	}
}

int menu()
{
	int luaChon;
	node head = NULL;

	do
	{
		cout << "\n0. Thoat.";
		cout << "\n1. Nhap gia tri.";
		cout << "\n2. Them gia tri tai vi tri bat ky.";
		cout << "\n3. Print dslk.";
		cout << "\n4. Tim kiem Node's position bang data.";
		cout << "\n5. Xoa node dau.";
		cout << "\n6, Xoa node cuoi.";
		cout << "\n7. Xoa 1 node tai vi tri.";
		cout << "\n8. Sap xep dslk theo gia tri tang dan.";
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
			int value, pos;
			cout << "Nhap vi tri: "; cin >> pos;
			cout << "Nhap gia tri: "; cin >> value;
			insertTaiViTri(head, value, pos);
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
		case 5:
			deleteFront(head);
			break;
		case 6:
			deleteLast(head);
			break;
		case 7:
			int viTri;
			cout << "Nhap vi tri can xoa: ";
			cin >> viTri;
			deleteMiddle(head, viTri);
			break;
		case 8:
			sapXep(head);
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