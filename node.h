#pragma once
class Node {
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node();
	Node(int val);
	Node* setAndGetNext();
	void setVal(int val);
	void setNext(Node* nextNode);
	void setPrev(Node* prevNode);
	Node* getPrev();
	void setNextNull();
	Node* getNext();
	int getVal();
	int& getValRef();
};
