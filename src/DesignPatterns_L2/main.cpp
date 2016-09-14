#include <iostream>
#include "Frame.h"

using namespace l2::rendering;

int main(int argc, char ** argv)
{
	if(argc && argv)
		printf("Hello World!\rTest\n");

	Frame frm(100, 40);
	frm.Display();

	system("pause");
	return 0;
}