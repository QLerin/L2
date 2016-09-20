#pragma once

#include "Score.h"
#include <vector>
#include <memory>

//Test
namespace l2 {
	namespace common {
		class HighScore {
		private:
			HighScore();
			~HighScore();
			std::vector <Score> highscores_;
			const bool Load() { return false; }
			const bool Save() { return false; }

			static HighScore * instance_;
		public:
			void addNewScore(Score s) {
				highscores_.push_back(s);
			}

		

			HighScore * GetInstance() { return instance_; }
		};
	}
}