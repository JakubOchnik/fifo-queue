#include"headers.h"

void Queue::init() {
	this->n = 0;
	this->first = new Node();
	this->last = this->first;
}

Queue::Queue() {
	init();
}

Queue::Queue(std::initializer_list<int> list){
	init();
	Node* element = first;
	int i = 0;
	for (int num : list) {
		element->setVal(num);
		if (i != list.size() - 1) {
			Node* newElement = element->setAndGetNext();
			newElement->setPrev(element);
			element = newElement;
		}
		i++;
	}
	this->n = list.size();
	this->last = element;
}
Queue::Queue(int tab[], int len) {
	init();
	Node* element = first;
	int tabSize = len;
	for (int i = 0; i < tabSize; i++) {
		element->setVal(tab[i]);
		if (i != tabSize - 1) {
			Node* newElement = element->setAndGetNext();
			newElement->setPrev(element);
			element = newElement;
		}
	}
	this->n = len;
	this->last = element;
}

void Queue::add(int num) {
	if (n == 0) {
		this->first->setVal(num);
		this->first->setNextNull();
	}
	else {
		Node* newNode = new Node(num);
		newNode->setNext(first);
		first->setPrev(newNode);
		first = newNode;
	}
	this->n++;
}

int Queue::remove() {
	int val = last->getVal();
	last = this->last->getPrev();
	if (n != 0) {
		delete last->getNext();
		last->setNextNull();
	}
	else
		delete last;
	return val;
}

void Queue::push(int num) {
	this->add(num);
}

int Queue::pop() {
	if (n == 0) {
		return -1;
	}
	n--;
	return this->remove();
}

int& Queue::operator[](int i) {
	Node* currentNode = first;
	for (int j = 0; j < i; j++) {
		currentNode = currentNode->getNext();
	}
	return currentNode->getValRef();
}

const int Queue::size() const {
	return n;
}

std::ostream& operator<<(std::ostream& out, const Queue& q) {
	std::string output;
	output = "Last -> First\n";
	output += "[";
	Node* currentNode = q.first;
	while (currentNode->getNext() != nullptr) {
		output += std::to_string(currentNode->getVal());
		output += ", ";
		currentNode = currentNode->getNext();
	}
	if (q.size() != 0)
		output += std::to_string(currentNode->getVal());
	output += "]";
	out << output << std::endl;
	return out;
}

Queue::~Queue() {

}