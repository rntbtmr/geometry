#pragma once

struct Point
{
	int x;
	int y;
	int z;
	char name[20];
	void setPoint(struct Point* point);
	void printPoint(struct Point* point);
};

struct Vector
{
	struct Point point1;
	struct Point point2;
	void setVector(struct Vector* vector);
	double lenghtVector(struct Vector* vector);
	int* findCoordinates(struct Vector* vector);
	double scalarProduct(struct Vector* vector1, struct Vector* vector2);
	int dditionVectors(struct Vector* vector1, struct Vector* vector2);
	void printVector(struct Vector* vector);
};

struct ColoredVector
{
	struct Vector vector;
	char color[20];
	void setColoredVector(struct ColoredVector* coloredVector);
	void printColoredVector(struct ColoredVector* coloredVector);
};

struct Triangle 
{
	struct ColoredVector vector1;
	struct ColoredVector vector2;
	void setTriangle(struct Triangle* triangle);
	int perimeterTriangle(struct Triangle* triangle);
	double squareTriangle(struct Triangle* triangle);
	void printTriangle(struct Triangle* triangle);
};

struct Parallelogram 
{
	struct ColoredVector vector1;
	struct ColoredVector vector2;
	void setParalleogram(struct Parallelogram* parallelogram);
	int perimeterParallelogram(struct Parallelogram* parallelogram);
	double squareParallelogram(struct Parallelogram* parallelogram);
	void printParallelogram(struct Parallelogram* parallelogram);
};