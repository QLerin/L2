#pragma once
#include "MedkitBuilder.h"
namespace l2
{

	namespace common
	{

		class MediumMedkitBuilder : public MedkitBuilder
		{
			gameobjects::Medkit med;
		public:
			MediumMedkitBuilder() : MedkitBuilder() {}
			void setHP() override {
				med.SetHealSize(25);
			};
			void setSP() override {
				med.SetScorePenalty(50);
			}

			void setModel() override {
				rendering::ColorizedDrawable model(nullptr);
				model.SetDrawableData("oavazasva");
				model.SetDrawableSpace(0, 0, 3, 3);
			}
			gameobjects::Medkit getMedkit() override {
				LOG_INFO("Medium medkit built");
				return med;
			}
		};
	}
}
