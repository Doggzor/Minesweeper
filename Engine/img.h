#pragma once
#include "Graphics.h"
#include "Loc.h"
class img
{
public:
	static void tile_empty(const Loc& topleft, Graphics& gfx);
	static void tile_flagged(const Loc& topleft, Graphics& gfx);
	static void tile_hidden(const Loc& topleft, Graphics& gfx);
	static void tile_mine_false(const Loc& topleft, Graphics& gfx);
	static void tile_mine_revealed(const Loc& topleft, Graphics& gfx);
	static void tile_mine_triggered(const Loc& topleft, Graphics& gfx);
	static void tile_num1(const Loc& topleft, Graphics& gfx);
	static void tile_num2(const Loc& topleft, Graphics& gfx);
	static void tile_num3(const Loc& topleft, Graphics& gfx);
	static void tile_num4(const Loc& topleft, Graphics& gfx);
	static void tile_num5(const Loc& topleft, Graphics& gfx);
	static void tile_num6(const Loc& topleft, Graphics& gfx);
	static void tile_num7(const Loc& topleft, Graphics& gfx);
	static void tile_num8(const Loc& topleft, Graphics& gfx);
};

