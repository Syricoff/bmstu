#include <iostream>
#include <string>
#include "Stack.h"

Stack::Stack() : lastFrame{ nullptr } {}

Stack::~Stack()
{
	if (lastFrame == nullptr) { return; }
	Frame* currFrame = lastFrame;
	while (currFrame->getLinkedFrame() != nullptr) {
		Frame* nextFrame = currFrame->getLinkedFrame();
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
	Frame* newFrame = new Frame(data, lastFrame);
	lastFrame = newFrame;
}

Frame* Stack::popFrame()
{
	if (lastFrame == nullptr) {
		std::cout << "Error: accessing empty stack." << std::endl;
		return nullptr;
	}
	Frame* returnFrame = lastFrame;
	lastFrame = lastFrame->getLinkedFrame();
	return returnFrame;
}

Frame* Stack::peekFrame()
{
	if (lastFrame == nullptr) { std::cout << "Error: accessing empty stack." << std::endl; }
	return lastFrame;
}

void Stack::display()
{
	if (lastFrame == nullptr) {
		std::cout << "Error: accessing empty stack." << std::endl;
		return;
	}
	Frame* currFrame = lastFrame;
	int index = 0;
	while (currFrame->getLinkedFrame() != nullptr) {
		std::cout << "Frame " << index++ << ": " << currFrame->getData() << std::endl;
		currFrame = currFrame->getLinkedFrame();
	}
	std::cout << "Frame " << index << ": " << currFrame->getData() << std::endl;
}

bool Stack::isEmpty()
{
	if (lastFrame == nullptr) { return true; }
	else { return false; }
}
