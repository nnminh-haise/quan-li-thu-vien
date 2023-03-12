#include "Shapes.h"

#include <iostream>
#include <string>
#include <format>

#include "../../Graphics/graphics.h"



// Struct Shapes::Coordinate -----------------------------------------------------

Shapes::Coordinate::Coordinate() : x(0), y(0) {
}

Shapes::Coordinate::Coordinate(int x, int y) : x(x), y(y) {
}



// Struct Shapes::Rectangle ------------------------------------------------------

Shapes::Rectangle::Rectangle()
	: A(Shapes::Coordinate()), B(Shapes::Coordinate()), C(Shapes::Coordinate()), D(Shapes::Coordinate()), width(0), height(0) {
}

Shapes::Rectangle::Rectangle(Shapes::Coordinate A, Shapes::Coordinate B, Shapes::Coordinate C, Shapes::Coordinate D)
	: A(A), B(B), C(C), D(D) {
	this->width = this->B.x - this->A.x;
	this->height = this->A.y - this->D.y;
}

Shapes::Rectangle::Rectangle(Shapes::Coordinate topLeft, Shapes::Coordinate bottomright)
	: A(topLeft), C(bottomright) {
	this->B = Shapes::Coordinate(this->C.x, this->A.y);
	this->D = Shapes::Coordinate(this->A.x, this->C.y);
	this->width = this->C.x - this->A.x;
	this->height = this->A.y - this->C.y;
}

Shapes::Rectangle::Rectangle(Shapes::Coordinate topLeft, int width, int height)
	: A(topLeft), width(width), height(height) {
	this->B = Shapes::Coordinate(this->A.x + this->width - 1, this->A.y);
	this->C = Shapes::Coordinate(this->A.x + this->width - 1, this->A.y + this->height - 1);
	this->D = Shapes::Coordinate(this->A.x, this->A.y + this->height - 1);
}

Shapes::Coordinate Shapes::Rectangle::GetA() {
	return this->A;
}

Shapes::Coordinate Shapes::Rectangle::GetB() {
	return this->B;
}

Shapes::Coordinate Shapes::Rectangle::GetC() {
	return this->C;
}

Shapes::Coordinate Shapes::Rectangle::GetD() {
	return this->D;
}

void Shapes::Rectangle::SetA(Shapes::Coordinate A) {
	this->A = A;
}

void Shapes::Rectangle::SetB(Shapes::Coordinate B) {
	this->B = B;
}

void Shapes::Rectangle::SetC(Shapes::Coordinate C) {
	this->C = C;
}

void Shapes::Rectangle::SetD(Shapes::Coordinate D) {
	this->D = D;
}
