#include "Geometry.h"

float
Rect::Left() const
{
	return center.x - w;
};

float
Rect::Top() const
{
	return center.y - h;
};

float
Rect::Right() const
{
	return center.x + w;
};

float
Rect::Bottom() const
{
	return center.y + h;
};

float
Rect::Whide() const
{
	return center.x / 2;
};

float
Rect::Hight() const
{
	return center.y / 2;
};

