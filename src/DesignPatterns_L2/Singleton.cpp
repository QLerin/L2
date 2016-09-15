#include "Singleton.h"

using namespace std;
using namespace l2::sys;

template <typename T>
shared_ptr<T> Singleton<T>::GetInstance()
{
	if (!instance_)
		instance_ = make_shared<T>(new T);
	return instance_;
}