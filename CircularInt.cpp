#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#include "CircularInt.hpp"

/////to do- what is a? 32 have no meaning for example..
int realHour(int a,int min,int max);
    //overload % operator when obj % int
    CircularInt CircularInt::operator%(int a){
    	CircularInt temp(this->min,this->max);
    	temp.hour=this->hour%a;
    	temp.hour=temp.getRange();
    	return temp;
    }
    //overload % operator when obj % obj
   CircularInt CircularInt::operator%(const CircularInt &ci){
    	CircularInt temp(this->min,this->max);
    	temp.hour=this->hour%ci.hour;
    	temp.hour=temp.getRange();
    	return temp;
   }
   
   CircularInt operator%(int a,const CircularInt &ci){
    	CircularInt temp(ci.min,ci.max);
    	temp.hour= a % ci.hour;
    	temp.hour=temp.getRange();
    	return temp;
    }
   
    //overload == operator when obj == int
    bool  CircularInt::operator==(int a){
        a=realHour(a,this->min,this->max);
        if(a==this->hour) return true;
        return false;
    }
    
    //overload == operator when obj == obj
	bool  CircularInt::operator==(const CircularInt &ci){
	     if(ci.hour==this->hour) return true;
        return false;
	}
	
	bool operator==(int a,const CircularInt &ci){
	 a=realHour(a,ci.min,ci.max);
        if(a==ci.hour) return true;
        return false;
	}
	
	//overload != operator when obj != int
    bool CircularInt::operator!=(int a){
        a=realHour(a,this->min,this->max);
       if(a==this->hour) return false;
        return true; 
    }
    
    //overload != operator when obj != obj
	bool CircularInt::operator!=(const CircularInt &ci){
	    if(ci.hour==this->hour) return false;
        return true; 
	}
	
	bool operator!=(int a,const CircularInt &ci){
	  a=realHour(a,ci.min,ci.max);
       if(a==ci.hour) return false;
        return true; 
	}
	
	//overload < operator when obj < int
	bool CircularInt::operator<(int a){
	   a=realHour(a,this->min,this->max);
	    if(a>this->hour) return true;
        return false;
	}
	
	//overload < operator when obj < obj
	bool CircularInt::operator<(const CircularInt &ci){
	    if(ci.hour>this->hour) return true;
        return false;
	}
	
	//overload < operator when int < obj
	bool operator<(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a<ci.hour) return true;
        return false;
    }

    //overload > operator when obj > int
	bool CircularInt::operator>(int a){
	   a=realHour(a,this->min,this->max);
	    if(a<this->hour) return true;
        return false;
	}
	
	//overload > operator when obj > obj
	bool CircularInt::operator>(const CircularInt &ci){
	    if(ci.hour < this->hour) return true;
        return false;
	}
	
	//overload > operator when int > obj
	bool operator>(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a>ci.hour) return true;
        return false;
    }
