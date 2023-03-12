
#include "Elements.h"

#include <string>
#include <iostream>
#include <format>

#include "../Shapes/Shapes.h"
#include "../../Graphics/graphics.h"



// Struct Elements::Size --------------------------------------------------------------

Elements::Size::Size() : width(0), height(0) {
}

Elements::Size::Size(int width, int height) : width(width), height(height) {
}



// Class Elements::GraphicWindow ------------------------------------------------------

Elements::GraphicWindow::GraphicWindow() : windowSize(500, 500), title("Default graphical window!") {
}

Elements::GraphicWindow::GraphicWindow(int width, int height, std::string title) {
	this->windowSize = Elements::Size(width, height);
	this->title = title;
}

int Elements::GraphicWindow::Initialize() {
	int windowsIndex = initwindow(
		this->windowSize.width, this->windowSize.height,
		(const char*)this->title.c_str()
	);

	return windowsIndex;
}

int Elements::GraphicWindow::Deconstruct() {
	closegraph();
	std::clog << "Window was deconstructed!" << std::endl;
	return 1;
}



// Struct Elements::Padding -----------------------------------------------------------

Elements::Padding::Padding() : top(0), bottom(0), left(0), right(0) {
}

Elements::Padding::Padding(int top, int bottom, int left, int right) : top(top), bottom(bottom), left(left), right(right) {
}



// Class Elements::Fill ---------------------------------------------------------------

Elements::Fill::Fill() {
	this->fillColor = BLACK;
	this->fillSize = Elements::Size();
	this->SetA(Shapes::Coordinate());
	this->SetB(Shapes::Coordinate());
	this->SetC(Shapes::Coordinate());
	this->SetD(Shapes::Coordinate());
}

Elements::Fill::Fill(Shapes::Coordinate topLeft, Shapes::Coordinate bottomRight, int color) {
	this->SetA(topLeft);
	this->SetC(bottomRight);
	this->SetB(Shapes::Coordinate(bottomRight.x, topLeft.y));
	this->SetD(Shapes::Coordinate(topLeft.x, bottomRight.y));
	this->fillColor = color;
	this->fillSize.width = this->GetC().x - this->GetA().x;
	this->fillSize.height = this->GetC().y - this->GetA().y;
}

Elements::Fill::Fill(Shapes::Coordinate position, int width, int height, int color) {
	this->SetA(position);
	this->SetC(Shapes::Coordinate(position.x + width, position.y + height));
	this->SetB(Shapes::Coordinate(this->GetC().x, this->GetA().y));
	this->SetD(Shapes::Coordinate(this->GetA().x, this->GetC().y));
	this->fillSize.width = width;
	this->fillSize.height = height;
	this->fillColor = color;
}

Elements::Size Elements::Fill::GetFillSize() {
	return this->fillSize;
}

void Elements::Fill::SetFillSize(Elements::Size fillSize) {
	this->fillSize = fillSize;
}

int Elements::Fill::GetFillColor() {
	return this->fillColor;
}

void Elements::Fill::SetFillColor(int color) {
	this->fillColor = color;
}

void Elements::Fill::Draw() {
	setfillstyle(SOLID_FILL, this->fillColor);
	setbkcolor(this->fillColor);
	bar(this->GetA().x, this->GetA().y, this->GetC().x, this->GetC().y);
}

// Class Elements::Border -------------------------------------------------------------

Elements::Border::Border() {
	this->borderColor = BLACK;
	this->borderSize = Elements::Size();
	this->SetA(Shapes::Coordinate());
	this->SetB(Shapes::Coordinate());
	this->SetC(Shapes::Coordinate());
	this->SetD(Shapes::Coordinate());
}

