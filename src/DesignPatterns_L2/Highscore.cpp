#include "Highscore.h"

using namespace std;
using namespace l2::common;

HighScore * HighScore::instance_(new HighScore);

HighScore::HighScore(){
	if (!Load())
	{
#pragma message ("LOG ME")
	}
}

HighScore :: ~HighScore() {
	if (!Save())
	{
#pragma message ("LOG ME2")
	}
}

