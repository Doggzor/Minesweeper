#pragma once
#include "Graphics.h"
#include "Location.h"
class img
{
public:
	static void tile_empty(const Location& topleft, Graphics& gfx);
	static void tile_flagged(const Location& topleft, Graphics& gfx);
	static void tile_flagged_hovered(const Location& topleft, Graphics& gfx);
	static void tile_hidden(const Location& topleft, Graphics& gfx);
	static void tile_hidden_hovered(const Location& topleft, Graphics& gfx);
	static void tile_mine_false(const Location& topleft, Graphics& gfx);
	static void tile_mine_revealed(const Location& topleft, Graphics& gfx);
	static void tile_mine_triggered(const Location& topleft, Graphics& gfx);
	static void tile_num1(const Location& topleft, Graphics& gfx);
	static void tile_num2(const Location& topleft, Graphics& gfx);
	static void tile_num3(const Location& topleft, Graphics& gfx);
	static void tile_num4(const Location& topleft, Graphics& gfx);
	static void tile_num5(const Location& topleft, Graphics& gfx);
	static void tile_num6(const Location& topleft, Graphics& gfx);
	static void tile_num7(const Location& topleft, Graphics& gfx);
	static void tile_num8(const Location& topleft, Graphics& gfx);
	static void smiley_smile(const Location& topleft, Graphics& gfx);
	static void smiley_shock(const Location& topleft, Graphics& gfx);
	static void smiley_dead(const Location& topleft, Graphics& gfx);
	static void smiley_cool(const Location& topleft, Graphics& gfx);
	static void mine_icon(const Location& topleft, Graphics& gfx);
};

