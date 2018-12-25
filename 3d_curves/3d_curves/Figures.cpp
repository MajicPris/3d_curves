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
	t = 45;
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
Point circle::getCoord()
{
	Point p;
	p.x = coord0.x + rX * cos(t*PI / 180);
	p.y = coord0.y + rX * sin(t*PI / 180);
	p.z = 0;
	return p;
}
Point circle::getProizvCoord()
{
	Point p1;
	p1.x = -rX * sin(t*PI / 180);
	p1.y = rX * cos(t*PI / 180);
	p1.z = 0;
	return p1;
}

void circle::show()
{
	cout <<"circle" << "  Radius:" << rX << "  Coordinate: " << getCoord() << "   Derivative: "<< getProizvCoord()<< endl;
}

//ELLIPSE
ellipse::ellipse() {
	figure_type = Ellipse_ID;
	t = 45;
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
Point ellipse::getCoord()
{
	Point p;
	p.x = coord0.x + rX * cos(t*PI / 180);
	p.y = coord0.y + rY * sin(t*PI / 180);
	p.z = 0;
	return p;
}
Point ellipse::getProizvCoord()
{
	Point p1;
	p1.x = -rX * sin(t*PI / 180);
	p1.y = rY * cos(t*PI / 180);
	p1.z = 0;
	return p1;
}
void ellipse::show()
{
	cout << "ellipse" << "  Radius_X:" << rX << "  Radius_Y:" << rY << "  Coordinate: " << getCoord() << "   Derivative: " << getProizvCoord() << endl;
}


//HELIXES
helixes::helixes() {
	figure_type = Helixes_ID;
	t = 45;
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
Point helixes::getCoord()
{
	Point p;
	p.x = coord0.x + rX * cos(t*PI / 180);
	p.y = coord0.y + rX * sin(t*PI / 180);
	p.z = coord0.z + step * t/(2*PI);
	return p;
}
Point helixes::getProizvCoord()
{
	Point p1;
	p1.x = -rX * sin(t*PI / 180);
	p1.y = rX * cos(t*PI / 180);
	p1.z = step/(2*PI);
	return p1;
}
void helixes::show()
{
	cout << "helixes" << "  Radius:" << rX << "  Coordinate: " << getCoord() << "   Derivative: " << getProizvCoord() << endl;
}
