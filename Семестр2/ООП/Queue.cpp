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

bool Queue::isEmpty()
{
	if (firstFrame == nullptr) { return true; }
	else { return false; }
}
