#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#pragma once

class CircularInt{
	public:
		int hour;
		int min;
		int max;
		CircularInt( int minimum, int maximum) { min = 	minimum; max = maximum; hour = min;}
		CircularInt(CircularInt& ci) { this->min = ci.min; this->max = ci.max; this->hour = ci.hour;}
		CircularInt(const CircularInt& ci) { this->min = ci.min; this->max = ci.max; this->hour = ci.hour;}
		
	CircularInt operator%(int a);
	CircularInt operator%(const CircularInt &ci);	
	friend CircularInt operator%(int a,const CircularInt &ci);
    
	bool operator==(int a);
	bool operator==(const CircularInt &ci);
	friend bool operator==(int a,const CircularInt &ci);
	
	bool operator!=(int a);
	bool operator!=(const CircularInt &ci);
	friend bool operator!=(int a,const CircularInt &ci);
	
	bool operator<(int a);
	bool operator<(const CircularInt &ci);
	friend bool operator<(int a,const CircularInt &ci);
	
	bool operator>(int a);
	bool operator>(const CircularInt &ci);
	friend bool operator>(int a,const CircularInt &ci);
	
	bool operator<=(int a);
	bool operator<=(const CircularInt &ci);
	friend bool operator<=(int a,const CircularInt &ci);
	
	bool operator>=(int a);
	bool operator>=(const CircularInt &ci);
	friend bool operator>=(int a,const CircularInt &ci);
	
	CircularInt& operator/=(int n);
	CircularInt& operator/=(const CircularInt &ci);
	friend int& operator/=(int& n ,const CircularInt &ci);
	
	CircularInt operator+(int a);
	CircularInt operator+(const CircularInt &ci2);
	friend CircularInt operator+(int a,const CircularInt &ci2);
	
	CircularInt& operator+=(int n);
	CircularInt& operator+=(const CircularInt &ci2);
	friend int& operator+=(int& n, const CircularInt &ci2);
	
	int operator-();
	
	CircularInt operator-(int n);
	CircularInt operator-(CircularInt &ci2);
	friend CircularInt operator-(int a,const CircularInt &ci);
	
	CircularInt& operator-=(int n);
	CircularInt& operator-=(const CircularInt &ci2);
	friend int& operator-=(int& n, const CircularInt &ci2);
	
	CircularInt& operator*(int n);
	CircularInt& operator*( const CircularInt &ci2);
	friend CircularInt operator*(int n, const CircularInt &ci);
	
	CircularInt& operator*=(int n);
	CircularInt& operator*=(const CircularInt &ci);
	friend int& operator*=(int& n, const CircularInt &ci);
	
	CircularInt operator++();
	CircularInt operator++(int);
	
	CircularInt operator--();
	CircularInt operator--(int);
	
	CircularInt& operator= (const CircularInt& ci);
	CircularInt& operator= (int a);
	
	int operator/(int n);
	friend int operator/(int n,const CircularInt &ci);
	int operator/(const CircularInt &ci2);
	
	friend ostream& operator<< (ostream& os, const CircularInt &n);
	friend istream& operator>> (istream& is, CircularInt &n);
	int& operator>>(int& n);
	friend CircularInt& operator>>(int n,CircularInt& ci);
	string& operator>>(string& n);
	float& operator>>(float& n);
	double& operator>>(double& n);

	
	//checks if the hour is in the range
	int getRange(){
		if(hour < min)
			return max - ((-hour)%max);
		else if(hour > max){
			int ans= (hour % max);
			if(ans==0) return max;
			return ans;
		}
		return hour;
	}
};


