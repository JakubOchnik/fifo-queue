#pragma once
#include"node.h"
#include<iostream>
#include <initializer_list>
#include <string>
#include <vector>

class Queue {
private:
	int n;
	Node* first;
	Node* last;

	void add(int num);
	int remove();
	void init();
public:
	Queue();
	Queue(std::initializer_list<int> list);
	Queue(int tab[], int len);
	Queue(std::vector<int> vec);
	
	void push(int num);
	int pop();

	int &operator[](int i);
	friend std::ostream& operator<<(std::ostream& out, const Queue& q);

	const int size() const;

	~Queue();
};
