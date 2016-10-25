#pragma once
#include "MedkitBuilder.h"
namespace l2
{

	namespace common
	{

		class LargeMedkitBuilder : public MedkitBuilder
		{
			gameobjects::Medkit med;
		public:
			LargeMedkitBuilder() : MedkitBuilder() {}
			void setHP() override {
				med.SetHealSize(50);
			};
			void setSP() override {
				med.SetScorePenalty(100);
			}

			void setModel() override{
				rendering::ColorizedDrawable model(nullptr);
				model.SetDrawableData("aaaaaaaaa");
				model.SetDrawableSpace(0, 0, 3, 3);
			}

			gameobjects::Medkit getMedkit() override {
				LOG_INFO("Large medkit built");
				return med;
			}
		};
	}
}

