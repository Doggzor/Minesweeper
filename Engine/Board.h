#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Mouse.h"
#include "rng.h"
#include "img.h"
#include "Rect.h"
#include "FrameTimer.h"
#include "Numbers.h"
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

		void Draw(bool GameOver, const Location& topleft, Graphics& gfx);
		void Reveal();
		void ToggleFlag();
		void Update(Mouse& mouse);
		State state = State::Hidden;
		Location gridLoc;
		Rect rect;
		bool bHasMine = false;
		bool bHovered = false;
		bool bPressed = false;
		int nNeighborMines = 0;
		int nNeighborFlags = 0;

		static constexpr int size = 16;
	};

public:
	Board(const Difficulty& difficulty, Graphics& gfx);

	void Draw(Graphics& gfx);
	void Update(Mouse& mouse);
private:
	int GetIndex(const Location& gridLoc);
	int CountNeighborMines(int tileIndex);
	int CountNeighborFlags(int tileIndex);
	void RevealTile(int tileIndex);
	void ToggleFlagTile(int tileIndex);
	void RevealNeighborTiles(int tileIndex);
	void PressNeighborTiles(int tileIndex);
	void ShockSmiley();
	const Rect GetRect() const;
private:
	FrameTimer ft;
	Numbers numb;
	Difficulty diff = Difficulty::Medium;
	Location topleft;
	std::vector< std::unique_ptr < Tile > > tile;
	int nColumns = 0;
	int nRows = 0;
	int nMines = 0;
	int nRevealedTiles = 0;
	int nFlaggedTiles = 0;
	static constexpr int nBorderThickness = 8;
	bool bLMB_inhibited = false;
	bool bRMB_inhibited = false;
	bool bShockSmiley = false;
	float fSmileyShockTimer = 0;
	bool bGameWon = false;
	bool bGameLost = false;
	bool bGameOver = false;
	float fElapsedTime = 0;
	bool bStartClock = false;
};

