#pragma once
#include "Player.h"

namespace l2
{

	namespace gameobjects
	{
		class Medkit
		{
			int scorePenalty;
			int healSize;
			rendering::ColorizedDrawable model_;
		public:
			Medkit() :  scorePenalty(0), healSize(0), model_(nullptr) {}
			Medkit(int hS, int sP, rendering::ColorizedDrawable model) :  scorePenalty(sP), healSize(hS), model_(nullptr)
			{
				scorePenalty = sP;
				healSize = hS;
				model_ = model;
			}

			void Use(Player player);
			void SetScorePenalty(int sP)
			{
				scorePenalty = sP;
			};
			void SetHealSize(int hS)
			{
				healSize = hS;
			}

			int GetHealSize()
			{
				return healSize;
			}

			int GetScorePenalty()
			{
				return scorePenalty;
			}

			void setModel (rendering::ColorizedDrawable mod)
			{
				model_ = mod;
			}

		};
	}
}

