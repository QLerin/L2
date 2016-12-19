#include "ProgressBar.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

static const uint16_t DEFAULT_MAX		     = 100;
static const uint16_t DEFAULT_UNITS_PER_CELL = 2;
static const uint16_t DEFAULT_HEIGHT		 = 4;

void ProgressBar::CalculateCells()
{
	uint16_t ammountToDraw = currentAmmount_ / unitsPerCell_;
	string & drawableData = drawable_.GetDrawableData();
	drawableData.resize(cells_ * height_, ' ');
	for (auto i = 0; i < height_; ++i)
		for (auto j = 0; j < ammountToDraw; ++j)
			drawableData[i * cells_ + j] = '#';
}

ProgressBar::ProgressBar() : UnselectabeSUIComponent(), maxAmmount_(DEFAULT_MAX), unitsPerCell_(DEFAULT_UNITS_PER_CELL), height_(DEFAULT_HEIGHT)
{
	drawable_.SetDrawableData("");

	currentAmmount_ = maxAmmount_;
	cells_ = maxAmmount_ / unitsPerCell_;
	height_ = DEFAULT_HEIGHT;

	drawable_.SetDrawableSpace(0, 0, cells_, height_);

	CalculateCells();
}

ProgressBar::ProgressBar(const uint16_t maxAmmount) : UnselectabeSUIComponent(), maxAmmount_(maxAmmount)
{
	drawable_.SetDrawableData("");

	currentAmmount_ = maxAmmount;
	unitsPerCell_ = DEFAULT_UNITS_PER_CELL;
	cells_ = maxAmmount / unitsPerCell_;
	height_ = DEFAULT_HEIGHT;

	drawable_.SetDrawableSpace(0, 0, cells_, height_);

	CalculateCells();
}

void ProgressBar::IncrementBar(const uint16_t ammount)
{
	if (ammount + currentAmmount_ >= maxAmmount_)
		currentAmmount_ = maxAmmount_;
	else
		currentAmmount_ += ammount;

	CalculateCells();
}

void ProgressBar::DecrementBar(const uint16_t ammount)
{
	if (currentAmmount_ <= ammount)
		currentAmmount_ = 0;
	else
		currentAmmount_ -= ammount;

	CalculateCells();
}

void ProgressBar::SetProgressAt(const uint16_t ammount)
{
	if (ammount <= maxAmmount_)
		currentAmmount_ = ammount;
	else
		currentAmmount_ = maxAmmount_;

	CalculateCells();
}

void ProgressBar::SetMaxAmmount(const uint16_t maxAmmount)
{
	if (currentAmmount_ < maxAmmount)
		currentAmmount_ = maxAmmount;
	maxAmmount_ = maxAmmount;
	unitsPerCell_ = maxAmmount / cells_;

	CalculateCells();
}

void ProgressBar::SetHeight(const uint16_t height)
{
	if (height > 0)
		height_ = height;
	CalculateCells();
}

void ProgressBar::SetUnitsPerCell(const uint16_t unitsPerCell)
{
	unitsPerCell_ = unitsPerCell;
	cells_ = maxAmmount_ / unitsPerCell;
	CalculateCells();
}