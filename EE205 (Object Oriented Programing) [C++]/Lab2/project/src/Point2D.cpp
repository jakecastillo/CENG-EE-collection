#include "Point2D.hpp"
#include <iostream>
using namespace std;

Point2D::Point2D(float q, float w){
	this->x = q;
	this->y = w;
}

Point2D::Point2D(){
	this->x = 0;
	this->y = 0;
}

void Point2D::set_x(float f){
	this->x = f;
}

void Point2D::set_y(float f){
	this->y = f;
}

float Point2D::get_x(void){
	return this->x;
}

float Point2D::get_y(void){
	return this->y;
}

Point2D operator+(const Point2D& lhs,const Point2D& rhs){
	Point2D point2d;
	point2d.x = lhs.x + rhs.x;
	point2d.y = lhs.y + rhs.y;
	return point2d;
}
Point2D operator-(const Point2D& lhs, const Point2D& rhs){
	Point2D point2d;
	point2d.x = lhs.x - rhs.x;
	point2d.y = lhs.y - rhs.y;
	return point2d;
}
Point2D operator*(const Point2D& lhs, const Point2D& rhs){
	Point2D point2d;
	point2d.x = lhs.x * rhs.x;
	point2d.y = lhs.y * rhs.y;
	return point2d;
}
Point2D operator/(const Point2D& lhs, const Point2D& rhs){
	Point2D point2d;
	point2d.x = lhs.x / rhs.x;
	point2d.y = lhs.y / rhs.y;
	return point2d;
}
