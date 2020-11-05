#include "Numbers.h"


void Numbers::Draw(int x, int y, int num, Color c, Graphics& gfx) const
{
	int offsetneg = 0;
	int offsetcomma = 0;
	int offset0 = 0;
	int offset1 = 0;
	int offset2 = 0;
	int offset3 = 0;
	int offset4 = 0;
	int number = num;
	if (num < 0)
	{
		draw_minus(x, y + 11, c, gfx);
		offsetneg = 12;
		number = abs(num);
	}
	int numberO = 0;
	int numberT = 0;
	int numberH = 0;
	int numberTH = 0;
	int numberTTH = 0;
	int numberHTH = 0;
	const int numberM = 1000000;
	while (numberM <= number) number -= numberM;
	if (number >= 10)
	{
		offset0 = 15;
		if (number >= 100)
		{
			offset1 = 15;
			if (number >= 1000)
			{
				offset2 = 15;
				if (number >= 10000)
				{
					offset3 = 15;
					if (number >= 100000)
					{
						offset4 = 15;
					}
				}
			}
		}
	}
	if (number >= 1000)
	{
		draw_comma(offsetneg + x + offset2 + offset3 + offset4, y + 22, c, gfx);
		offsetcomma = 6;
	}
	for (int nHTH = 100000; nHTH <= number; ++numberHTH) number -= 100000;
	for (int nTTH = 10000; nTTH <= number; ++numberTTH) number -= 10000;
	for (int nTH = 1000; nTH <= number; ++numberTH) number -= 1000;
	for (int nH = 100; nH <= number; ++numberH) number -= 100;
	for (int nT = 10; nT <= number; ++numberT) number -= 10;
	for (int nO = 0; nO < number; ++numberO) --number;

	if (numberO == 0)
		drawnum0(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 1)
		drawnum1(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 2)
		drawnum2(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 3)
		drawnum3(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 4)
		drawnum4(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 5)
		drawnum5(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 6)
		drawnum6(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 7)
		drawnum7(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 8)
		drawnum8(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);
	else if (numberO == 9)
		drawnum9(offsetneg + x + offsetcomma + offset0 + offset1 + offset2 + offset3 + offset4, y, c,  gfx);

	if (numberT == 0 && (numberH > 0 || numberTH > 0 || numberTTH > 0 || numberHTH > 0))
		drawnum0(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 1)
		drawnum1(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 2)
		drawnum2(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 3)
		drawnum3(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 4)
		drawnum4(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 5)
		drawnum5(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 6)
		drawnum6(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 7)
		drawnum7(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 8)
		drawnum8(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberT == 9)
		drawnum9(offsetneg + x + offsetcomma + offset1 + offset2 + offset3 + offset4, y, c,  gfx);

	if (numberH == 0 && (numberTH > 0 || numberTTH > 0 || numberHTH >0))
		drawnum0(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 1)
		drawnum1(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 2)
		drawnum2(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 3)
		drawnum3(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 4)
		drawnum4(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 5)
		drawnum5(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 6)
		drawnum6(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 7)
		drawnum7(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 8)
		drawnum8(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c, gfx);
	else if (numberH == 9)
		drawnum9(offsetneg + x + offsetcomma + offset2 + offset3 + offset4, y, c,  gfx);

	if (numberTH == 0 && (numberTTH > 0 || numberHTH > 0))
		drawnum0(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 1)
		drawnum1(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 2)
		drawnum2(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 3)
		drawnum3(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 4)
		drawnum4(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 5)
		drawnum5(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 6)
		drawnum6(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 7)
		drawnum7(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 8)
		drawnum8(offsetneg + x + offset3 + offset4, y, c, gfx);
	else if (numberTH == 9)
		drawnum9(offsetneg + x + offset3 + offset4, y, c, gfx);

	if (numberTTH == 0 && numberHTH > 0)
		drawnum0(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 1)
		drawnum1(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 2)
		drawnum2(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 3)
		drawnum3(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 4)
		drawnum4(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 5)
		drawnum5(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 6)
		drawnum6(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 7)
		drawnum7(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 8)
		drawnum8(offsetneg + x + offset4, y, c, gfx);
	else if (numberTTH == 9)
		drawnum9(offsetneg + x + offset4, y, c, gfx);

	if (numberHTH == 1)
		drawnum1(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 2)
		drawnum2(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 3)
		drawnum3(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 4)
		drawnum4(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 5)
		drawnum5(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 6)
		drawnum6(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 7)
		drawnum7(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 8)
		drawnum8(offsetneg + x, y, c,  gfx);
	else if (numberHTH == 9)
		drawnum9(offsetneg + x, y, c,  gfx);
}

