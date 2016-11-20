#pragma once
#include <string>
#include <mutex>
#include <memory>
#include <windows.h>


namespace l2
{

	namespace common
	{

		class Score {
			Score() = default;
			Score(const Score & right) : points_(right.points_) { }

			std::mutex scoreLock_;
			long points_;

		public:
			static Score & getInstance();

			void setPoints(const int p) {
				std::lock_guard<std::mutex> lock(scoreLock_);
				points_ = p;
			}

			void changePoints(int change) {
				std::lock_guard<std::mutex> lock(scoreLock_);
				points_ += change;
			}

			void saveScore2File(const std::string & name);

			const int getPoints() {
				return points_;
			}

		};



	}

}

