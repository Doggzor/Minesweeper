#include "Menu.h"

Menu::Button::Button(const Location& topleft)
{
	rect = { topleft, Menu::btn_width, Menu::btn_height };
}

void Menu::Button::Update(Mouse& mouse)
{
	if (rect.isContaining(mouse.GetPos()))
	{
		status = Status::Hovered;
		if (mouse.LeftIsPressed()) status = Status::Pressed;
	}
	else status = Status::Empty;
}

void Menu::Button::Draw(Graphics& gfx)
{
	img::button({ rect.left, rect.top }, isHovered(), gfx);
}

bool Menu::Button::isPressed() const
{
	return status == Status::Pressed;
}

bool Menu::Button::isHovered() const
{
	return status == Status::Hovered;
}

void Menu::Button::ResetStatus()
{
	status = Status::Empty;
}

const Location Menu::Button::getTopLeft() const
{
	return Location(rect.left, rect.top);
}

Menu::Menu(const Location& topleft)
	:
	topleft(topleft)
{
}

void Menu::Update(Mouse& mouse)
{
	if (!bCustomizing)
	{
		S->Update(mouse);
		M->Update(mouse);
		L->Update(mouse);
		XL->Update(mouse);
		Custom->Update(mouse);
		if (S->isPressed())
		{
			nColumns = 10;
			nRows = 8;
			nMines = 9;
		}
		else if (M->isPressed())
		{
			nColumns = 20;
			nRows = 16;
			nMines = 50;
		}
		else if (L->isPressed())
		{
			nColumns = 30;
			nRows = 24;
			nMines = 150;
		}
		else if (XL->isPressed())
		{
			nColumns = 40;
			nRows = 32;
			nMines = 300;
		}
		else if (Custom->isPressed()) bCustomizing = true;
	}
	else
	{
		Columns_Increase->Update(mouse);
		Columns_Decrease->Update(mouse);
		Rows_Increase->Update(mouse);
		Rows_Decrease->Update(mouse);
		Mines_Increase->Update(mouse);
		Mines_Decrease->Update(mouse);
		Go->Update(mouse);

		if (Columns_Increase->isPressed() && nColumns < nColumnsMax) if (!bLRM_inhibited || Columns_Increase->nCooldown <= 1) nColumns++;
		if (Columns_Decrease->isPressed() && nColumns > nColumnsMin) if (!bLRM_inhibited || Columns_Decrease->nCooldown <= 1) nColumns--;
		if (Rows_Increase->isPressed() && nRows < nRowsMax) if (!bLRM_inhibited || Rows_Increase->nCooldown <= 1) nRows++;
		if (Rows_Decrease->isPressed() && nRows > nRowsMin) if (!bLRM_inhibited || Rows_Decrease->nCooldown <= 1) nRows--;
		if (Mines_Increase->isPressed() && nMines < nMinesMax) if (!bLRM_inhibited || Mines_Increase->nCooldown <= 1) nMines++;
		if (Mines_Decrease->isPressed() && nMines > 1) if (!bLRM_inhibited || Mines_Decrease->nCooldown <= 1) nMines--;

		nMinesMax = std::min(999, nColumns * nRows / 2);
		if (nColumns == 10) nMinesMax = std::min(9, nColumns * nRows / 2);
		else if (nColumns == 11) nMinesMax = std::min(99, nColumns * nRows / 2);

		if (nMines > nMinesMax) nMines = nMinesMax;
		else if (nMines < 1) nMines = 1;
	}

	bLRM_inhibited = mouse.LeftIsPressed();
}

void Menu::Draw(Graphics& gfx)
{
	if (!bCustomizing)
	{
		S->Draw(gfx);
		img::button_text_small(S->getTopLeft(), gfx);
		M->Draw(gfx);
		img::button_text_medium(M->getTopLeft(), gfx);
		L->Draw(gfx);
		img::button_text_large(L->getTopLeft(), gfx);
		XL->Draw(gfx);
		img::button_text_XL(XL->getTopLeft(), gfx);
		Custom->Draw(gfx);
		img::button_text_custom(Custom->getTopLeft(), gfx);
	}
	else
	{
		img::text_columns(Location(topleft.x, Columns_Increase->getTopLeft().y), gfx);
		numb.Draw(topleft.x + 78, Columns_Increase->getTopLeft().y, nColumns, Colors::Red, gfx);
		Columns_Increase->Draw(gfx);
		Columns_Decrease->Draw(gfx);
		img::text_rows(Location(topleft.x, Rows_Increase->getTopLeft().y), gfx);
		numb.Draw(topleft.x + 78, Rows_Increase->getTopLeft().y, nRows, Colors::Red, gfx);
		Rows_Increase->Draw(gfx);
		Rows_Decrease->Draw(gfx);
		img::text_mines(Location(topleft.x, Mines_Increase->getTopLeft().y), gfx);
		numb.Draw(topleft.x + 78, Mines_Increase->getTopLeft().y, nMines, Colors::Red, gfx);
		Mines_Increase->Draw(gfx);
		Mines_Decrease->Draw(gfx);
		Go->Draw(gfx);
		img::button_text_go(Go->getTopLeft(), gfx);
	}
}

int Menu::getColumns() const
{
	return nColumns;
}

int Menu::getRows() const
{
	return nRows;
}

int Menu::getMines() const
{
	return nMines;
}

bool Menu::isInitialized() const
{
	return S->isPressed() || M->isPressed() || L->isPressed() || XL->isPressed() || Go->isPressed();
}

void Menu::Reset()
{
	bCustomizing = false;
	S->ResetStatus();
	M->ResetStatus();
	L->ResetStatus();
	XL->ResetStatus();
	Go->ResetStatus();
}

Menu::SmallButton::SmallButton(const Location& topleft, bool increment)
	:
	bIncrement(increment)
{
	rect = { topleft, width, height };
}

void Menu::SmallButton::Update(Mouse& mouse)
{
	if (nCooldown > 0) nCooldown--;
	if (rect.isContaining(mouse.GetPos()))
	{
		status = Status::Hovered;
		if (mouse.LeftIsPressed())
		{
			status = Status::Pressed;
			if (nCooldown <= 0) nCooldown = nCooldownMax;
		}
	}
	else status = Status::Empty;

	if (status == Status::Pressed)
	{
		nCooldownMax--;
		nCooldownMax = std::max(1, nCooldownMax);
	}
	else nCooldownMax = 40;
}

void Menu::SmallButton::Draw(Graphics& gfx)
{
	switch (status)
	{
	case Status::Empty:
		if (bIncrement) img::button_increase_empty({ rect.left, rect.top }, gfx);
		else img::button_decrease_empty({ rect.left, rect.top }, gfx);
		break;
	case Status::Hovered:
		if (bIncrement) img::button_increase_hovered({ rect.left, rect.top }, gfx);
		else img::button_decrease_hovered({ rect.left, rect.top }, gfx);
		break;
	case Status::Pressed:
		if (bIncrement) img::button_increase_pressed({ rect.left, rect.top }, gfx);
		else img::button_decrease_pressed({ rect.left, rect.top }, gfx);
		break;
	}
}

bool Menu::SmallButton::isPressed() const
{
	return status == Status::Pressed;;
}

const Location Menu::SmallButton::getTopLeft() const
{
	return Location(rect.left, rect.top);
}
