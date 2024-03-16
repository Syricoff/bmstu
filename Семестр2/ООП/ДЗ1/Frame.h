#ifndef FRAME
#define FRAME

#include <string>

class Frame
{
public:
	Frame();
	Frame(std::string data, Frame* linkedFrame);

	std::string getData();
	Frame* getLinkedFrame();

	void setData(std::string data);
	void setLinkedFrame(Frame* linkedFrame);

private:
	std::string data;
	Frame* linkedFrame;
};

#endif // !FRAME