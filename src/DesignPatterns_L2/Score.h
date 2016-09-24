#pragma once
#include <string>
#include <mutex>
#include <memory>

namespace l2
{

	namespace common
	{

		class Score {
			friend std::shared_ptr<Score>;
		private:
			static std::mutex initLock_;

		protected:
			Score() = default;
			Score(const Score & right) : name_(right.name_), points_(right.points_) { }

			static std::shared_ptr<Score> instance_;

			int points_;
			std::string name_;

		public:
			static std::shared_ptr<Score> getInstance();


			void setPoints(const int p) {
				points_ = p;
			}
			void setName(const std::string & n) {
				name_ = n;
			}
			void changePoints(int change) {
				points_ += change;
			}
			void saveScore2File();

			const int getPoints() {
				return points_;
			}
			const std::string & getName() {
				return name_;
			}
		};



	}

}

