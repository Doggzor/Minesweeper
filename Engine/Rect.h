#pragma once
#include "Location.h"

struct Rect
{
	Rect() = default;
	Rect(const Location& loc, int width, int height)
	{
		left = loc.x;
		right = loc.x + width;
		top = loc.y;
		bottom = loc.y + height;
	}
	bool isContaining(const Location& point)
	{
		return point.x > left && point.x < right&& point.y > top && point.y < bottom;
	}
	const int GetWidth() const
	{
		return right - left;
	}
	const int GetHeight() const
	{
		return bottom - top;
	}
	int left, right, top, bottom;
};
