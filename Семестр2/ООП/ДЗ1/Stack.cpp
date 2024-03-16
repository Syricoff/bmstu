#include "Stack.h"
#include <iostream>
#include <string>

Stack::Stack() : lastFrame{nullptr}
{
}

Stack::~Stack()
{
    if (lastFrame == nullptr)
    {
        return;
    }
    Frame *currFrame = lastFrame;
    while (currFrame->getLinkedFrame() != nullptr)
    {
        Frame *nextFrame = currFrame->getLinkedFrame();
        delete currFrame;
        currFrame = nextFrame;
    }
    delete currFrame;
}

void Stack::pushFrame()
{
    std::cout << "Enter frame data: ";
    std::string data;
    std::cin >> data;
    Frame *newFrame = new Frame(data, lastFrame);
    lastFrame = newFrame;
}

void Stack::addAfter() {
  if (lastFrame == nullptr) {
    std::cout << "Error: accessing empty stack." << std::endl;
    return;
  }

  std::string afterData;
  std::cout << "Enter frame data: ";
  std::cin >> afterData;

  Frame* prev = nullptr;
  Frame* curr = lastFrame;
  while (curr != nullptr) {
    if (curr->getData() == afterData) {

      std::cout << "Enter data after " << afterData << ": ";
      std::string newData;
      std::cin >> newData;

      Frame* newFrame = new Frame(newData, curr->getLinkedFrame());
      curr->setLinkedFrame(newFrame);
      return;
    }
    prev = curr;
    curr = curr->getLinkedFrame();
  }
  std::cout << "Error: element not found." << std::endl;
}

Frame *Stack::popFrame()
{
    if (lastFrame == nullptr)
    {
        std::cout << "Error: accessing empty stack." << std::endl;
        return nullptr;
    }
    Frame *returnFrame = lastFrame;
    lastFrame = lastFrame->getLinkedFrame();
    return returnFrame;
}

Frame *Stack::peekFrame()
{
    if (lastFrame == nullptr)
    {
        std::cout << "Error: accessing empty stack." << std::endl;
    }
    return lastFrame;
}

void Stack::display()
{
    if (lastFrame == nullptr)
    {
        std::cout << "Error: accessing empty stack." << std::endl;
        return;
    }
    Frame *currFrame = lastFrame;
    int index = 0;
    while (currFrame->getLinkedFrame() != nullptr)
    {
        std::cout << "Frame " << index++ << ": " << currFrame->getData() << std::endl;
        currFrame = currFrame->getLinkedFrame();
    }
    std::cout << "Frame " << index << ": " << currFrame->getData() << std::endl;
}

void Stack::deleteFrame()
{
    if (lastFrame == nullptr)
    {
        std::cout << "Error: accessing empty stack." << std::endl;
        return;
    }
    std::cout << "Enter frame data: ";
    std::string data;
    std::cin >> data;

    Frame *prev = nullptr;
    Frame *curr = lastFrame;
    while (curr != nullptr)
    {
        if (curr->getData() == data)
        {
            if (prev == nullptr)
            {
                lastFrame = curr->getLinkedFrame();
            }
            else
            {
                prev->setLinkedFrame(curr->getLinkedFrame());
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getLinkedFrame();
    }
    std::cout << "Error: element not found." << std::endl;
}

bool Stack::isEmpty()
{
    if (lastFrame == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
