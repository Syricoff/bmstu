#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack stack = Stack();
	stack.pushFrame();
	stack.pushFrame();
	std::cout << stack.popFrame() << std::endl;
	stack.pushFrame();
	stack.deleteFrame();
	stack.addAfter();
	cout << "Stack:" << endl;
	stack.display();
	Queue queue = Queue();
	queue.pushFrame();
	queue.pushFrame();
	std::cout << queue.popFrame() << std::endl;
	queue.pushFrame();
	queue.deleteFrame();
	queue.addAfter();
	queue.pushFrame();
	cout << "Queue:" << endl;
	queue.display();
}