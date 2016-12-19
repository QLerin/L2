#pragma once

#include "UnselectableSUIComponent.h"

namespace l2
{

	namespace gameobjects
	{

		class ProgressBar : public UnselectabeSUIComponent
		{
		private:
			void CalculateCells();
		protected:
			uint16_t cells_;
			uint16_t unitsPerCell_;
			uint16_t currentAmmount_;
			uint16_t maxAmmount_;

			uint16_t height_;
		public:
			ProgressBar();
			ProgressBar(const uint16_t maxAmmount);
			
			void IncrementBar(const uint16_t ammount);
			void DecrementBar(const uint16_t ammount);

			void SetProgressAt(const uint16_t ammount);

			void SetMaxAmmount(const uint16_t maxAmmount);
			void SetHeight(const uint16_t height);
			void SetUnitsPerCell(const uint16_t unitsPerCell);

		};

	}

}