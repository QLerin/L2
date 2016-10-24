#include "Score.h"
#include <fstream>
using namespace std;
using namespace l2::common;


Score & Score::getInstance() {
	
	static Score instance;
	return instance;
}

void Score::saveScore2File(const std::string & name) {
	ofstream sf;
	sf.open("scores.txt", ios::app);
	{
		lock_guard<mutex> lock(scoreLock_);
		sf << name << ", " << points_ << ".\n";
	}
	sf.close();
}