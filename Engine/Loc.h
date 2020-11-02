#pragma once
struct Loc
{
	Loc() = default;
	Loc(int x, int y)
		:
		x(x),
		y(y)
	{}

	int x, y;
};
