#pragma once

class Point
{
private:
	int x;
	int y;
	int z;
	char name[20];
	Point();
	static void printTemplatePoint();
	void printPoint();
};

class Vector
{
public:
	Point point1;
	Point point2;
	static int amountVector;
	Vector();
	double lenghtVector();
	int* findCoordinates();
	double scalarProduct();
	double additionVectors();
	void printCoordinates();
	void printVector();
};

template <typename Color>
class ColoredVector : public Vector
{
public:
	Vector vector;
	ColoredVector();
	void setColor();
	Color getColor();
	void printColoredVector();
};

class Triangle : public Figure 
{
public:
	ColoredVector<Vector> vector1;
	ColoredVector<Vector> vector2;
	friend void setVectors();
	int perimeterTriangle();
	void printFigure();
};

class Parallelogram : public Figure
{
public:
	ColoredVector<Vector> vector1;
	ColoredVector<Vector> vector2;
	int perimeterParallelogram();
	double squareParallelogram();
	void printFigure();
};

class Figure 
{
protected:
	void printFigure();
};