Elements::Border::Border(Shapes::Coordinate topLeft, Shapes::Coordinate bottomRight, int color) {
	this->SetA(topLeft);
	this->SetC(bottomRight);
	this->SetB(Shapes::Coordinate(bottomRight.x, topLeft.y));
	this->SetD(Shapes::Coordinate(topLeft.x, bottomRight.y));
	this->borderColor = color;
	this->borderSize.width = this->GetC().x - this->GetA().x;
	this->borderSize.height = this->GetC().y - this->GetA().y;
}

Elements::Border::Border(Shapes::Coordinate position, int width, int height, int color) {
	this->SetA(position);
	this->SetC(Shapes::Coordinate(position.x + width, position.y + height));
	this->SetB(Shapes::Coordinate(this->GetC().x, this->GetA().y));
	this->SetD(Shapes::Coordinate(this->GetA().x, this->GetC().y));
	this->borderSize.width = width;
	this->borderSize.height = height;
	this->borderColor = color;
}

Elements::Size Elements::Border::GetBorderSize() {
	return this->borderSize;
}

void Elements::Border::SetBorderSize(Elements::Size borderSize) {
	this->borderSize = borderSize;
}

int Elements::Border::GetBorderColor() {
	return this->borderColor;
}

void Elements::Border::SetBorderColor(int color) {
	this->borderColor = color;
}

void Elements::Border::Draw() {
	setbkcolor(this->borderColor);
	rectangle(this->GetA().x, this->GetA().y, this->GetC().x, this->GetC().y);
}



// Class Elements::MessBox ------------------------------------------------------------

void Elements::MessBox::UpdateStyle() {
	settextstyle(this->fontStyle, HORIZ_DIR, this->fontSize);
	setcolor(this->textColor);
	
	this->fill.SetFillSize(this->boxSize);
	this->fill.SetFillColor(this->backgroundColor);
	
	this->border.SetBorderSize(this->boxSize);
	this->border.SetBorderColor(this->backgroundColor);
	
	this->textSize = Elements::Size(
		textwidth((char*)value.c_str()),
		textheight((char*)value.c_str())
	);
}

void Elements::MessBox::UpdatePosition() {
	this->textSize = Elements::Size(
		textwidth((char*)value.c_str()),
		textheight((char*)value.c_str())
	);

	int requireBoxWidth = this->textSize.width + this->padding.left + this->padding.right;
	int requireBoxHeight = this->textSize.height + this->padding.top + this->padding.bottom;

	if (requireBoxWidth > this->boxSize.width) {
		this->boxSize.width = requireBoxWidth;
	}

	if (requireBoxHeight > this->boxSize.height) {
		this->boxSize.height = requireBoxHeight;
	}

	this->textPosition = Shapes::Coordinate(
		this->boxPosition.x + this->padding.left,
		this->boxPosition.y + this->padding.top
	);

	this->border = Elements::Border(
		this->boxPosition,
		this->boxSize.width, this->boxSize.height,
		this->backgroundColor
	);

	this->fill = Elements::Fill(
		this->boxPosition,
		this->boxSize.width, this->boxSize.height,
		this->backgroundColor
	);

	std::clog << std::format("Box position : ({}, {})", this->boxPosition.x, this->boxPosition.y) << std::endl;
	std::clog << std::format("Text position: ({}, {})", this->textPosition.x, this->textPosition.y) << std::endl;
	std::clog << std::format("Text width : {}", this->textSize.width) << std::endl;
	std::clog << std::format("Text height: {}", this->textSize.height) << std::endl;
	std::clog << std::format("Box width : {}", this->boxSize.width) << std::endl;
	std::clog << std::format("Box height: {}", this->boxSize.height) << std::endl;
}

Elements::MessBox::MessBox() :
	value(std::string()),
	boxSize(Elements::Size()),
	textSize(Elements::Size()),
	boxPosition(Shapes::Coordinate()),
	textPosition(Shapes::Coordinate()),
	textColor(0),
	backgroundColor(0),
	fontStyle(8),
	fontSize(3),
	fill(Elements::Fill()),
	border(Elements::Border()),
	padding(Elements::Padding()),
	verticalAlignment(Elements::Align::MIDDLE),
	horizontalAlignment(Elements::Align::LEFT)
{
}

