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

class ColoredVector : public Vector
{
public:
	Vector vector;
	char color[20];
	ColoredVector();
	void printColoredVector();
};

class Triangle 
{
public:
	ColoredVector vector1;
	ColoredVector vector2;
	friend void setVectors();
	int perimeterTriangle();
	void printTriangle();
};

class Parallelogram 
{
public:
	ColoredVector vector1;
	ColoredVector vector2;
	int perimeterParallelogram();
	double squareParallelogram();
	void printParallelogram();
};