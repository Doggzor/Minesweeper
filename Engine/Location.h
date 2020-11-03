#pragma once
struct Location
{
	Location() = default;
	Location(int x, int y)
		:
		x(x),
		y(y)
	{}
	Location operator+ (const Location& other) const
	{
		return { x + other.x, y + other.y };
	}
	Location& operator+= (const Location& other)
	{
		*this = *this + other;
	}
	Location operator- (const Location& other) const
	{
		return { x - other.x, y - other.y };
	}
	Location& operator-= (const Location& other)
	{
		*this = *this - other;
	}
	Location operator*(int number) const
	{
		return { x * number, y * number };
	}
	Location& operator*= (int number)
	{
		*this = *this * number;
	}
	Location operator/(int number) const
	{
		return { x / number, y / number };
	}
	Location& operator/= (int number)
	{
		*this = *this / number;
	}

	int x, y;
};
