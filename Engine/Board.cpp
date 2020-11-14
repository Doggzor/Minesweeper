
#include "Board.h"

Board::Board(int columns, int rows, int mines, Graphics& gfx)
	:
	nColumns(columns),
	nRows(rows),
	nMines(mines)
{
	topleft = gfx.Center() - (Location(nColumns, nRows) / 2) * Tile::size + Location(-nBorderThickness, 25 - nBorderThickness);

	//Create tiles
	for (int y = 0; y < nRows; y++)
	{
		for (int x = 0; x < nColumns; x++) {
			tile.push_back(std::make_unique <Tile>(Location(x, y), topleft));
		}
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
	const Rect ClockRect = { {GetRect().right - 64 - nBorderThickness, GetRect().top - 25 - nBorderThickness * 3 / 2}, 64 + nBorderThickness, 25 + nBorderThickness };
	for (int i = 0; i < tile.size(); i++) tile[i]->Draw(bGameOver, topleft, gfx);
	gfx.DrawRectEmpty(GetRect().left, GetRect().top, GetRect().right - GetRect().left, GetRect().bottom - GetRect().top, -nBorderThickness, { 48, 48, 48 }); //Border
	gfx.DrawRect(GetRect().left - nBorderThickness, GetRect().top - nBorderThickness * 2 - 25, GetRect().right + nBorderThickness, GetRect().top, { 48, 48, 48 }); //Top Border extra
	gfx.DrawRectDim(ClockRect.left, ClockRect.top, ClockRect.GetWidth(), ClockRect.GetHeight(), Colors::Black);
	numb.DrawClock(ClockRect.left + nBorderThickness / 2, ClockRect.top + nBorderThickness / 2, fElapsedTime, Colors::Red, gfx);

	const Location mine_icon_topleft = { GetRect().left, GetRect().top - 25 - nBorderThickness };
	img::mine_icon(mine_icon_topleft, gfx);
	Rect MineCountRect;
	if (nMines >= 100)
	{
		MineCountRect = { {GetRect().left + 27, GetRect().top - 25 - nBorderThickness * 3 / 2}, 43 + nBorderThickness, 25 + nBorderThickness };
		gfx.DrawRectDim(MineCountRect.left, MineCountRect.top, MineCountRect.GetWidth(), MineCountRect.GetHeight(), Colors::Black);
		numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 888, Colors::Red * 0.3f, gfx);
		if (nMines - nFlaggedTiles >= 100)
		{
			if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			else numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
		}
		else if (nMines - nFlaggedTiles >= 10)
		{
			numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			else numb.Draw(MineCountRect.left + nBorderThickness / 2 + 15, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
		}
		else
		{
			numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			numb.Draw(MineCountRect.left + nBorderThickness / 2 + 15, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			else numb.Draw(MineCountRect.left + nBorderThickness / 2 + 30, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
		}
	}
	else if (nMines >= 10)
	{
		MineCountRect = { {GetRect().left + 27, GetRect().top - 25 - nBorderThickness * 3 / 2}, 28 + nBorderThickness, 25 + nBorderThickness };
		gfx.DrawRectDim(MineCountRect.left, MineCountRect.top, MineCountRect.GetWidth(), MineCountRect.GetHeight(), Colors::Black);
		numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 88, Colors::Red * 0.3f, gfx);
		if (nMines - nFlaggedTiles >= 10)
		{
			if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			else numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
		}
		else
		{
			numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
			else numb.Draw(MineCountRect.left + nBorderThickness / 2 + 15, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
		}
	}
	else
	{
		MineCountRect = { {GetRect().left + 27, GetRect().top - 25 - nBorderThickness * 3 / 2}, 13 + nBorderThickness, 25 + nBorderThickness };
		gfx.DrawRectDim(MineCountRect.left, MineCountRect.top, MineCountRect.GetWidth(), MineCountRect.GetHeight(), Colors::Black);
		numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 8, Colors::Red * 0.3f, gfx);
		if (bGameWon) numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, 0, Colors::Red, gfx);
		else numb.Draw(MineCountRect.left + nBorderThickness / 2, MineCountRect.top + nBorderThickness / 2, std::max(0, nMines - nFlaggedTiles), Colors::Red, gfx);
	}

	const Location smiley_topleft = { MineCountRect.right + (ClockRect.left - MineCountRect.right) / 2 - 12, GetRect().top - 25 - nBorderThickness };
	if (!bGameOver)
	{
		if (bShockSmiley) img::smiley_shock(smiley_topleft, gfx);
		else img::smiley_smile(smiley_topleft, gfx);
	}
	else if (bGameLost) img::smiley_dead(smiley_topleft, gfx);
	else img::smiley_cool(smiley_topleft, gfx);
}

void Board::Update(Mouse& mouse)
{
	if (!bReady && !mouse.LeftIsPressed()) bReady = true;
	else if (bReady)
	{
		const float dt = ft.Mark();
		bGameOver = bGameWon || bGameLost;
		if (nRevealedTiles == tile.size() - nMines) bGameWon = true;
		if (!bGameOver)
		{
			if (bStartClock) fElapsedTime += dt;
			bShockSmiley = fSmileyShockTimer > 0;
			if (fSmileyShockTimer > 0) fSmileyShockTimer -= dt;
			for (int i = 0; i < tile.size(); i++)
			{
				tile[i]->Update(mouse);
				if (tile[i]->bHovered)
				{
					if (mouse.LeftIsPressed() && mouse.RightIsPressed())
					{
						if ((!bLMB_inhibited || !bRMB_inhibited) && tile[i]->state == Tile::State::Revealed && CountNeighborMines(i) == CountNeighborFlags(i) && CountNeighborMines(i) != 0) RevealNeighborTiles(i);
						else PressNeighborTiles(i);
					}
					else if (mouse.LeftIsPressed() && !bLMB_inhibited && tile[i]->state == Tile::State::Hidden)
					{
						RevealTile(i);
						if (!bStartClock) bStartClock = true;
					}
					else if (mouse.RightIsPressed() && !bRMB_inhibited) ToggleFlagTile(i);
				}
				if (tile[i]->state == Tile::State::Hidden && bGameWon) tile[i]->state = Tile::State::Flagged;
			}
		}

		bLMB_inhibited = mouse.LeftIsPressed();
		bRMB_inhibited = mouse.RightIsPressed();
	}
}

bool Board::isGameOver()
{
	return bGameOver;
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

int Board::CountNeighborFlags(int tileIndex)
{
	const int startX = std::max(0, tile[tileIndex]->gridLoc.x - 1);
	const int endX = std::min(nColumns - 1, tile[tileIndex]->gridLoc.x + 1);
	const int startY = std::max(0, tile[tileIndex]->gridLoc.y - 1);
	const int endY = std::min(nRows - 1, tile[tileIndex]->gridLoc.y + 1);

	int nFlags = 0;

	for (int y = startY; y <= endY; y++)
	{
		for (int x = startX; x <= endX; x++) if (tile[GetIndex({ x, y })]->state == Tile::State::Flagged) nFlags++;
	}

	return nFlags;
}

void Board::RevealTile(int tileIndex)
{
	tile[tileIndex]->Reveal();
	nRevealedTiles++;
	if (tile[tileIndex]->nNeighborMines == 0) RevealNeighborTiles(tileIndex);
	if (tile[tileIndex]->bHasMine) bGameLost = true;
	ShockSmiley();;
}

void Board::ToggleFlagTile(int tileIndex)
{
	tile[tileIndex]->ToggleFlag();
	if (tile[tileIndex]->state == Tile::State::Flagged) nFlaggedTiles++;
	else if (tile[tileIndex]->state == Tile::State::Hidden) nFlaggedTiles--;
}

void Board::RevealNeighborTiles(int tileIndex)
{
	const int startX = std::max(0, tile[tileIndex]->gridLoc.x - 1);
	const int endX = std::min(nColumns - 1, tile[tileIndex]->gridLoc.x + 1);
	const int startY = std::max(0, tile[tileIndex]->gridLoc.y - 1);
	const int endY = std::min(nRows - 1, tile[tileIndex]->gridLoc.y + 1);

	for (int y = startY; y <= endY; y++)
	{
		for (int x = startX; x <= endX; x++)
		{
			if(tile[GetIndex({ x, y })]->state == Tile::State::Hidden) RevealTile(GetIndex({ x, y }));
		}
	}
}

void Board::PressNeighborTiles(int tileIndex)
{
	const int startX = std::max(0, tile[tileIndex]->gridLoc.x - 1);
	const int endX = std::min(nColumns - 1, tile[tileIndex]->gridLoc.x + 1);
	const int startY = std::max(0, tile[tileIndex]->gridLoc.y - 1);
	const int endY = std::min(nRows - 1, tile[tileIndex]->gridLoc.y + 1);

	for (int i = 0; i < tile.size(); i++) tile[i]->bPressed = false;
	for (int y = startY; y <= endY; y++)
	{
		for (int x = startX; x <= endX; x++)
		{
			if (tile[GetIndex({ x, y })]->state == Tile::State::Hidden)
			{
				tile[GetIndex({ x, y })]->bPressed = true;
				ShockSmiley();
			}
		}
	}
}

void Board::ShockSmiley()
{
	fSmileyShockTimer = 0.225f;
}

const Rect Board::GetRect() const
{
	return Rect(topleft, nColumns * Tile::size, nRows * Tile::size);
}

Board::Tile::Tile(const Location& gridLoc, const Location& board_topleft)
	:
	gridLoc(gridLoc)
{
	rect = { board_topleft + gridLoc * size, size, size };
}

void Board::Tile::Draw(bool GameOver, const Location& topleft, Graphics& gfx)
{
	const Location screenLoc = topleft + gridLoc * size;
	switch (state)
	{
	case State::Hidden:
		if (GameOver && bHasMine) img::tile_mine_revealed(screenLoc, gfx);
		else if (bPressed) img::tile_empty(screenLoc, gfx);
		else if (bHovered) img::tile_hidden_hovered(screenLoc, gfx);
		else img::tile_hidden(screenLoc, gfx);
		break;
	case State::Flagged:
		if (GameOver && !bHasMine) img::tile_mine_false(screenLoc, gfx);
		else if (bHovered) img::tile_flagged_hovered(screenLoc, gfx);
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

void Board::Tile::Update(Mouse& mouse)
{
	bHovered = rect.isContaining(mouse.GetPos());
	if (!mouse.LeftIsPressed() || !mouse.RightIsPressed()) bPressed = false;
}
