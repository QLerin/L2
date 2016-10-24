#pragma once

#include "Frame.h"
#include <string>

namespace l2
{

	namespace gameobjects
	{

		class IGameObject
		{
		private:
			IGameObject() = delete;
		protected:
			std::string objectName_;
			IGameObject(const IGameObject & right) : objectName_(right.objectName_) { }
			IGameObject(const std::string & name) : objectName_(name) { }
		public:
			virtual ~IGameObject()
			{
			}

			const std::string & GetObjectName() { return objectName_; }
		};

	}

}