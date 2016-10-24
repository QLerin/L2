#include <iostream>
#include "Frame.h"
#include "ConsoleWindow.h"
#include "ColorizedDrawable.h"

#include "Sender.h"
#include "Receiver.h"
#include "Register.h"
#include "Logger.h"
#include "Score.h"

#include "StartMenu.h"
#include "EnemyFactory.h"
#include "Medkit.h"
#include "LargeMedkitBuilder.h"
#include "MedkitEngineer.h"
#include "MediumMedkitBuilder.h"
#include "SmallMedkitBuilder.h"


using namespace std;
using namespace l2::sys;
using namespace l2::rendering;
using namespace l2::common;
using namespace l2::gameobjects;

const uint16_t wh = 10;
string testData = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

class TestReceiver : public Receiver<char>
{
public:
	TestReceiver() : Receiver<char>() { }
	TestReceiver(const TestReceiver & right) = delete;
    ~TestReceiver() { }
	void HandleMessage(const std::shared_ptr<char> & message) 
    {
        if (message)
        {
            LOG_INFO("Handling message " + string(1, *message));
            cout << *message << endl;
        }
        else
            LOG_WARNING("Corrupt (null) message was received from sender");
    }
};

const uint64_t TestType = 1;

void testfun(const uint16_t threadid)
{
    for (uint16_t i = 0; i < 40; ++i)
        LOG_ERROR(("TEST_MESSAGE" + std::to_string(threadid)) + to_string(i));
}


int main(int argc, char ** argv)
{
	Logger::GetInstance()->Initialize("L.log");

	if(argc && argv)
		printf("Hello World!\rTest\n");
	EnemyFactory fac;
	Enemy *a = fac.CreateEnemy("archer"); 
	Enemy *b = fac.CreateEnemy("swordsman");
	Enemy *c = fac.CreateEnemy("mage");

	Score::getInstance().changePoints(-100);
	Score::getInstance().saveScore2File("Jonas");

	MedkitBuilder *a1 = new LargeMedkitBuilder();
	MedkitBuilder *a2 = new MediumMedkitBuilder();
	MedkitBuilder *a3 = new SmallMedkitBuilder();
	MedkitEngineer me;
	me.setBuilder(a1);
	Medkit m1 = me.getKit();
	me.setBuilder(a2);
	Medkit m2 = me.getKit();
	me.setBuilder(a3);
	Medkit m3 = me.getKit();


	Player player("Jonas");
	m1.Use(player);
	m2.Use(player);
	m3.Use(player);

	

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
	//	snd->BroadcastMessage(msg);
 //       //menu.Draw();
 //       //wnd->SwapBuffers();

	//	Sleep(1000);
	//}

 //   //reg.UnregisterSender(snd);
 //   //reg.UnregisterReceiver(rcv);

 //   delete snd;
 //   delete rcv;

 //   if (!Logger::GetInstance()->IsInitialized())
 //       return -1;

 //   //LOG_ERROR("Test_ERROR");
 //   //LOG_WARNING("Test_WARNING");
 //   //LOG_INFO("Test_INFO");
 //   //LOG_INFO("Something occured...");
 //   //LOG_WARNING("I have a bad feeling about this...");
 //   //LOG_ERROR("DEFCON 1");

 //   //for (uint16_t i = 0; i < 8; ++i)
 //   //    std::thread(testfun, i).detach();

 //   Sleep(30000);

 //   Logger::GetInstance()->Stop();

	return 0;
}