#pragma once
#include "Location.h"
#include "Graphics.h"
#include "img.h"
#include "Mouse.h"
#include "Rect.h"
#include "Numbers.h"
#include <memory>
class Menu
{
private:
	class Button
	{
	public:
		enum class Status
		{
			Empty,
			Hovered,
			Pressed
		};

		Button(const Location& topleft);
		void Update(Mouse& mouse);
		void Draw(Graphics& gfx);
		bool isPressed() const;
		bool isHovered() const;
		void ResetStatus();
		const Location getTopLeft() const;

	private:
		Rect rect;
		Status status = Status::Empty;
	};

	class SmallButton
	{
	public:
		enum class Status
		{
			Empty,
			Hovered,
			Pressed
		};

		SmallButton(const Location& topleft, bool increment);
		void Update(Mouse& mouse);
		void Draw(Graphics& gfx);
		bool isPressed() const;
		const Location getTopLeft() const;

		int nCooldown = 0;
		int nCooldownMax = 40;
		static constexpr int width = 16;
		static constexpr int height = 25;
	private:
		Rect rect;
		Status status = Status::Empty;
		bool bIncrement = false;
	};

public:

	Menu(const Location& topleft);

	void Update(Mouse& mouse);
	void Draw(Graphics& gfx);
	int getColumns() const;
	int getRows() const;
	int getMines() const;
	bool isInitialized() const;
	void Reset();

	static constexpr int btn_width = 160;
	static constexpr int btn_height = 60;

private:
	Location topleft;
	static constexpr int nColumnsMax = 49;
	static constexpr int nRowsMax = 34;
	static constexpr int nColumnsMin = 10;
	static constexpr int nRowsMin = 3;
	int nMinesMax = 1;
	int nColumns = nColumnsMin;
	int nRows = nRowsMin;
	int nMines = -1;

	bool bCustomizing = false;
	bool bLRM_inhibited = false;
	Numbers numb;

	std::unique_ptr<Button> S = std::make_unique<Button>(topleft);
	std::unique_ptr<Button> M = std::make_unique<Button>(Location(topleft.x, topleft.y + btn_height));
	std::unique_ptr<Button> L = std::make_unique<Button>(Location(topleft.x, topleft.y + btn_height * 2));
	std::unique_ptr<Button> XL = std::make_unique<Button>(Location(topleft.x, topleft.y + btn_height * 3));
	std::unique_ptr<Button> Custom = std::make_unique<Button>(Location(topleft.x, topleft.y + btn_height * 4));

	std::unique_ptr<SmallButton> Columns_Increase = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width, topleft.y), true);
	std::unique_ptr<SmallButton> Columns_Decrease = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width * 2 - 1, topleft.y), false);
	std::unique_ptr<SmallButton> Rows_Increase = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width, topleft.y + 50), true);
	std::unique_ptr<SmallButton> Rows_Decrease = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width * 2 - 1, topleft.y + 50), false);
	std::unique_ptr<SmallButton> Mines_Increase = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width, topleft.y + 100), true);
	std::unique_ptr<SmallButton> Mines_Decrease = std::make_unique<SmallButton>(Location(topleft.x + btn_width - SmallButton::width * 2 - 1, topleft.y + 100), false);
	std::unique_ptr<Button> Go = std::make_unique<Button>(Location(topleft.x, topleft.y + 180));
};

