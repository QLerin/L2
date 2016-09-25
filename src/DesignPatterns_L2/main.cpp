#include <iostream>
#include "Frame.h"
#include "ConsoleWindow.h"
#include "ColorizedDrawable.h"

#include "Sender.h"
#include "Receiver.h"
#include "Register.h"
#include "Logger.h"

#include "StartMenu.h"


using namespace std;
using namespace l2::sys;
using namespace l2::rendering;
using namespace l2::gameobjects;

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

	//Sender<char> * snd(new Sender<char>);
	//TestReceiver * rcv(new TestReceiver);
	//Register<char> reg;

	//reg.RegisterSender(TestType, snd);
	//reg.RegisterReceiver(TestType, rcv);

	//shared_ptr<char> msg(new char('X'));

	//shared_ptr<ConsoleWindow> wnd(new ConsoleWindow(false));
 //   StartMenu menu(wnd);
	////ColorizedDrawable drw(wnd);

	////drw.SetDrawableSpace(0, 0, wh, wh);
	////drw.SetDrawableData(testData);
	////drw.SetColor(Colorizer::Black, Colorizer::White);

	////drw.Draw();

	//for (uint16_t i = 0; i < 15; ++i)
	//{
	//	//snd->BroadcastMessage(msg);
 //       menu.Draw();
 //       wnd->SwapBuffers();

	//	Sleep(1000);
	//}

 //   //reg.UnregisterSender(snd);
 //   //reg.UnregisterReceiver(rcv);

 //   delete snd;
 //   delete rcv;

    Logger::GetInstance()->Initialize("Linalukage2.log");
    if (!Logger::GetInstance()->IsInitialized())
        return -1;

    LOG_ERROR("Test_ERROR");
    LOG_WARNING("Test_WARNING");
    LOG_INFO("Test_INFO");
    LOG_INFO("Something occured...");
    LOG_WARNING("I have a bad feeling about this...");
    LOG_ERROR("DEFCON 1");

    Logger::GetInstance()->Stop();

	system("pause");
	return 0;
}