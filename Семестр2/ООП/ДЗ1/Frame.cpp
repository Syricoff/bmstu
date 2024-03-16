#include <string>
#include "Frame.h"

Frame::Frame() : data{ "" }, linkedFrame{ nullptr } {}

Frame::Frame(std::string data, Frame* linkedFrame) : data{ data }, linkedFrame{ linkedFrame } {}

std::string Frame::getData() { return data; }

Frame* Frame::getLinkedFrame() { return linkedFrame; }

void Frame::setData(std::string data) { this->data = data; }

void Frame::setLinkedFrame(Frame* linkedFrame) { this->linkedFrame = linkedFrame; }