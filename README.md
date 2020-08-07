# Object-oriented FIFO queue
A object-oriented implementation of a FIFO queue. The goal was to train object oriented programming in C++.
## Features
* Multiple constructors (empty, initalizer list, array as an argument)
* Overloaded output stream operator (printing out the whole queue)
```
Queue x = {6,5,4,3}
cout << x;

*Last -> First*
*[6, 5, 4, 3]*
```