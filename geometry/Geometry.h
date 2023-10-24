#pragma once

class Point
{
private:
	int x;
	int y;
	int z;
	char name[20];
	Point();
	void printPoint();
};

class Vector
{
public:
	Point point1;
	Point point2;
	double lenghtVector();
	int* findCoordinates();
	double scalarProduct(Vector* vector2);
	double additionVectors(Vector* vector2);
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