#include <iostream>
#include <string>
#include "Queue.h"

Queue::Queue() : firstFrame{ nullptr }, lastFrame{ nullptr } {}

Queue::~Queue()
{
	if (firstFrame == nullptr) { return; }
	Frame* currFrame = firstFrame;
	while (currFrame->getLinkedFrame() != nullptr) {
		Frame* nextFrame = currFrame->getLinkedFrame();
		delete currFrame;
		currFrame = nextFrame;
	}
	delete currFrame;
}

void Queue::pushFrame()
{
	std::cout << "Enter frame data: ";
	std::string data;
	std::cin >> data;
	Frame* newFrame = new Frame(data, nullptr);
	if (firstFrame == nullptr) {
		firstFrame = newFrame;
	}
	else {
		lastFrame->setLinkedFrame(newFrame);
	}
	lastFrame = newFrame;
}

void Queue::addAfter() {
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

Frame* Queue::popFrame()
{
	if (firstFrame == nullptr) {
		std::cout << "Error: accessing empty queue." << std::endl;
		return nullptr;
	}
	Frame* returnFrame = firstFrame;
	firstFrame = firstFrame->getLinkedFrame();
	return returnFrame;
}

Frame* Queue::peekFrame()
{
	if (firstFrame == nullptr) { std::cout << "Error: accessing empty queue." << std::endl; }
	return firstFrame;
}

void Queue::display()
{
	if (firstFrame == nullptr) {
		std::cout << "Error: accessing empty queue." << std::endl;
		return;
	}
	Frame* currFrame = firstFrame;
	int index = 0;
	while (currFrame->getLinkedFrame() != nullptr) {
		std::cout << "Frame " << index++ << ": " << currFrame->getData() << std::endl;
		currFrame = currFrame->getLinkedFrame();
	}
	std::cout << "Frame " << index << ": " << currFrame->getData() << std::endl;
}

void Queue::deleteFrame()
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

bool Queue::isEmpty()
{
	if (firstFrame == nullptr) { return true; }
	else { return false; }
}
