#pragma once

#include <string>
#include <iostream>
#include <format>
#include "../Shapes/Shapes.h"
#include "../../Graphics/graphics.h"



namespace Elements {
	
	enum Align {
		LEFT, CENTER, RIGHT, TOP, MIDDLE, BOTTOM
	};

	struct Size {
		int width, height;

		Size();
		Size(int width, int height);
	};

	struct Padding {
		int top, bottom, left, right;

		Padding();
		Padding(int top, int bottom, int left, int right);
	};


	class GraphicWindow {
	private:
		Size windowSize;
		std::string title;

	public:
		GraphicWindow();
		GraphicWindow(int width, int height, std::string title);
		int Initialize();
		int Deconstruct();
	};

	class Fill : private Shapes::Rectangle {
	private:
		Size fillSize;
		int fillColor;

	public:
		Fill();
		Fill(Shapes::Coordinate topLeft, Shapes::Coordinate bottomRight, int color);
		Fill(Shapes::Coordinate position, int width, int height, int color);
		Size GetFillSize();
		void SetFillSize(Size fillSize);
		int GetFillColor();
		void SetFillColor(int color);
		void Draw();
	};
	
	class Border : private Shapes::Rectangle {
	private:
		Size borderSize;
		int borderColor;

	public:
		Border();
		Border(Shapes::Coordinate topLeft, Shapes::Coordinate bottomRight, int color);
		Border(Shapes::Coordinate position, int width, int height, int color);
		Size GetBorderSize();
		void SetBorderSize(Size borderSize);
		int GetBorderColor();
		void SetBorderColor(int color);
		void Draw();
	};


	class MessBox {
	private:
		std::string value;
		Size boxSize;
		Size textSize;
		Shapes::Coordinate boxPosition;
		Shapes::Coordinate textPosition;
		int textColor;
		int backgroundColor;
		int fontStyle;
		int fontSize;
		Fill fill;
		Border border;
		Padding padding;
		Align verticalAlignment;
		Align horizontalAlignment;
		

	private:
		void UpdateStyle();
		void UpdatePosition();

	public:
		MessBox();
		MessBox(std::string value, Shapes::Coordinate position, int width, int height);

		void SetValue(std::string value);
		void SetWidth(int width);
		void SetHeight(int height);
		void SetTextColor(int color);
		void SetBackgroundColor(int color);
		void SetVerticalAlignment(Align verticalAlignment);
		void SetHorizontalAlignment(Align horizontalAlignment);
		void SetFontStyle(int fontStyle);
		void SetFontSize(int fontSize);


		void Draw();
	};


}