Elements::MessBox::MessBox(std::string value, Shapes::Coordinate position, int width, int height) :
	value(value),
	boxSize(Elements::Size(width, height)),
	boxPosition(position),
	textColor(BLACK),
	backgroundColor(WHITE),
	fontStyle(8),
	fontSize(2),
	padding(Elements::Padding(10, 10, 10, 10)),
	verticalAlignment(Elements::Align::MIDDLE),
	horizontalAlignment(Elements::Align::LEFT)
{
	this->UpdateStyle();
	this->UpdatePosition();

}

void Elements::MessBox::SetValue(std::string value) {
	this->value = value;
}

void Elements::MessBox::SetWidth(int width) {
	int currentHeight = this->boxSize.height;
	this->boxSize = Elements::Size(width, currentHeight);
}

void Elements::MessBox::SetHeight(int height) {
	int currentWidth = this->boxSize.width;
	this->boxSize = Elements::Size(currentWidth, height);
}

void Elements::MessBox::SetTextColor(int color) {
	this->textColor = color;
}

void Elements::MessBox::SetBackgroundColor(int color) {
	this->backgroundColor = color;
}

void Elements::MessBox::SetVerticalAlignment(Align verticalAlignment) {
	int remainWidth = this->boxSize.width - this->padding.left - this->padding.right;
	int remainHeight = this->boxSize.height - this->padding.top - this->padding.bottom;

	if (remainHeight == 0) {
		return;
	}

	switch (this->verticalAlignment) {
		case (Elements::Align::TOP): {
			this->textPosition.y = this->boxPosition.y + this->padding.top;
			this->UpdateStyle();
			this->UpdatePosition();
			break;
		};
		case (Elements::Align::MIDDLE): {
			this->textPosition.y = this->boxPosition.y + this->padding.top + remainHeight / 2;
			this->UpdateStyle();
			this->UpdatePosition();
			break;
		};
		case (Elements::Align::BOTTOM): {
			this->textPosition.y = this->boxPosition.y + this->padding.top + remainHeight;
			this->UpdateStyle();
			this->UpdatePosition();
			break;
		}
	}
}

void Elements::MessBox::SetHorizontalAlignment(Align horizontalAlignment) {
	int remainWidth = this->boxSize.width - this->padding.left - this->padding.right;
	int remainHeight = this->boxSize.height - this->padding.top - this->padding.bottom;

	if (remainWidth == 0) {
		return;
	}

	switch (this->horizontalAlignment) {
	case (Elements::Align::LEFT): {
		this->textPosition.x = this->boxPosition.x + this->padding.left;
		this->UpdateStyle();
		this->UpdatePosition();
		break;
	};
	case (Elements::Align::CENTER): {
		this->textPosition.x = this->boxPosition.x + this->padding.left + remainWidth / 2;
		this->UpdateStyle();
		this->UpdatePosition();
		break;
	};
	case (Elements::Align::RIGHT): {
		this->textPosition.x = this->boxPosition.x + this->padding.left + remainWidth;
		this->UpdateStyle();
		this->UpdatePosition();
		break;
	}
	}
}

void Elements::MessBox::SetFontStyle(int fontStyle) {
	this->fontStyle = fontStyle;
	this->UpdateStyle();
	this->UpdatePosition();
}

void Elements::MessBox::SetFontSize(int fontSize) {
	this->fontSize = fontSize;
	this->UpdateStyle();
	this->UpdatePosition();
}

void Elements::MessBox::Draw() {
	this->UpdateStyle();
	this->UpdatePosition();

	this->fill.Draw();
	this->border.Draw();
	outtextxy(
		this->textPosition.x, this->textPosition.y,
		(char*)value.c_str()
	);
}
