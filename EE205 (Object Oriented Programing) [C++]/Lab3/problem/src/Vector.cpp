#include "../include/Vector.hpp"
#include <utility>
#include <iostream>

 Vector::Vector(){
 	length = 0;
 	capacity = 1;
        arr = new int[capacity];

}
void Vector::double_capacity(){
	capacity *= 2;
	int* temp = new int[capacity];
	//char *temp = new char[this->capacity * 2];
	
	for(int i=0; i < length;i++){
		temp[i]=arr[i];
	}
	//this->capacity *= 2;
	//int *temp2 = this->arr;
	delete[] arr;
	arr = temp;
	//this->arr = temp;
	//delete [] temp2;
}


	
Vector::Vector(const Vector& other){
	length = other.length;
	capacity = other.capacity;
	arr = new int[other.capacity];
     
     for(int i=0;i < length;i++) {
          arr[i] = other.arr[i];
     }
}
	/*
	this->arr = new char[other.capacity];
	for(int i = 0;i < other.length;i++){
		temp[i] = arr[i];
	}
	delete [] arr;
	arr = temp;
}
*/

Vector::Vector(Vector&& other){
	arr = new int[other.capacity];
	for(int i=0; i < other.length; i++){
	arr[i] = other.arr[i];
	}

	length = other.length;
	capacity = other.capacity;
	delete[] other.arr;
	other.length = 0;
	other.capacity = 0;
}
Vector::~Vector(){
	delete [] arr;
	length = 0;
	capacity = 0;
}

void Vector::append(int num){
	if(this->length == this->capacity){
		this->double_capacity();
	}
	this->arr[this->length] = num;
	this->length++;
}

void Vector::insert(int index, int num){
	if(index < 0 || index > this->length){
		throw "Index is out of bounds";
	}
	else if(this->length == this->capacity){
		this->double_capacity();
	}
	else if(index == this->length){
		this->arr[length] = num;
	}
	else{
		for(int i = index;i<length;i++){
		int temp = this->arr[i];
		this->arr[i] = num;
		num = temp;
	}
	this->length++;
	}
}

void Vector::remove(int index){
	if(index < 0 || index > this->length){
		throw "Index is out of bounds";
	}
	else if(index == this-> length-1){
		this->length--;
	}
	else{
		for(int i = index;i<length;i++){
		arr[i] = this->arr[i+1];
	}
	this->length--;
}

}
int Vector::get(int index) const{
	if(index < 0 || index == length)
	throw "Index is not in bounds";
	else{
	return arr[index];
}
}
std::size_t Vector::size() const{
	return this->length;
}

int& Vector::operator[] (int index){
	if(index<0 || index == length)
	throw "Index is not in bounds";
	else
	return arr[index];
}

