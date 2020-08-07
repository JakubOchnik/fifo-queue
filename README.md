# Object-oriented FIFO queue
An object-oriented implementation of a FIFO queue. The goal was to train object oriented programming in C++.
## Features
* Multiple constructors (zero-argument, initalizer list, array)
* Overloaded output stream << operator (printing out the whole queue)
```
Queue x = {6,5,4,3}
cout << x;

Last -> First
[6, 5, 4, 3]
```
* Overloaded subscript [] operator (modifying values of a particular queue element)
## Functions
```
queue.pop() // returns the oldest queue element (and removes it from a queue)
queue.push(number) // pushes a number to the beginning of a queue
queue.size() // returns a number of queue elements
```