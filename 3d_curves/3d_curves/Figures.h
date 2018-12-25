#pragma once
#define PI 3.14159265
#include<iostream>
using namespace std;

enum Figure_Type { Circle_ID, Ellipse_ID, Helixes_ID };

float random(float min, float max);

struct Point {
	float x, y, z;
	friend ostream& operator<< (ostream &out, const Point &point)
	{
		out << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";
		return out;
	}
};

class Figure {
public:
	Point coord0;
	float rX, rY;
	float t;
	Figure_Type figure_type;
	virtual void show() { cout << "figure"; }
	virtual void setRadius() = 0;
	virtual void setX0() = 0;
	virtual void setY0() = 0;
	virtual void setZ0() = 0;
	//virtual void setT(float t1) = 0;
	/*friend bool operator> (const Figure &f1, const Figure &f2)
	{
		return f1.rX >f2.rX;
	}
	friend bool operator< (const Figure &f1, const Figure &f2)
	{
		return f1.rX <f2.rX;
	}*/

};


class circle : public Figure {
public:
	circle();
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	Point getCoord();
	Point getProizvCoord();
	void show();
};

class ellipse : public Figure {

public:
	ellipse();
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	Point getCoord();
	Point getProizvCoord();
	void show();
};

class helixes : public Figure {
public:
	double step = 2.0;
	helixes();
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	Point getCoord();
	Point getProizvCoord();
	void show();
};
