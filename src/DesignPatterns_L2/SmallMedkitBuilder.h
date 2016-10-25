#pragma once
#include "MedkitBuilder.h"
namespace l2
{

	namespace common
	{

		class SmallMedkitBuilder : public MedkitBuilder
		{
			gameobjects::Medkit med;
		public:
			SmallMedkitBuilder() : MedkitBuilder() {}
			void setHP() override{
				med.SetHealSize(10);
			};
			void setSP() override{
				med.SetScorePenalty(20);
			}

			void setModel() override {
				rendering::ColorizedDrawable model(nullptr);
				model.SetDrawableData("aavavaava");
				model.SetDrawableSpace(0, 0, 3, 3);
			}

			gameobjects::Medkit getMedkit() override {
				LOG_INFO("Small medkit built");
				return med;
			}
		};
	}
}
