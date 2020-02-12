#include"Person.hpp"
#include <iostream>

Person::Person(){
	Point2D temp;
	this -> location = temp;
	this->name = "";
}
Person::Person(std::string name, float x, float y){
	Point2D tempi(x,y);
	this -> location = tempi;
	this -> name = name;
	}
Point2D Person::get_location(){
	return this->location;
}
std::string Person::get_name(){
	return this->name;
}
void Person::set_location(Point2D location){
	this -> location = location;
}
void Person::set_name(std::string name){
	this -> name = name;
}
