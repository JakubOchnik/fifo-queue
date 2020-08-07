#include <iostream>
#include "headers.h"

const int len = 5;
int tab[len] = { 7,6,5,4,3 };

int main() {
	Queue x;
	Queue y = { 6,5,4,3,2 };
	Queue z(tab, len);
	x.push(1);
	x.push(2);
	std::cout << x.size() << " " << y.size() << " " << z.size() << std::endl;
	std::cout << x.pop() << " " << y.pop() << " " << z.pop() << std::endl;
	std::cout << x.size() << " " << y.size() << " " << z.size() << std::endl;

	std::cout << y;
	y.push(41);
	std::cout << y;
	y.pop();
	std::cout << y;
	y[0] = 1;
	std::cout << y;
	return 0;
}