
#include "Board.h"

Board::Board(const Difficulty& difficulty, Graphics& gfx)
	:
	diff(difficulty)
{
	switch (diff)
	{
	case Difficulty::Easy:
		nColumns = 10;
		nRows = 8;
		nMines = 10;
		break;
	case Difficulty::Medium:
		nColumns = 20;
		nRows = 16;
		nMines = 50;
		break;
	case Difficulty::Hard:
		nColumns = 30;
		nRows = 24;
		nMines = 150;
		break;
	case Difficulty::VeryHard:
		nColumns = 40;
		nRows = 32;
		nMines = 300;
		break;
	}
	topleft = gfx.Center() - (Location(nColumns, nRows) / 2) * Tile::size;

	//Create tiles
	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nColumns; x++) tile.push_back(std::make_unique <Tile>(Location(x, y), topleft));
	}
	//Spawn mines
	for (int i = 0; i < nMines; i++)
	{
		Location spawnloc;
		do spawnloc = { rng::rdm_int(0, nColumns - 1), rng::rdm_int(0, nRows - 1) };
		while (tile[GetIndex(spawnloc)]->bHasMine);
		tile[GetIndex(spawnloc)]->bHasMine = true;
	}
	//Count neighbor mines
	for (int i = 0; i < tile.size(); i++) tile[i]->nNeighborMines = CountNeighborMines(i);
}

void Board::Draw(Graphics& gfx)
{
	for (int i = 0; i < tile.size(); i++) tile[i]->Draw(topleft, gfx);
}

void Board::Update(Mouse& mouse)
{
	pointer = { mouse.GetPosX(), mouse.GetPosY() };
	for (int i = 0; i < tile.size(); i++)
	{
		tile[i]->Update(pointer);
		if (tile[i]->bHovered)
		{
			if (mouse.LeftIsPressed() && !bLMB_inhibited) tile[i]->Reveal();
			if (mouse.RightIsPressed() && !bRMB_inhibited) tile[i]->ToggleFlag();
		}
	}

	bLMB_inhibited = mouse.LeftIsPressed();
	bRMB_inhibited = mouse.RightIsPressed();
}

int Board::GetIndex(const Location& gridLoc)
{
	return gridLoc.y * nColumns + gridLoc.x;
}

int Board::CountNeighborMines(int tileIndex)
{
	const int startX = std::max(0, tile[tileIndex]->gridLoc.x - 1);
	const int endX = std::min(nColumns - 1, tile[tileIndex]->gridLoc.x + 1);
	const int startY = std::max(0, tile[tileIndex]->gridLoc.y - 1);
	const int endY = std::min(nRows - 1, tile[tileIndex]->gridLoc.y + 1);

	int nMines = 0;

	for (int y = startY; y <= endY; y++)
	{
		for (int x = startX; x <= endX; x++) if (tile[GetIndex({ x, y })]->bHasMine) nMines++;
	}

	return nMines;
}

Board::Tile::Tile(const Location& gridLoc, const Location& board_topleft)
	:
	gridLoc(gridLoc)
{
	rect = { board_topleft + gridLoc * size, size, size };
}

void Board::Tile::Draw(const Location& topleft, Graphics& gfx)
{
	const Location screenLoc = topleft + gridLoc * size;
	switch (state)
	{
	case State::Hidden:
		if (bHovered) img::tile_hidden_hovered(screenLoc, gfx);
		else img::tile_hidden(screenLoc, gfx);
		break;
	case State::Flagged:
		if (bHovered) img::tile_flagged_hovered(screenLoc, gfx);
		else img::tile_flagged(screenLoc, gfx);
		break;
	case State::Revealed:
		if (bHasMine) img::tile_mine_triggered(screenLoc, gfx);
		else if (nNeighborMines == 0) img::tile_empty(screenLoc, gfx);
		else if (nNeighborMines == 1) img::tile_num1(screenLoc, gfx);
		else if (nNeighborMines == 2) img::tile_num2(screenLoc, gfx);
		else if (nNeighborMines == 3) img::tile_num3(screenLoc, gfx);
		else if (nNeighborMines == 4) img::tile_num4(screenLoc, gfx);
		else if (nNeighborMines == 5) img::tile_num5(screenLoc, gfx);
		else if (nNeighborMines == 6) img::tile_num6(screenLoc, gfx);
		else if (nNeighborMines == 7) img::tile_num7(screenLoc, gfx);
		else  img::tile_num8(screenLoc, gfx);
		break;
	}
}

void Board::Tile::Reveal()
{
	if (state == State::Hidden) state = State::Revealed;
}

void Board::Tile::ToggleFlag()
{
	if (state == State::Hidden) state = State::Flagged;
	else if (state == State::Flagged) state = State::Hidden;
}

void Board::Tile::Update(const Location& pointer)
{
	bHovered = rect.isContaining(pointer);
}
