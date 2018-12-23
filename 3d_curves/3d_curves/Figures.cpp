#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include"Figures.h"

using namespace std;

//RANDOM FUNC
float random(float min, float max)
{
	return (float)(rand()) / RAND_MAX * (max - min) + min;
}

//CIRCLE
circle::circle() {
	figure_type = Circle_ID;
}
void circle::setT(float t1)
{
	t = t1;
}
void circle::setX0()
{
	coord0.x = random(0.0, 10.0);
}
void circle::setY0()
{
	coord0.y = random(0.0, 10.0);
}
void circle::setZ0()
{
	coord0.z = 0;
}
void circle::setRadius()
{
	rX = random(1.0, 100.0);
}
float circle::getX()
{
	coord.x = coord0.x + rX * cos(t*PI / 180);
	return coord.x;
}
float circle::getY()
{
	coord.y = coord0.y + rX * sin(t*PI / 180);
	return coord.y;
}
float circle::getProizvX()
{
	proizv.x = -rX * sin(t*PI / 180);
	return proizv.x;
}
float circle::getProizvY()
{
	proizv.y = rX * cos(t*PI / 180);
	return proizv.y;
}
void circle::show()
{
	cout << "circle" << "  Radius:" << rX << "  Coordinate: X:" << getX() << "  Y:" << getY() << "   Derivative: X':" << getProizvX() << "  Y':" << getProizvY() << "  Yx':" << (getProizvY() / getProizvX()) << endl;
}

//ELLIPSE
ellipse::ellipse() {
	figure_type = Ellipse_ID;
}
void ellipse::setT(float t1)
{
	t = t1;
}
void ellipse::setX0()
{
	coord0.x = random(0.0, 10.0);
}
void ellipse::setY0()
{
	coord0.y = random(0.0, 10.0);
}
void ellipse::setZ0()
{
	coord0.z = 0;
}
void ellipse::setRadius()
{
	rX = random(1.0, 100.0);
	rY = random(1.0, 100.0);
}
float ellipse::getX()
{
	coord.x = coord0.x + rX * cos(t*PI / 180);
	return coord.x;
}
float ellipse::getY()
{
	coord.y = coord0.y + rY * sin(t*PI / 180);
	return coord.y;
}
float ellipse::getProizvX()
{
	proizv.x = -rX * sin(t*PI / 180);
	return proizv.x;
}
float ellipse::getProizvY()
{
	proizv.y = rY * cos(t*PI / 180);
	return proizv.y;
}
void ellipse::show()
{
	cout << "ellipse" << "  Radius_X:" << rX << "  Radius_Y:" << rY << "  Coordinate: X:" << getX() << "  Y:" << getY() << "   Derivative: X':" << getProizvX() << "  Y':" << getProizvY() << "  Yx':" << (getProizvY() / getProizvX()) << endl;
}


//HELIXES
helixes::helixes() {
	figure_type = Helixes_ID;
}
void helixes::setT(float t1)
{
	t = t1;
}
void helixes::setX0()
{
	coord0.x = random(0.0, 10.0);
}
void helixes::setY0()
{
	coord0.y = random(0.0, 10.0);
}
void helixes::setZ0()
{
	coord0.z = random(0.0, 10.0);
}
void helixes::setRadius()
{
	rX = random(1.0, 100.0);
}
float helixes::getX()
{
	coord.x = coord0.x + rX * cos(t*PI / 180);
	return coord.x;
}
float helixes::getY()
{
	coord.y = coord0.y + rX * sin(t*PI / 180);
	return coord.y;
}
float helixes::getZ()
{
	coord.z = coord0.z + step * t;
	return coord.z;
}
float helixes::getProizvX()
{
	proizv.x = -rX * sin(t*PI / 180);
	return proizv.x;
}
float helixes::getProizvY()
{
	proizv.y = rX * cos(t*PI / 180);
	return proizv.y;
}
float helixes::getProizvZ()
{
	proizv.z = 0;
	return proizv.z;
}
void helixes::show()
{
	cout << "helixes" << "  Radius:" << rX << "  Coordinate: X:" << getX() << "  Y:" << getY() << "  Z:" << getZ() << "   Derivative: X':" << getProizvX() << "  Y':" << getProizvY() << "  Z':" << getProizvZ() << "  Yx':" << (getProizvY() / getProizvX()) << endl;
}