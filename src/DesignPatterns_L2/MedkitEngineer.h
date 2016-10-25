#pragma once
#include "MedkitBuilder.h"
namespace l2
{

	namespace common
	{
		class MedkitEngineer
		{
			MedkitBuilder * builder;

		public:
			void setBuilder(MedkitBuilder* newBuilder)
			{
				builder = newBuilder;
			}

			gameobjects::Medkit getKit()
			{
				builder->setHP();
				builder->setModel();
				builder->setSP();
				gameobjects::Medkit medkit = builder->getMedkit();
				return medkit;
			}
		};
	}
}
