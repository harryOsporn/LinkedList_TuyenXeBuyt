#include <iostream>
#include <string>
using namespace std;

class tuyenXeBuyt {
public:
	string ma, ten, diemDau, diemCuoi;
	double cuLy;
};

class xeBuyt {
public:
	xeBuyt* link;
	tuyenXeBuyt xb;
};
typedef class xeBuyt* xb;

xb makeNode()
{//
	tuyenXeBuyt a;
	cout << "Nhap thong tin: \n";
	cout << "Nhap ma tuyen xe: "; cin >> a.ma;
	cout << "Nhap ten tuyen xe: "; cin >> a.ten;
	cout << "Nhap diem dau: "; cin >> a.diemDau;
	cout << "Nhap diem cuoi: "; cin >> a.diemCuoi;
	cout << "Nhap cu ly: "; cin >> a.cuLy;
	xb temp = new xeBuyt();
	temp->xb = a;
	temp->link = NULL;
	return temp;
}

int size(xb& a)
{
	int length = 0;
	while (a != NULL)
	{
		a = a->link;
		length++;
	}
	return length;
}

void insertFirst(xb& main)
{
	xb temp = makeNode();
	if (main == NULL)
		main = temp;
	else {
		temp->link = main;
		main = temp;
	}
}

void insertLast(xb& main)
{
	xb temp = makeNode();
	if (main == NULL)
		main = temp;
	else {
		xb last = main;
		while (last->link != NULL)
		{
			last = last->link;
		}
		last->link = temp;
		last = temp;
	}
}

void insertTaiViTri(xb& list, int pos) {
	xb newNode = makeNode();
	if (pos == 1)
	{
		newNode->link = list;
		list = newNode;
		return;
	}
	xb temp = list;
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
void import(xb & list)
{
	tuyenXeBuyt a;
	do
	{
		cout << "Nhap thong tin: \n";
		cout << "Nhap ma tuyen xe: "; cin >> a.ma;
		cout << "Nhap ten tuyen xe: "; cin >> a.ten;
		cin.ignore();
		cout << "Nhap diem dau: ";
		getline(cin, a.diemDau);
		cout << "Nhap diem cuoi: ";
		getline(cin, a.diemCuoi);
		cout << "Nhap cu ly: "; cin >> a.cuLy;
		cout << "===========\n";
		if (a.cuLy == -99)
			break;
		insertLast(list);
	} while (true);
}

void deleteFront(xb& list)
{
	if (list == NULL)
		return;
	list = list->link;
}

void deleteLast(xb& list)
{
	if (list == NULL)
		return;
	xb prev = NULL, next = list;
	while (next->link != NULL)
	{
		prev = next;
		next = next->link;
	}
	if (prev == NULL)
		list = NULL;
	else
		prev->link = next->link;
}

void deleteMiddle(xb& list, int pos)
{
	if (pos == 1)
		deleteFront(list);
	else {
		xb temp = list;
		for (int i = 1; i <= pos - 2; i++) {
			temp = temp->link;
		}
		xb remove = temp->link;
		temp->link = remove->link;
		delete remove;
	}
}

void findData(xb current)
{
	bool flag;
	string ma;
	cout << "Nhap ma tuyen xe buyt can tim: ";
	cin >> ma;
	for (xb p = current; p != NULL; p = p->link)
	{
		if (p->xb.ma == ma)
			flag = true;
	}
	flag = false;

	if (flag == true)
		cout << "Tuyen " << ma << " co ton tai.";
	else
		cout << "Tuyen " << ma << " khong ton tai.";
}

void printThongTin(tuyenXeBuyt a)
{
	cout << "===================\n";
	cout << "ID: " << a.ma << endl;
	cout << "Ten: " << a.ten << endl;
	cout << "Diem dau: " << a.diemDau << endl;
	cout << "Diem cuoi: " << a.diemCuoi << endl;
	cout << "Cu ly: " << a.cuLy;
	cout << "\n===================\n";
}

void printDS(xb a) {
	cout << "Danh sach tuyen xe buyt:\n";

	while (a != NULL)
	{
		printThongTin(a->xb);
		a = a->link;
	}
	cout << endl;

}

void sapXep(xb& list) {
	for (xb p = list; p->link != NULL; p = p->link) {
		xb min = p;
		for (xb q = p->link; q != NULL; q = q->link) {
			if (q->xb.cuLy < min->xb.cuLy)
				min = q;
		}
		tuyenXeBuyt temp = min->xb;
		min->xb = p->xb;
		p->xb = temp;
	}
}

int menu()
{
	int luaChon;
	xb head = NULL;

	do
	{
		cout << "\n0. Thoat.";
		cout << "\n1. Nhap gia tri.";
		cout << "\n2. Them gia tri tai vi tri bat ky.";
		cout << "\n3. Print tuyen xe buyt.";
		cout << "\n4. Tim kiem ma tuyen.";
		cout << "\n5. Xoa 1 tuyen tai vi tri.";
		cout << "\n6. Sap xep cu ly tang dan.";
		cout << "\n\t Chon tai day: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 0:
			exit(0);
		case 1:
			insertLast(head);
			break;
		case 2:
			int value, pos;
			cout << "Nhap vi tri: "; cin >> pos;
			insertTaiViTri(head, pos);
			break;
		case 3:
			printDS(head);
			break;
		case 4:
			findData(head);
			break;
		case 5:
			int viTri;
			cout << "Nhap vi tri can xoa: ";
			cin >> viTri;
			deleteMiddle(head, viTri);
			break;
		case 6:
			sapXep(head);
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