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
	
	
	//overload = operator
	CircularInt& operator= (const CircularInt& ci){
		this->min = ci.min;
		this->max = ci.max;
		this->hour = ci.hour;
		return *this;
	}
	
	//overload = int
	CircularInt& operator= (int a){
		this->hour = a;
		return *this;
	}
	
	
	
	//overload (/) operator when obj/int
	int operator/(int n){
		int check=this->hour;
		this->hour= this->hour/n;
		if(this->hour*n!=this->hour){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(n)+"="+to_string(this->hour);
	 		this->hour=check;
	 		throw msg ;//exception
		}
		this->hour=this->getRange();
		return this->hour;
	}
	
	//overload (/) operator when int/obj
	friend int operator/(int n,const CircularInt &ci){
		CircularInt temp(ci);
		temp.hour= n/ci.hour;
		if(temp.hour*n!=ci.hour){
			string msg="There is no number x in {"+to_string(ci.min)+","+to_string(ci.max)+"} such that x*"+to_string(n)+"="+to_string(ci.hour);
	 	
	 		throw msg ;//exception
		}
		temp.hour=temp.getRange();
		return temp.hour;
	}
	
	//overload (/) operator when obj/obj
	int operator/(const CircularInt &ci2){
		int check=this->hour;
		this->hour= this->hour/ci2.hour;
		if(this->hour*ci2.hour!=this->hour){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(ci2.hour)+"="+to_string(this->hour);
	 		this->hour=check;
	 		throw msg ;//exception
		}
		this->hour=this->getRange();
		return this->hour;
	}
	
	
	
	// overload output stream (<<) operator
	friend ostream& operator<< (ostream& os, const CircularInt &n){
		os << n.hour;
		return os;
	}
	
	// overload input stream (>>) operator
	friend istream& operator>> (istream& is, CircularInt &n){
		is >> n.hour >> n.min >> n.max;
		return is;
	}
	
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


