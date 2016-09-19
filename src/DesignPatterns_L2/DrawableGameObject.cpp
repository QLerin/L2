#include "DrawableGameObject.h"

using namespace std;
using namespace l2::gameobjects;
using namespace l2r;

DrawableGameObject::DrawableGameObject(const DrawableGameObject & right) :
	IGameObject(right.objectName_), 
	IDrawable(right.parentWindow_)
{
}
DrawableGameObject::DrawableGameObject(const IDrawable & drawable, const IGameObject & gameobject) :
	IDrawable(drawable), IGameObject(gameobject)
{
}