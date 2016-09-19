#pragma once
#include <string>

namespace l2
{

	namespace common
	{

		class Scores {
		protected:
			int points_;
			std::string name_;
		public:
			Scores() : points_(0), name_("") {}
			Scores(const Scores & right) : points_(right.points_), name_(right.name_) {}
			Scores(int points, std::string name) : points_(points), name_(name) {}
			void setPoints(const int p) {
				points_ = p;
			}
			void setName(const std::string & n) {
				name_ = n;
			}
			const int getPoints() {
				return points_;
			}
			const std::string & getName() {
				return name_;
			}
		};

	}

}