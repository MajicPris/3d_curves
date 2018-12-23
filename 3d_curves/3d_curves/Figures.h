#pragma once
#define PI 3.14159265
using namespace std;

enum Figure_Type { Circle_ID, Ellipse_ID, Helixes_ID };

float random(float min, float max);

struct Point {
	float x, y, z;
};

class Figure {
public:
	Point coord0, coord, proizv;
	float rX, rY;
	float t;
	double step = 2.0;
	Figure_Type figure_type;
	virtual void show() { cout << "figure"; }
	virtual void setRadius() = 0;
	virtual void setX0() = 0;
	virtual void setY0() = 0;
	virtual void setZ0() = 0;
	virtual void setT(float t1) = 0;
	friend bool operator> (const Figure &f1, const Figure &f2)
	{
		return f1.rX >f2.rX;
	}
	friend bool operator< (const Figure &f1, const Figure &f2)
	{
		return f1.rX <f2.rX;
	}

};


class circle : public Figure {
public:
	circle();
	void setT(float t1);
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	float getX();
	float getY();
	float getProizvX();
	float getProizvY();
	void show();
};

class ellipse : public Figure {

public:
	ellipse();
	void setT(float t1);
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	float getX();
	float getY();
	float getProizvX();
	float getProizvY();
	void show();
};

class helixes : public Figure {
public:
	helixes();
	void setT(float t1);
	void setX0();
	void setY0();
	void setZ0();
	void setRadius();
	float getX();
	float getY();
	float getZ();
	float getProizvX();
	float getProizvY();
	float getProizvZ();
	void show();
};