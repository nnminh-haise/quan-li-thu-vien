#pragma once

#include <iostream>
#include <string>
#include <format>

namespace Shapes {

	struct Coordinate {
		int x, y;

		Coordinate();
		Coordinate(int x, int y);
	};



	class Rectangle {
	private:
		Coordinate A, B, C, D;
		int width, height;

	public:
		Rectangle();
		Rectangle(Coordinate A, Coordinate B, Coordinate C, Coordinate D);
		Rectangle(Coordinate topLeft, Coordinate bottomRight);
		Rectangle(Coordinate topLeft, int width, int height);

	public:
		Coordinate GetA();
		Coordinate GetB();
		Coordinate GetC();
		Coordinate GetD();
		void SetA(Coordinate A);
		void SetB(Coordinate B);
		void SetC(Coordinate C);
		void SetD(Coordinate D);
	};
}
