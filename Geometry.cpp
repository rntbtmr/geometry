#include <iostream>
#include <windows.h>
#include <math.h>
#include <list>
#include <algorithm>


using namespace std;

class Point
{
public:
	int x;
	int y;
	int z;
	string name;

	Point()
	{
		int x, y, z;
		string name;
		cout << "������� �������� �����: ";
		cin >> name;
		cout << "������� ���������� ����� \"" << name  << "\": ";
		cin >> x >> y >> z;
		this->x = x;
		this->y = y;
		this->z = z;
		this->name = name;
	}

	static void printTemplatePoint()
	{
		cout << "�������� �����(x,y,z)\n";
	}

	void printPoint(struct Point* point)
	{
		cout << this->name << this->x << this->y << this->z;
	}
};

class Vector
{
public:
	Point point1;
	Point point2;
	static int amountVector; // ����������� ����
	

	Vector() {
		amountVector++; // ���������� ��������� ����������� �������
	}

	double lenghtVector()
	{
		int* coordinatesVector = this->findCoordinates();
		double lenght, X, Y, Z;
		X = pow(coordinatesVector[0], 2);
		Y = pow(coordinatesVector[1], 2);
		Z = pow(coordinatesVector[2], 2);
		lenght = sqrt(X + Y + Z);
		return lenght;
	}

	int* findCoordinates()
	{
		int coordinates[3] =
		{
			this->point2.x - this->point1.x,
			this->point2.y - this->point1.y,
			this->point2.z - this->point1.z
		};
		return coordinates;
	}

	double scalarProduct(Vector* vector2)
	{
		int* coordinatesVector1 = this->findCoordinates();
		int* coordinatesVector2 = vector2->findCoordinates();
		return coordinatesVector1[0] * coordinatesVector2[0] + coordinatesVector1[1] * coordinatesVector2[1] + coordinatesVector1[2] * coordinatesVector2[2];
	}

	double additionVectors(Vector* vector2)
	{
		int* coordinatesVector1 = this->findCoordinates();
		int* coordinatesVector2 = vector2->findCoordinates();
		int coordinates[3] =
		{
			coordinatesVector1[0] + coordinatesVector2[0],
			coordinatesVector1[1] + coordinatesVector2[1],
			coordinatesVector1[2] + coordinatesVector2[2]
		};
		double lenght, X, Y, Z;
		X = pow(coordinates[0], 2);
		Y = pow(coordinates[1], 2);
		Z = pow(coordinates[2], 2);
		lenght = sqrt(X + Y + Z);
		return lenght;
	}
	
	void printCoordinates(Vector* vector)
	{
		int* coordinatesVector = this->findCoordinates();
		for (int i = 0; i <= 3; ++i)
		{
			cout << coordinatesVector[i - 1] << "\n";
		}
	}

	void printVector()
	{
		int* coordinates = this->findCoordinates();
		cout << "������ \"" << this->point1.name << this->point2.name << "\"(" << coordinates[0] << ", " << coordinates[1] << ", " << coordinates[2] << ")";
	}


	// ���������� � �����

	bool compareLenghtVector(Vector* vector1, Vector* vector2)
	{
		return vector1->lenghtVector() > vector2->lenghtVector();
	}
	
	Vector maxLenghtVector(list<Vector>& vectors) {
		return *max_element(vectors.begin(), vectors.end(), compareLenghtVector);
	}

	list<Vector> sortLenghtVector(list<Vector>& vectors)
	{
		sort(vectors.begin(), vectors.end(), compareLenghtVector);
	}
};

// ������ ������
template <typename Color>
class ColoredVector : public Vector
{
public:
	Vector vector;

	ColoredVector(Point point1, Point point2, Color color)
	{
		// try, catch, throw �����
		int* cooridanatesVector = vector.findCoordinates();
		try
		{
			int f = 0;
			for (int i = 0; i < 3; i++)
				if (cooridanatesVector[i] == 0)
					f = 1;
			if (f == 1)
				throw "���������� ������� �� ����� ���� ����� 0";
		}
		catch (const char* errorMessage)
		{
			cout << "������: " << errorMessage << endl;

		}
		Vector(point1, point2);
		this->color = color;

	}

	void setColor(Color color) {
		this->color = color;
	}

	Color getColar() {
		return this->color;
	}

	void printColoredVector()
	{
		Vector::printVector();
		cout << "���� �������: " << color;
	}
};

class Triangle : public Figure
{
public:
	ColoredVector<Vector> vector1;
	ColoredVector<Vector> vector2;

	// ������������� �������
	friend void setVectors(Triangle triangle, ColoredVector<Vector> vector1, ColoredVector<Vector> vector2)
	{
		triangle.vector1 = vector1;
		triangle.vector2 = vector2;
	}

	int perimeterTriangle()
	{
		return vector1.vector.lenghtVector() + vector1.vector.lenghtVector() + vector1.vector.additionVectors(&vector2.vector);
	}

	void printFigure()
	{
		vector1.printColoredVector();
		vector2.printColoredVector();
	}
};

class Parallelogram : public Figure
{
public:
	// ������������� �����������
	list<ColoredVector<Vector>> vectors;
	
	Parallelogram(ColoredVector<Vector> vector1, ColoredVector<Vector> vector2) 
	{
		this->vectors.push_back(vector1);
		this->vectors.push_back(vector2);

	}

	int perimeterParallelogram()
	{
		return this->vectors.front().vector.lenghtVector() * 2 + this->vectors.back().vector.lenghtVector() * 2;
	}

	double squareParallelogram()
	{
		double sinus, cosinus, lenghtVector1, lenghtVector2;
		lenghtVector1 = this->vectors.front().vector.lenghtVector();
		lenghtVector2 = this->vectors.back().vector.lenghtVector();
		cosinus = this->vectors.front().vector.scalarProduct(&this->vectors.back().vector) / (lenghtVector1 * lenghtVector2);
		sinus = sqrt(1 - pow(cosinus, 2));
		return lenghtVector1 * lenghtVector2 * sinus;
	}
	
	void printFigure()
	{
		vectors.front().printColoredVector();
		vectors.back().printColoredVector();
	}

};

// ����������� �����
class Figure
{
// ����������� protected
protected:
	// ����������� �������
	virtual void printFigure();
};