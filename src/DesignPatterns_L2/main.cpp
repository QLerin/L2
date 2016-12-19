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
#include "InputHandler.h"

#include "UsableFactory.h"
#include "CommonFactory.h"
#include "RareFactory.h"

#include "Executor.h"
#include "EnemyBoss.h"
#include "BossAdapter.h"
#include "Caretaker.h"


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

//class TestInputHandler : public InputHandler
//{
//public:
//    void HandleMessage(const std::shared_ptr<Message> & message)
//    {
//        if(message)
//            printf(message.get()->GetMessageString().c_str());
//    }
//};
//
//void PrintLife(const LifeStatistics & in)
//{
//    cout << "Health is: " << in.GetHealth() << " | Energy is: " << in.GetEnergy() << endl;
//}
//
//void PrintTertiary(const TertiaryStatistics & in)
//{
//    cout << "Strength is: " << in.GetStrength() << " | Agility is: " << in.GetAgility() << " | Intellect is: " << in.GetIntellect() << endl;
//}

void FunkcijaLinui();
void FunkcijaLukui();

#pragma warning (push)
#pragma warning (disable : 4702) // While still in development disable warning for unreachable code
                                 // MUST REMOVE ON RELEASE!
int main()
{
    //FunkcijaLinui();
    FunkcijaLukui();

	return 0;
}
#pragma warning (pop)

#pragma warning (push)
#pragma warning (disable : 4101 4189) // Lino funkcija (nuff said)
void FunkcijaLinui()
{
	Logger::GetInstance()->Initialize("L2.log");
	LOG_INFO("Test start");
    EnemyFactory fac;
    Enemy *a = fac.CreateEnemy("archer");
    Enemy *b = fac.CreateEnemy("swordsman");
    Enemy *c = fac.CreateEnemy("mage");
	Enemy *d = fac.CreateEnemy("error2000");
	EnemyBoss *g = new EnemyBoss("Lukas");
	Enemy *ga = new BossAdapter(g);
	
	//ga.setBoss(g);
	if(d->isNull())
	{
		LOG_INFO("Null enemy created in main");
	}
	Player *Stanislovas = new Player("Stanislovas");

	Caretaker *care = new Caretaker(Stanislovas);
	Stanislovas->saveStateToMemento(*care);
	
	b->Attack(static_cast <Player*>(Stanislovas));
	LOG_INFO(std::to_string(b->getEnemyHealth()));
	Stanislovas->Attack(b);
	Stanislovas->setAcc(30);
	Stanislovas->saveStateToMemento(*care);
	

	Stanislovas->Attack(ga);
	ga->Attack(static_cast <Player*>(Stanislovas));
	LOG_INFO(std::to_string(ga->getEnemyHealth()));
	LOG_INFO(std::to_string(Stanislovas->getCharacterStatistics()->GetLife().GetHealth()));
	Stanislovas->saveStateToMemento(*care);

	Stanislovas->Attack(ga);
	ga->Attack(static_cast <Player*>(Stanislovas));
	LOG_INFO(std::to_string(ga->getEnemyHealth()));
	LOG_INFO(std::to_string(Stanislovas->getCharacterStatistics()->GetLife().GetHealth()));
	Stanislovas->restoreStateFromMemento(*care);
	LOG_INFO(std::to_string(Stanislovas->getCharacterStatistics()->GetLife().GetHealth()));



	
}
#pragma warning (pop)

void FunkcijaLukui()
{
    //Test for input handling ----------------------------------------

    //TestInputHandler a;
    //TestInputHandler b;
    //InputManager a2;
    //Register<Message> test;
    //test.RegisterReceiver(1, &a);
    //test.RegisterReceiver(1, &b);

    //a2.GetInstance()->StartPolling(test);

    //while (1)
    //{
    //    Sleep(1000);
    //}

    //Test for input handling -------------------------------------------



    // Test for items --------------------------------------------------

    //CharacterStatistics stats(LifeStatistics(500, 500), TertiaryStatistics(50, 50, 50));

    //UsableFactory * fac = new CommonFactory();

    //Gem * s = fac->CreateGem();
    //PrintTertiary(s->GetUsableStatistics());
    //delete s;
    //delete fac;
    //fac = new RareFactory();
    //s = fac->CreateGem();
    //PrintTertiary(s->GetUsableStatistics());
    //delete fac;

    //cout << "-----------------Testing statistics application----------------" << endl;
    //cout << "Before application:" << endl;
    //PrintTertiary(stats.GetTertiary());
    //s->UseItem(stats);
    //cout << "After application:" << endl;
    //PrintTertiary(stats.GetTertiary());
    //delete s;

    // Test for items --------------------------------------------------

    ////////Sender<char> * snd(new Sender<char>);
    ////////TestReceiver * rcv(new TestReceiver);
    ////////Register<char> reg;

    ////////reg.RegisterSender(TestType, snd);
    ////////reg.RegisterReceiver(TestType, rcv);

    ////////shared_ptr<char> msg(new char('X'));

    ////////shared_ptr<ConsoleWindow> wnd(new ConsoleWindow(false));
    ////////   StartMenu menu(wnd);
    ////////ColorizedDrawable drw(wnd);

    ////////drw.SetDrawableSpace(0, 0, wh, wh);
    ////////drw.SetDrawableData(testData);
    ////////drw.SetColor(Colorizer::Black, Colorizer::White);

    //drw.Draw();

    //StartMenu men(wnd);
    //men.Draw();

    //////////for (uint16_t i = 0; i < 15; ++i)
    //////////{
    //////////	snd->BroadcastMessage(msg);
    //////////    menu.Draw();
    //////////    wnd->SwapBuffers();

    //////////    if (i % 2 == 0)
    //////////        menu.Next();
    //////////    else
    //////////        menu.Previous();

    //////////	Sleep(1000);
    //////////}

    //////////   reg.UnregisterSender(snd);
    //////////   reg.UnregisterReceiver(rcv);

    //////////   delete snd;
    //////////   delete rcv;

       //if (!Logger::GetInstance()->IsInitialized())
       //    return -1;

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

    Logger::GetInstance()->Initialize("ExecutorTest.log");
    if (!Logger::GetInstance()->IsInitialized())
        MessageBoxA(NULL, "Logger not initialized", "ERROR", MB_ICONEXCLAMATION);
    Executor().Run();
}