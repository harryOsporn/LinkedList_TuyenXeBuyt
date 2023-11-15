#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* link;
	int value;
};
typedef class Node* node;

node makeNode(int data);
void insertFirst(node& main, int a);

void insertLast(node& main, int value);

void pushFront(node& main, int value);

void import(node & main);

int size(node& main);

void printOutcome(node a);

void insertTaiViTri(node& list, int value, int pos);

void deleteFront(node& list);

void deleteLast(node& list);

void loadData(node& current);
bool findData(node current, int x);

void deleteMiddle(node& list, int pos);

void sapXep(node& list);

int menu();