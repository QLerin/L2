#pragma once

#include "Points.h"
#include <vector>
#include <memory>

//Test
namespace l2 {
	namespace common {
		class HighScore {
		private:
			HighScore();
			~HighScore();
			std::vector <Scores> highscores_;
			const bool Load() { return false; }
			const bool Save() { return false; }

			static HighScore * instance_;
		public:
			void addNewScore(Scores s) {
				highscores_.push_back(s);
			}
			
			HighScore * GetInstance() { return instance_; }
		};
	}
}