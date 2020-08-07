#include"headers.h"

void Queue::init() {
	this->first = new Node();
	this->last = this->first;
}

Queue::Queue() {
	init();
	this->n = 0;
}

Queue::Queue(std::initializer_list<int> list): n(list.size()){
	init();
	Node* element = first;
	unsigned int i = 0;
	for (int num : list) {
		element->setVal(num);
		if (i != n - 1) {
			Node* newElement = element->setAndGetNext();
			newElement->setPrev(element);
			element = newElement;
		}
		i++;
	}
	this->last = element;
}
Queue::Queue(int tab[], int len): n(len) {
	init();
	Node* element = first;
	for (int i = 0; i < n; i++) {
		element->setVal(tab[i]);
		if (i != n - 1) {
			Node* newElement = element->setAndGetNext();
			newElement->setPrev(element);
			element = newElement;
		}
	}
	this->last = element;
}

Queue::Queue(std::vector<int> vec): n(vec.size()) {
	init();
	Node* element = first;
	unsigned int i = 0;
	for (int num : vec) {
		element->setVal(num);
		if (i != n - 1) {
			Node* newElement = element->setAndGetNext();
			newElement->setPrev(element);
			element = newElement;
		}
		i++;
	}
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
		if(currentNode->getNext()!=nullptr)
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