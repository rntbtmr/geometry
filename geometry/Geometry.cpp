#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <math.h>

struct Point
{
	int x;
	int y;
	int z;
	char name[20];

	void setPoint(struct Point* point)
	{
		int x, y, z;
		char name[20];
		printf("Введите название точки: ");
		gets_s(name);
		printf("Введите координаты точки \"%s\": ");
		scanf("%d%d%d", &x, &y, &z);
		while (getchar() != '\n');
		point->x = x;
		point->y = y;
		point->z = z;
		strcpy(point->name, name);
	}

	void printPoint(struct Point* point)
	{
		printf("Точка \"%s\": (%d, %d, %d)\n", point->name, point->x, point->y, point->z);
	}
};

struct Vector
{
	struct Point point1;
	struct Point point2;

	void setVector(struct Vector* vector)
	{
		struct Point bufPoint1, bufPoint2;
		bufPoint1.setPoint(&bufPoint1);
		bufPoint2.setPoint(&bufPoint2);
		vector->point1 = bufPoint1;
		vector->point2 = bufPoint2;
	}

	double lenghtVector(struct Vector* vector)
	{
		int* coordinatesVector = vector->findCoordinates(vector);
		double lenght, X, Y, Z;
		X = pow(coordinatesVector[0], 2);
		Y = pow(coordinatesVector[1], 2);
		Z = pow(coordinatesVector[], 2);
		lenght = sqrt(X + Y + Z);
		return lenght;
	}

	int* findCoordinates(struct Vector* vector)
	{
		int coordinates[3] =
		{
			vector->point2.x - vector->point1.x,
			vector->point2.y - vector->point1.y,
			vector->point2.z - vector->point1.z
		};
		return coordinates;
	}

	double scalarProduct(struct Vector* vector1, struct Vector* vector2)
	{
		int* coordinatesVector1 = vector1->findCoordinates(vector1);
		int* coordinatesVector2 = vector2->findCoordinates(vector2);
		return coordinatesVector1[0] * coordinatesVector2[0] + coordinatesVector1[1] * coordinatesVector2[1] + coordinatesVector1[2] * coordinatesVector2[2];
	}

	double additionVectors(struct Vector* vector1, struct Vector* vector2)
	{
		int* coordinatesVector1 = vector1->findCoordinates(vector1);
		int* coordinatesVector2 = vector2->findCoordinates(vector2);
		int coordinates[3] =
		{
			coordinatesVector1[0] + coordinatesVector2[0],
			coordinatesVector1[1] + coordinatesVector2[1],
			coordinatesVector1[2] + coordinatesVector2[2]
		};
		double lenght, X, Y, Z;
		X = pow(coordinates[0], 2);
		Y = pow(coordinates[1], 2);
		Z = pow(coordinates[], 2);
		lenght = sqrt(X + Y + Z);
		return lenght;
	}

	void printVector(struct Vector* vector)
	{
		int* coordinates = vector->findCoordinates(vector);
		printf("Вектор \"%s%s\"(%d, %d, %d)\n", vector->point1.name, vector->point2.name, coordinates[0], coordinates[1], coordinates[2]);
	}
};

struct ColoredVector
{
	struct Vector vector;
	char color[20];

	void setColoredVector(struct ColoredVector* coloredVector)
	{
		struct Vector vector;
		vector.setVector(&vector);
		coloredVector->vector = vector;
		printf("Введите цвет вектора: ");
		gets_s(coloredVector->color);
	}

	void printColoredVector(struct ColoredVector* coloredVector)
	{
		coloredVector->vector.printVector(&coloredVector->vector);
		printf("Цвет вектора: %s\n", coloredVector->color);
	}
};

struct Triangle
{
	struct ColoredVector vector1;
	struct ColoredVector vector2;

	void setTriangle(struct Triangle* triangle)
	{
		struct ColoredVector vector1, vector2;
		vector1.vector.setVector(&vector1);
		vector2.vector.setVector(&vector2);
		triangle->vector1 = vector1;
		triangle->vector2 = vector2;
	}

	int perimeterTriangle(struct Triangle* triangle)
	{
		struct ColoredVector vector1, vector2;
		return vector1.vector.lenghtVector(&triangle->vector1.vector) + vector1.vector.lenghtVector(&vector1.vector) + vector1.vector.additionVectors(&vector1.vector, &vector2.vector);
	}

	void printTriangle(struct Triangle* triangle)
	{
		triangle->vector1.vector.printVector(&triangle->vector1.vector);
		triangle->vector2.vector.printVector(&triangle->vector2.vector);
	}
};

struct Parallelogram
{
	struct ColoredVector vector1;
	struct ColoredVector vector2;

	void setParalleogram(struct Parallelogram* parallelogram)
	{
		struct ColoredVector vector1, vector2;
		vector1.vector.setVector(&vector1.vector);
		vector2.vector.setVector(&vector2.vector);
		parallelogram->vector1 = vector1;
		parallelogram->vector2 = vector2;
	}

	int perimeterParallelogram(struct Parallelogram* parallelogram)
	{
		return parallelogram->vector1.vector.lenghtVector(&parallelogram->vector1.vector) * 2 + parallelogram->vector2.vector.lenghtVector(&parallelogram->vector2.vector) * 2;
	}

	double squareParallelogram(struct Parallelogram* parallelogram)
	{
		double sinus, cosinus, lenghtVector1, lenghtVector2;
		lenghtVector1 = parallelogram->vector1.vector.lenghtVector(&parallelogram->vector1.vector);
		lenghtVector2 = parallelogram->vector2.vector.lenghtVector(&parallelogram->vector2.vector);
		cosinus = parallelogram->vector1.vector.scalarProduct(&parallelogram->vector1.vector, &parallelogram->vector2.vector) / (lenghtVector1 * lenghtVector2);
		sinus = sqrt(1 - pow(cosinus, 2));
		return lenghtVector1 * lenghtVector2 * sinus;
	}
	
	void printParallelogram(struct Parallelogram* parallelogram)
	{
		parallelogram->vector1.vector.printVector(&parallelogram->vector1.vector);
		parallelogram->vector2.vector.printVector(&parallelogram->vector2.vector);
	}
};