//////

	//overload <= operator when obj <= int
	bool CircularInt::operator<=(int a){
	   a=realHour(a,this->min,this->max);
	    if(a>this->hour||a==this->hour) return true;
        return false;
	}
	
	//overload <= operator when obj <= obj
	bool CircularInt::operator<=(const CircularInt &ci){
	    if(ci.hour>this->hour||ci.hour==this->hour) return true;
        return false;
	}
	
	//overload <= operator when int <= obj
	bool operator<=(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a<ci.hour||a==ci.hour) return true;
        return false;
    }

    //overload >= operator when obj >= int
	bool CircularInt::operator>=(int a){
	   a=realHour(a,this->min,this->max);
	    if(a<this->hour||a==this->hour) return true;
        return false;
	}
	
	//overload >= operator when obj >= obj
	bool CircularInt::operator>=(const CircularInt &ci){
	    if(ci.hour < this->hour||ci.hour==this->hour) return true;
        return false;
	}
	
	//overload >= operator when int >= obj
	bool operator>=(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a>ci.hour||a==ci.hour) return true;
        return false;
    }
    
	//overload /= operator when obj /= int
    CircularInt& CircularInt::operator/=(int n){
    	int check=this->hour;	
		this->hour= this->hour/n;
		if(this->hour*n!=check){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(n)+"="+to_string(check);
 			this->hour=check;
 			throw msg ;//exception
		}
		this->hour=this->getRange();
		return *this;
    }
    
	//overload /= operator when obj /= obj
	CircularInt& CircularInt::operator/=(const CircularInt &ci){
		int check=this->hour;
		this->hour= this->hour/ci.hour;
		if(this->hour*ci.hour!=check){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(ci.hour)+"="+to_string(check);
 			this->hour=check;
 			throw msg ;//exception
		}
		this->hour=this->getRange();
		return *this;
	}
	
	//overload /= operator when int /= obj
	int& operator/=(int& n ,const CircularInt &ci){
		n=realHour(n,ci.min,ci.max);
		int ans=n;
		n= n/ci.hour;
		if(ci.hour*n!=ans){
			string msg="There is no number x in {"+to_string(ci.min)+","+to_string(ci.max)+"} such that x*"+to_string(ci.hour)+"="+to_string(ans);
 			throw msg ;//exception
		}
		return n;	
	}
    
    // overload + operator
	CircularInt CircularInt::operator+(int a){
		CircularInt temp(this->min,this->max);
		temp.hour = this->hour + a;
		temp.hour = temp.getRange();
		return temp;	
	}

	//overload + operator when obj + obj
	CircularInt CircularInt::operator+(const CircularInt &ci2){
		CircularInt temp(this->min,this->max);
		temp.hour = this->hour + ci2.hour;
		temp.hour = temp.getRange();
		return temp;	
	}

	//overload + operator when int + obj
	int& operator+(int a,const CircularInt &ci){
		//CircularInt temp(ci.min,ci.max);
		a=realHour(a,ci.min,ci.max);
		a = ci.hour + a;
		//temp.hour = a;
		//temp.hour = temp.getRange();
		return a;
	}

	// overload += operator
	CircularInt& CircularInt::operator+=(int n){
		this->hour = (this->hour + n);	
		this->hour = this->getRange();
		return *this;	
	}
	
	CircularInt& CircularInt::operator+=(const CircularInt &ci2){
			this->hour = (this->hour + ci2.hour);	
			this->hour = this->getRange();
		return *this;
	}

	int& operator+=(int& n, const CircularInt &ci2){
		n = (ci2.hour + n);	
		n = realHour(n,ci2.min,ci2.max);
		return n;
	}

	//overload - operator changes the object to negative
	int CircularInt::operator-(){
		return max-(this->hour%this->max);
	}

	// overload - operator obg - int  
	CircularInt CircularInt::operator-(int n){
		int r= this->max - this->min +1;
		int temp = (this->hour - this->min - n) % r;
		int ans = (temp + r) % r + this->min;
		CircularInt Cir(this->min,this->max);
		Cir.hour = ans;
		return Cir;
	}
	
	// overload - operator when int - obj
	CircularInt operator-(int a,const CircularInt &ci){
		CircularInt temp(ci.min,ci.max);
		temp.hour =a-ci.hour;
		temp.hour =temp.getRange();
		return temp;	
	}
	
	//overload - operator when obj - obj
	CircularInt CircularInt::operator-(CircularInt &ci2){
		CircularInt Cir(this->min,this->max);
		Cir.hour = this->hour-ci2.hour;
		Cir.hour=Cir.getRange();
		return Cir;	
	}
	
	// overload -= operator
	CircularInt& CircularInt::operator-=(int n){
		int r= max - min +1;
		int temp = (this->hour - min - n) % r;
		int ans = (temp + r) % r + min;
		this->hour = ans;
		return *this;	
	}
	
	CircularInt& CircularInt::operator-=(const CircularInt &ci2){
		this->hour=this->hour-ci2.hour;
		this->hour = this->getRange();
		return *this;		
	}
	
	int& operator-=(int& n, const CircularInt &ci2){
		n=n-ci2.hour;
		n=realHour(n,ci2.min,ci2.max);
		return n;
	}
	
		// overload * operator obj * int
	CircularInt& CircularInt::operator*(int n){
		this->hour = (this->hour*n) % this->max;
		this->hour = this->getRange();
		return *this;
	}
	
	// overload * operator obj * obj
	CircularInt& CircularInt::operator*(const CircularInt &ci2){
		this->hour = (this->hour*ci2.hour) % this->max;
		this->hour = this->getRange();
		return *this;
	}
	
	CircularInt operator*(int n, const CircularInt &ci){
		CircularInt temp(ci.min,ci.max);
		temp.hour=n*ci.hour;
		temp.hour=temp.getRange();
		return temp;
	}
	
	// overload *= operator
	CircularInt& CircularInt::operator*=(int n){
		this->hour = (this->hour*n);
		this->hour = this->getRange();
		return *this;
	}
	
	CircularInt& CircularInt::operator*=(const CircularInt &ci){
		this->hour = (this->hour*ci.hour);
		this->hour = this->getRange();
		return *this;
	}
	int& operator*=(int& n, const CircularInt &ci){
		
		n=n*ci.hour;
		n=realHour(n,ci.min,ci.max);
		return n;
	}

		
	// overload prefix ++ operator
	CircularInt CircularInt::operator++(){
		hour++;
		hour =this->getRange();
		return 	*this;
	}
	
	// overload postfix ++ operator
	CircularInt CircularInt::operator++(int){
		CircularInt H(*this); // saves the original value
		hour++;
		hour = this->getRange();
		return H; // returns the original value	
	}
	
	// overload prefix -- operator
	CircularInt CircularInt::operator--(){
		hour--;
		hour = this->getRange();
		return 	*this;
	}
	
	// overload postfix -- operator
	CircularInt CircularInt::operator--(int){
		CircularInt H(*this); // saves the original value
		hour--;
		hour = this->getRange();
		return H; // returns the original value	
	}
	
	
	//overload = operator
	CircularInt& CircularInt::operator= (const CircularInt& ci){
		this->min = ci.min;
		this->max = ci.max;
		this->hour = ci.hour;
		return *this;
	}
	
	//overload = int
	CircularInt& CircularInt::operator= (int a){
		this->hour = a;
		return *this;
	}
	
	
	
	//overload (/) operator when obj/int
	int CircularInt::operator/(int n){
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
	int operator/(int n,const CircularInt &ci){
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
	int CircularInt::operator/(const CircularInt &ci2){
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
	ostream& operator<< (ostream& os, const CircularInt &n){
		os << n.hour;
		return os;
	}
	
	// overload input stream (>>) operator
	istream& operator>> (istream& is, CircularInt &n){
		is >> n.hour >> n.min >> n.max;
		return is;
	}
	
	int& CircularInt::operator>>(int& n){
		n = this->hour;
		return n;
	}
	
	CircularInt& operator>>(int n,CircularInt& ci){
		ci.hour=n;
		ci.hour=ci.getRange();
		return ci;
	}
	
	string& CircularInt::operator>>(string& n){
		string str=to_string(this->hour);
		n=str;
		return n;
	}
	float& CircularInt::operator>>(float& n){
		n=(float)this->hour;
		return n;
	}
	double& CircularInt::operator>>(double& n){
		n=(double)this->hour;
		return n;
	}
	int realHour(int a,int min,int max){
	if(a < min)
		return max - ((-a)%max);
	else if(a > max){
			int ans= (a % max);
			if(ans==0) return max;
			return ans;
	}
	return a;
}

