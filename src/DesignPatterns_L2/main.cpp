#include <iostream>
#include "Frame.h"
#include "ConsoleWindow.h"
#include "ColorizedDrawable.h"


using namespace std;
using namespace l2::rendering;

const uint16_t wh = 10;
string testData = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

int main(int argc, char ** argv)
{
	if(argc && argv)
		printf("Hello World!\rTest\n");

	shared_ptr<ConsoleWindow> wnd(new ConsoleWindow(false));
	ColorizedDrawable drw(wnd);

	drw.SetDrawableSpace(0, 0, wh, wh);
	drw.SetDrawableData(testData);
	drw.SetColor(Colorizer::Black, Colorizer::White);

	drw.Draw();

	for (uint16_t i = 0; i < 15; ++i)
	{
		wnd->SwapBuffers();

		Sleep(1000);
	}

	system("pause");
	return 0;
}