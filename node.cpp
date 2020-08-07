#include"node.h"
Node::Node() {
	this->value = 0;
	this->next = nullptr;
	this->prev = nullptr;
}
Node::Node(int val) {
	this->value = val;
	this->next = nullptr;
	this->prev = nullptr;
}

Node* Node::setAndGetNext() {
	this->next = new Node();
	return this->next;
}

void Node::setVal(int val) {
	this->value = val;
}

void Node::setNext(Node* nextNode) {
	this->next = nextNode;
}

void Node::setNextNull() {
	this->next = nullptr;
}

void Node::setPrev(Node* prevNode) {
	this->prev = prevNode;
}

Node* Node::getPrev() {
	return this->prev;
}

Node* Node::getNext() {
	return this->next;
}

int& Node::getValRef() {
	int& val = this->value;
	return val;
}

int Node::getVal() {
	return value;
}