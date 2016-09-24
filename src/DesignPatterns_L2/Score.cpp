#include "Score.h"
#include <fstream>
using namespace std;
using namespace l2::common;

mutex Score::initLock_;
std::shared_ptr<Score> Score::instance_(nullptr);

std::shared_ptr<Score> Score::getInstance() {
	if (!instance_)
	{
		std::lock_guard<std::mutex> lock(initLock_);
		if (!instance_)
			instance_ = std::shared_ptr<Score>(new Score);
	}
	return instance_;
}

void Score::saveScore2File() {
	ofstream sf;
	sf.open("scores.txt", ios::app);
	sf << name_ << ", " << points_ << ".\n";
	sf.close();
}