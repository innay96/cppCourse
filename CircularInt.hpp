#include <iostream>
using namespace std;

#pragma once

class CircularInt{
	public:
		int hour;
		int min;
		int max;
		CircularInt(int minimum, int maximum) { min = 	minimum; max = maximum; hour = min;}
		CircularInt(CircularInt &ci) { min = ci.min; max = ci.max; hour = ci.hour;}

// overload + operator
friend CircularInt operator+(CircularInt &ci, int a){
	ci.hour = ci.hour + a;
	ci.hour = ci.getRange();
	return ci;	
}

//overload + operator when obj + obj
friend CircularInt& operator+(CircularInt &ci, CircularInt &ci2){
	ci.hour = ci.hour + ci2.hour;
	ci.hour = ci.getRange();
	return ci;	
}

// overload += operator
CircularInt& operator+=(int n){
	this->hour = (this->hour + n);	
	if(hour > max){
		int temp = (this->hour % max);
		this->hour = temp;
	}
	return *this;	
}

int operator-(){
	return max-this->hour;
}

// overload - operator obg - int  
friend CircularInt operator-(CircularInt &ci, int n){
	int r= ci.max - ci.min +1;
	int temp = (ci.hour - ci.min - n) % r;
	int ans = (temp + r) % r + ci.min;
	ci.hour = ans;
	return ci;
}

// overload - operator when int - obj
friend CircularInt operator-(int a, CircularInt &ci){
	int r= ci.max - ci.min +1;
	int temp = (a - ci.hour - ci.min) % r;
	int ans = (temp + r) % r + ci.min;
	ci.hour = ans;
	return ci;	
}

//overload - operator when obj - obj
friend int operator-(CircularInt &ci, CircularInt &ci2){
	int r= ci.max - ci.min +1;
	int temp = (ci.hour - ci2.hour - ci.min) % r;
	int ans = (temp + r) % r + ci.min;
	ci.hour = ans;
	return ci.hour;	
}

// overload -= operator
CircularInt& operator-=(int n){
	int r= max - min +1;
	int temp = (this->hour - min - n) % r;
	int ans = (temp + r) % r + min;
	this->hour = ans;
	return *this;	
}

// overload prefix ++ operator
CircularInt operator++(){
	hour++;
	hour =this->getRange();
	return 	*this;
}

// overload postfix ++ operator
CircularInt operator++(int){
	CircularInt H(*this); // saves the original value
	hour++;
	hour = this->getRange();
	return H; // returns the original value	
}

// overload prefix -- operator
CircularInt operator--(){
	hour--;
	hour = this->getRange();
	return 	*this;
}

// overload postfix -- operator
CircularInt operator--(int){
	CircularInt H(*this); // saves the original value
	hour--;
	hour = this->getRange();
	return H; // returns the original value	
}

// overload * operator obj * int
friend int operator*(CircularInt &ci ,int n){
	ci.hour = (ci.hour*n) % ci.max;
	ci.hour = ci.getRange();
	return ci.hour;
}

// overload * operator obj * obj
friend int operator*(CircularInt &ci ,CircularInt &ci2){
	ci.hour = (ci.hour*ci2.hour) % ci.max;
	ci.hour = ci.getRange();
	return ci.hour;
}

// overload *= operator
int operator*=(int n){
	hour = (hour*n);
	hour = getRange();
	return hour;
}

//overload = operator
CircularInt& operator= (const CircularInt& ci){
	min = ci.min;
	max = ci.max;
	hour = ci.hour;
	return *this;
}

// overload output stream (<<) operator
friend ostream& operator<< (ostream& os, const CircularInt &n){
	os << n.hour;
	return os;
}

// overload input stream (>>) operator
friend istream& operator<< (istream& is, CircularInt &n){
	is >> n.hour >> n.min >> n.max;
	return is;
}

//checks if the hour is in the range
int getRange(){
	if(hour < min)
		return max - (min - hour + 1);
	else if(hour > max)
		return (hour % max);
	return hour;
}
/*
//distructor
~CircularInt(){
delete &min;
delete &max;
delete &hour;
}*/
};
