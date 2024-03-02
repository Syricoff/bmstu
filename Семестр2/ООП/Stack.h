#ifndef STACK
#define STACK

#include "Frame.h"

class Stack
{
  public:
    Stack();
    ~Stack();

    void pushFrame();
    Frame *popFrame();
    Frame *peekFrame();
    void display();
    bool isEmpty();
    void deleteFrame();
    void addAfter();

  private:
    Frame *lastFrame;
};

#endif // !STACK
