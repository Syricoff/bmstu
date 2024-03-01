#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack stack = Stack();
	stack.pushFrame();
	stack.pushFrame();
	stack.pushFrame();
	cout << "Stack:" << endl;
	stack.display();
	Queue queue = Queue();
	queue.pushFrame();
	queue.pushFrame();
	queue.pushFrame();
	cout << "Queue:" << endl;
	queue.display();
}