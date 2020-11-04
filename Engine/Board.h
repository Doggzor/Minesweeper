#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Mouse.h"
#include "rng.h"
#include "img.h"
#include "Rect.h"
#include <memory>
class Board
{
public:
	enum class Difficulty
	{
		Easy,
		Medium,
		Hard,
		VeryHard
	};

private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};

		Tile() = default;
		Tile(const Location& gridLoc, const Location& board_topleft);

		void Draw(const Location& topleft, Graphics& gfx);
		void Reveal();
		void ToggleFlag();
		void Update(const Location& pointer);
		State state = State::Hidden;
		Location gridLoc;
		Rect rect;
		bool bHasMine = false;
		bool bHovered = false;
		int nNeighborMines = 0;
		int nNeighborFlags = 0;

		static constexpr int size = 16;
	};

public:
	Board(const Difficulty& difficulty, Graphics& gfx);

	void Draw(Graphics& gfx);
	void Update(Mouse& mouse, const Location& pointer);
private:
	int GetIndex(const Location& gridLoc);
	int CountNeighborMines(int tileIndex);
	int CountNeighborFlags(int tileIndex);
	void RevealTile(int tileIndex);
	void RevealNeighborTiles(int tileIndex);
private:
	Difficulty diff = Difficulty::Medium;
	Location topleft;
	std::vector< std::unique_ptr < Tile > > tile;
	int nColumns = 0;
	int nRows = 0;
	int nMines = 0;
	bool bLMB_inhibited = false;
	bool bRMB_inhibited = false;
};