void Numbers::DrawClock(int x, int y, float time, Color c, Graphics& gfx) const
{
	const int offset_numb = 15;
	const int offset_doubledot = 6;
	int minutes = (int)time / 60;
	int seconds;
	if (minutes < 100) seconds = (int)time % 60;
	else seconds = 59;

	if (minutes >= 99) minutes = 99;

	const Color PaleBase = c * 0.3f;
	Draw(x, y, 88, PaleBase, gfx);
	Draw(x + offset_numb * 2 + offset_doubledot, y, 88, PaleBase, gfx);
	if (minutes < 10)
	{
		drawnum0(x, y, c, gfx);
		Draw(x + offset_numb, y, minutes, c, gfx);
	}
	else Draw(x, y, minutes, c, gfx);

	draw_doubledot(x + offset_numb * 2, y, c, gfx);

	if (seconds < 10)
	{
		drawnum0(x + offset_numb * 2 + offset_doubledot, y, c, gfx);
		Draw(x + offset_numb * 3 + offset_doubledot, y, seconds, c, gfx);
	}
	else Draw(x + offset_numb * 2 + offset_doubledot, y, seconds, c, gfx);
}

void Numbers::drawnum0(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(1 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(0 + x, 14 + y,   c);
	gfx.PutPixel(1 + x, 14 + y,   c);
	gfx.PutPixel(2 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(0 + x, 15 + y,   c);
	gfx.PutPixel(1 + x, 15 + y,   c);
	gfx.PutPixel(2 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(0 + x, 16 + y,   c);
	gfx.PutPixel(1 + x, 16 + y,   c);
	gfx.PutPixel(2 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(0 + x, 17 + y,   c);
	gfx.PutPixel(1 + x, 17 + y,   c);
	gfx.PutPixel(2 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(0 + x, 18 + y,   c);
	gfx.PutPixel(1 + x, 18 + y,   c);
	gfx.PutPixel(2 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(0 + x, 19 + y,   c);
	gfx.PutPixel(1 + x, 19 + y,   c);
	gfx.PutPixel(2 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(0 + x, 20 + y,   c);
	gfx.PutPixel(1 + x, 20 + y,   c);
	gfx.PutPixel(2 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(0 + x, 21 + y,   c);
	gfx.PutPixel(1 + x, 21 + y,   c);
	gfx.PutPixel(2 + x, 21 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(0 + x, 22 + y,   c);
	gfx.PutPixel(1 + x, 22 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(0 + x, 23 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum1(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);

}

void Numbers::drawnum2(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(1 + x, 13 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(0 + x, 14 + y,   c);
	gfx.PutPixel(1 + x, 14 + y,   c);
	gfx.PutPixel(2 + x, 14 + y,   c);
	gfx.PutPixel(0 + x, 15 + y,   c);
	gfx.PutPixel(1 + x, 15 + y,   c);
	gfx.PutPixel(2 + x, 15 + y,   c);
	gfx.PutPixel(0 + x, 16 + y,   c);
	gfx.PutPixel(1 + x, 16 + y,   c);
	gfx.PutPixel(2 + x, 16 + y,   c);
	gfx.PutPixel(0 + x, 17 + y,   c);
	gfx.PutPixel(1 + x, 17 + y,   c);
	gfx.PutPixel(2 + x, 17 + y,   c);
	gfx.PutPixel(0 + x, 18 + y,   c);
	gfx.PutPixel(1 + x, 18 + y,   c);
	gfx.PutPixel(2 + x, 18 + y,   c);
	gfx.PutPixel(0 + x, 19 + y,   c);
	gfx.PutPixel(1 + x, 19 + y,   c);
	gfx.PutPixel(2 + x, 19 + y,   c);
	gfx.PutPixel(0 + x, 20 + y,   c);
	gfx.PutPixel(1 + x, 20 + y,   c);
	gfx.PutPixel(2 + x, 20 + y,   c);
	gfx.PutPixel(0 + x, 21 + y,   c);
	gfx.PutPixel(1 + x, 21 + y,   c);
	gfx.PutPixel(2 + x, 21 + y,   c);
	gfx.PutPixel(0 + x, 22 + y,   c);
	gfx.PutPixel(1 + x, 22 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(0 + x, 23 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum3(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum4(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);

}

void Numbers::drawnum5(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum6(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(1 + x, 13 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(0 + x, 14 + y,   c);
	gfx.PutPixel(1 + x, 14 + y,   c);
	gfx.PutPixel(2 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(0 + x, 15 + y,   c);
	gfx.PutPixel(1 + x, 15 + y,   c);
	gfx.PutPixel(2 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(0 + x, 16 + y,   c);
	gfx.PutPixel(1 + x, 16 + y,   c);
	gfx.PutPixel(2 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(0 + x, 17 + y,   c);
	gfx.PutPixel(1 + x, 17 + y,   c);
	gfx.PutPixel(2 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(0 + x, 18 + y,   c);
	gfx.PutPixel(1 + x, 18 + y,   c);
	gfx.PutPixel(2 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(0 + x, 19 + y,   c);
	gfx.PutPixel(1 + x, 19 + y,   c);
	gfx.PutPixel(2 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(0 + x, 20 + y,   c);
	gfx.PutPixel(1 + x, 20 + y,   c);
	gfx.PutPixel(2 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(0 + x, 21 + y,   c);
	gfx.PutPixel(1 + x, 21 + y,   c);
	gfx.PutPixel(2 + x, 21 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(0 + x, 22 + y,   c);
	gfx.PutPixel(1 + x, 22 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(0 + x, 23 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum7(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);

}

void Numbers::drawnum8(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(1 + x, 13 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(0 + x, 14 + y,   c);
	gfx.PutPixel(1 + x, 14 + y,   c);
	gfx.PutPixel(2 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(0 + x, 15 + y,   c);
	gfx.PutPixel(1 + x, 15 + y,   c);
	gfx.PutPixel(2 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(0 + x, 16 + y,   c);
	gfx.PutPixel(1 + x, 16 + y,   c);
	gfx.PutPixel(2 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(0 + x, 17 + y,   c);
	gfx.PutPixel(1 + x, 17 + y,   c);
	gfx.PutPixel(2 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(0 + x, 18 + y,   c);
	gfx.PutPixel(1 + x, 18 + y,   c);
	gfx.PutPixel(2 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(0 + x, 19 + y,   c);
	gfx.PutPixel(1 + x, 19 + y,   c);
	gfx.PutPixel(2 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(0 + x, 20 + y,   c);
	gfx.PutPixel(1 + x, 20 + y,   c);
	gfx.PutPixel(2 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(0 + x, 21 + y,   c);
	gfx.PutPixel(1 + x, 21 + y,   c);
	gfx.PutPixel(2 + x, 21 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(0 + x, 22 + y,   c);
	gfx.PutPixel(1 + x, 22 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(0 + x, 23 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::drawnum9(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(8 + x, 0 + y,   c);
	gfx.PutPixel(9 + x, 0 + y,   c);
	gfx.PutPixel(10 + x, 0 + y,   c);
	gfx.PutPixel(11 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(9 + x, 1 + y,   c);
	gfx.PutPixel(10 + x, 1 + y,   c);
	gfx.PutPixel(12 + x, 1 + y,   c);
	gfx.PutPixel(0 + x, 2 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);
	gfx.PutPixel(8 + x, 2 + y,   c);
	gfx.PutPixel(9 + x, 2 + y,   c);
	gfx.PutPixel(11 + x, 2 + y,   c);
	gfx.PutPixel(12 + x, 2 + y,   c);
	gfx.PutPixel(0 + x, 3 + y,   c);
	gfx.PutPixel(1 + x, 3 + y,   c);
	gfx.PutPixel(2 + x, 3 + y,   c);
	gfx.PutPixel(10 + x, 3 + y,   c);
	gfx.PutPixel(11 + x, 3 + y,   c);
	gfx.PutPixel(12 + x, 3 + y,   c);
	gfx.PutPixel(0 + x, 4 + y,   c);
	gfx.PutPixel(1 + x, 4 + y,   c);
	gfx.PutPixel(2 + x, 4 + y,   c);
	gfx.PutPixel(10 + x, 4 + y,   c);
	gfx.PutPixel(11 + x, 4 + y,   c);
	gfx.PutPixel(12 + x, 4 + y,   c);
	gfx.PutPixel(0 + x, 5 + y,   c);
	gfx.PutPixel(1 + x, 5 + y,   c);
	gfx.PutPixel(2 + x, 5 + y,   c);
	gfx.PutPixel(10 + x, 5 + y,   c);
	gfx.PutPixel(11 + x, 5 + y,   c);
	gfx.PutPixel(12 + x, 5 + y,   c);
	gfx.PutPixel(0 + x, 6 + y,   c);
	gfx.PutPixel(1 + x, 6 + y,   c);
	gfx.PutPixel(2 + x, 6 + y,   c);
	gfx.PutPixel(10 + x, 6 + y,   c);
	gfx.PutPixel(11 + x, 6 + y,   c);
	gfx.PutPixel(12 + x, 6 + y,   c);
	gfx.PutPixel(0 + x, 7 + y,   c);
	gfx.PutPixel(1 + x, 7 + y,   c);
	gfx.PutPixel(2 + x, 7 + y,   c);
	gfx.PutPixel(10 + x, 7 + y,   c);
	gfx.PutPixel(11 + x, 7 + y,   c);
	gfx.PutPixel(12 + x, 7 + y,   c);
	gfx.PutPixel(0 + x, 8 + y,   c);
	gfx.PutPixel(1 + x, 8 + y,   c);
	gfx.PutPixel(2 + x, 8 + y,   c);
	gfx.PutPixel(10 + x, 8 + y,   c);
	gfx.PutPixel(11 + x, 8 + y,   c);
	gfx.PutPixel(12 + x, 8 + y,   c);
	gfx.PutPixel(0 + x, 9 + y,   c);
	gfx.PutPixel(1 + x, 9 + y,   c);
	gfx.PutPixel(2 + x, 9 + y,   c);
	gfx.PutPixel(10 + x, 9 + y,   c);
	gfx.PutPixel(11 + x, 9 + y,   c);
	gfx.PutPixel(12 + x, 9 + y,   c);
	gfx.PutPixel(0 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 10 + y,   c);
	gfx.PutPixel(2 + x, 10 + y,   c);
	gfx.PutPixel(10 + x, 10 + y,   c);
	gfx.PutPixel(11 + x, 10 + y,   c);
	gfx.PutPixel(12 + x, 10 + y,   c);
	gfx.PutPixel(1 + x, 11 + y,   c);
	gfx.PutPixel(3 + x, 11 + y,   c);
	gfx.PutPixel(4 + x, 11 + y,   c);
	gfx.PutPixel(5 + x, 11 + y,   c);
	gfx.PutPixel(6 + x, 11 + y,   c);
	gfx.PutPixel(7 + x, 11 + y,   c);
	gfx.PutPixel(8 + x, 11 + y,   c);
	gfx.PutPixel(9 + x, 11 + y,   c);
	gfx.PutPixel(11 + x, 11 + y,   c);
	gfx.PutPixel(2 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 12 + y,   c);
	gfx.PutPixel(4 + x, 12 + y,   c);
	gfx.PutPixel(5 + x, 12 + y,   c);
	gfx.PutPixel(6 + x, 12 + y,   c);
	gfx.PutPixel(7 + x, 12 + y,   c);
	gfx.PutPixel(8 + x, 12 + y,   c);
	gfx.PutPixel(9 + x, 12 + y,   c);
	gfx.PutPixel(10 + x, 12 + y,   c);
	gfx.PutPixel(3 + x, 13 + y,   c);
	gfx.PutPixel(4 + x, 13 + y,   c);
	gfx.PutPixel(5 + x, 13 + y,   c);
	gfx.PutPixel(6 + x, 13 + y,   c);
	gfx.PutPixel(7 + x, 13 + y,   c);
	gfx.PutPixel(8 + x, 13 + y,   c);
	gfx.PutPixel(9 + x, 13 + y,   c);
	gfx.PutPixel(11 + x, 13 + y,   c);
	gfx.PutPixel(10 + x, 14 + y,   c);
	gfx.PutPixel(11 + x, 14 + y,   c);
	gfx.PutPixel(12 + x, 14 + y,   c);
	gfx.PutPixel(10 + x, 15 + y,   c);
	gfx.PutPixel(11 + x, 15 + y,   c);
	gfx.PutPixel(12 + x, 15 + y,   c);
	gfx.PutPixel(10 + x, 16 + y,   c);
	gfx.PutPixel(11 + x, 16 + y,   c);
	gfx.PutPixel(12 + x, 16 + y,   c);
	gfx.PutPixel(10 + x, 17 + y,   c);
	gfx.PutPixel(11 + x, 17 + y,   c);
	gfx.PutPixel(12 + x, 17 + y,   c);
	gfx.PutPixel(10 + x, 18 + y,   c);
	gfx.PutPixel(11 + x, 18 + y,   c);
	gfx.PutPixel(12 + x, 18 + y,   c);
	gfx.PutPixel(10 + x, 19 + y,   c);
	gfx.PutPixel(11 + x, 19 + y,   c);
	gfx.PutPixel(12 + x, 19 + y,   c);
	gfx.PutPixel(10 + x, 20 + y,   c);
	gfx.PutPixel(11 + x, 20 + y,   c);
	gfx.PutPixel(12 + x, 20 + y,   c);
	gfx.PutPixel(10 + x, 21 + y,   c);
	gfx.PutPixel(11 + x, 21 + y,   c);
	gfx.PutPixel(12 + x, 21 + y,   c);
	gfx.PutPixel(3 + x, 22 + y,   c);
	gfx.PutPixel(4 + x, 22 + y,   c);
	gfx.PutPixel(5 + x, 22 + y,   c);
	gfx.PutPixel(6 + x, 22 + y,   c);
	gfx.PutPixel(7 + x, 22 + y,   c);
	gfx.PutPixel(8 + x, 22 + y,   c);
	gfx.PutPixel(9 + x, 22 + y,   c);
	gfx.PutPixel(11 + x, 22 + y,   c);
	gfx.PutPixel(12 + x, 22 + y,   c);
	gfx.PutPixel(2 + x, 23 + y,   c);
	gfx.PutPixel(3 + x, 23 + y,   c);
	gfx.PutPixel(4 + x, 23 + y,   c);
	gfx.PutPixel(5 + x, 23 + y,   c);
	gfx.PutPixel(6 + x, 23 + y,   c);
	gfx.PutPixel(7 + x, 23 + y,   c);
	gfx.PutPixel(8 + x, 23 + y,   c);
	gfx.PutPixel(9 + x, 23 + y,   c);
	gfx.PutPixel(10 + x, 23 + y,   c);
	gfx.PutPixel(12 + x, 23 + y,   c);
	gfx.PutPixel(1 + x, 24 + y,   c);
	gfx.PutPixel(2 + x, 24 + y,   c);
	gfx.PutPixel(3 + x, 24 + y,   c);
	gfx.PutPixel(4 + x, 24 + y,   c);
	gfx.PutPixel(5 + x, 24 + y,   c);
	gfx.PutPixel(6 + x, 24 + y,   c);
	gfx.PutPixel(7 + x, 24 + y,   c);
	gfx.PutPixel(8 + x, 24 + y,   c);
	gfx.PutPixel(9 + x, 24 + y,   c);
	gfx.PutPixel(10 + x, 24 + y,   c);
	gfx.PutPixel(11 + x, 24 + y,   c);

}

void Numbers::draw_minus(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(1 + x, 0 + y,   c);
	gfx.PutPixel(2 + x, 0 + y,   c);
	gfx.PutPixel(3 + x, 0 + y,   c);
	gfx.PutPixel(4 + x, 0 + y,   c);
	gfx.PutPixel(5 + x, 0 + y,   c);
	gfx.PutPixel(6 + x, 0 + y,   c);
	gfx.PutPixel(7 + x, 0 + y,   c);
	gfx.PutPixel(0 + x, 1 + y,   c);
	gfx.PutPixel(1 + x, 1 + y,   c);
	gfx.PutPixel(2 + x, 1 + y,   c);
	gfx.PutPixel(3 + x, 1 + y,   c);
	gfx.PutPixel(4 + x, 1 + y,   c);
	gfx.PutPixel(5 + x, 1 + y,   c);
	gfx.PutPixel(6 + x, 1 + y,   c);
	gfx.PutPixel(7 + x, 1 + y,   c);
	gfx.PutPixel(8 + x, 1 + y,   c);
	gfx.PutPixel(1 + x, 2 + y,   c);
	gfx.PutPixel(2 + x, 2 + y,   c);
	gfx.PutPixel(3 + x, 2 + y,   c);
	gfx.PutPixel(4 + x, 2 + y,   c);
	gfx.PutPixel(5 + x, 2 + y,   c);
	gfx.PutPixel(6 + x, 2 + y,   c);
	gfx.PutPixel(7 + x, 2 + y,   c);

}

void Numbers::draw_comma(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(0 + x, 0 + y, c);
	gfx.PutPixel(1 + x, 0 + y, c);
	gfx.PutPixel(2 + x, 0 + y, c);
	gfx.PutPixel(3 + x, 0 + y, c);
	gfx.PutPixel(0 + x, 1 + y, c);
	gfx.PutPixel(1 + x, 1 + y, c);
	gfx.PutPixel(2 + x, 1 + y, c);
	gfx.PutPixel(3 + x, 1 + y, c);
	gfx.PutPixel(0 + x, 2 + y, c);
	gfx.PutPixel(1 + x, 2 + y, c);
	gfx.PutPixel(2 + x, 2 + y, c);
	gfx.PutPixel(3 + x, 2 + y, c);
	gfx.PutPixel(1 + x, 3 + y, c);
	gfx.PutPixel(2 + x, 3 + y, c);
	gfx.PutPixel(3 + x, 3 + y, c);
	gfx.PutPixel(2 + x, 4 + y, c);
	gfx.PutPixel(3 + x, 4 + y, c);
	gfx.PutPixel(3 + x, 5 + y, c);
}

void Numbers::draw_doubledot(int x, int y, Color c, Graphics& gfx) const
{
	gfx.PutPixel(0 + x, 6 + y, c);
	gfx.PutPixel(1 + x, 6 + y, c);
	gfx.PutPixel(2 + x, 6 + y, c);
	gfx.PutPixel(3 + x, 6 + y, c);
	gfx.PutPixel(0 + x, 7 + y, c);
	gfx.PutPixel(1 + x, 7 + y, c);
	gfx.PutPixel(2 + x, 7 + y, c);
	gfx.PutPixel(3 + x, 7 + y, c);
	gfx.PutPixel(0 + x, 8 + y, c);
	gfx.PutPixel(1 + x, 8 + y, c);
	gfx.PutPixel(2 + x, 8 + y, c);
	gfx.PutPixel(3 + x, 8 + y, c);
	gfx.PutPixel(0 + x, 9 + y, c);
	gfx.PutPixel(1 + x, 9 + y, c);
	gfx.PutPixel(2 + x, 9 + y, c);
	gfx.PutPixel(3 + x, 9 + y, c);
	gfx.PutPixel(0 + x, 19 + y, c);
	gfx.PutPixel(1 + x, 19 + y, c);
	gfx.PutPixel(2 + x, 19 + y, c);
	gfx.PutPixel(3 + x, 19 + y, c);
	gfx.PutPixel(0 + x, 20 + y, c);
	gfx.PutPixel(1 + x, 20 + y, c);
	gfx.PutPixel(2 + x, 20 + y, c);
	gfx.PutPixel(3 + x, 20 + y, c);
	gfx.PutPixel(0 + x, 21 + y, c);
	gfx.PutPixel(1 + x, 21 + y, c);
	gfx.PutPixel(2 + x, 21 + y, c);
	gfx.PutPixel(3 + x, 21 + y, c);
	gfx.PutPixel(0 + x, 22 + y, c);
	gfx.PutPixel(1 + x, 22 + y, c);
	gfx.PutPixel(2 + x, 22 + y, c);
	gfx.PutPixel(3 + x, 22 + y, c);

}

