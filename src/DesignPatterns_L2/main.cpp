#include <iostream>
#include "Frame.h"
#include "ConsoleWindow.h"
#include "ColorizedDrawable.h"

#include "Sender.h"
#include "Receiver.h"
#include "Register.h"


using namespace std;
using namespace l2::sys;
using namespace l2::rendering;

const uint16_t wh = 10;
string testData = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

class TestReceiver : public Receiver<char>
{
public:
	TestReceiver() : Receiver<char>() { }
	TestReceiver(const TestReceiver & right) = delete;
    ~TestReceiver() { }
	void HandleMessage(const std::shared_ptr<char> & message) { cout << *message << endl; }
};

const uint64_t TestType = 1;


int main(int argc, char ** argv)
{

	if(argc && argv)
		printf("Hello World!\rTest\n");

	Sender<char> * snd(new Sender<char>);
	TestReceiver * rcv(new TestReceiver);
	Register<char> reg;

	reg.RegisterSender(TestType, snd);
	reg.RegisterReceiver(TestType, rcv);

	shared_ptr<char> msg(new char('X'));

	shared_ptr<ConsoleWindow> wnd(new ConsoleWindow(false));
	ColorizedDrawable drw(wnd);

	//drw.SetDrawableSpace(0, 0, wh, wh);
	//drw.SetDrawableData(testData);
	//drw.SetColor(Colorizer::Black, Colorizer::White);

	//drw.Draw();

	for (uint16_t i = 0; i < 15; ++i)
	{
		snd->BroadcastMessage(msg);

		Sleep(1000);
	}

    reg.UnregisterSender(snd);
    reg.UnregisterReceiver(rcv);

    delete snd;
    delete rcv;

	system("pause");
	return 0;
}