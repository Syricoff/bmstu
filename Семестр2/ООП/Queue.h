#ifndef QUEUE
#define QUEUE

#include "Frame.h"

class Queue
{
public:
	Queue();
	~Queue();

	void pushFrame();
	Frame* popFrame();
	Frame* peekFrame();
	void display();
	bool isEmpty();

private:
	Frame* firstFrame;
	Frame* lastFrame;
};

#endif // !QUEUE