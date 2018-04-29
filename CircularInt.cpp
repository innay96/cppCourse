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
    	temp.hour=temp.hour%a;
    	temp.hour=temp.getRange();
    	return temp;
    }
    //overload % operator when obj % obj
   CircularInt CircularInt::operator%(const CircularInt &ci){
    	CircularInt temp(this->min,this->max);
    	temp.hour=temp.hour%ci.hour;
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
	    if(a>this->hour&&a==this->hour) return true;
        return false;
	}
	
	//overload <= operator when obj <= obj
	bool CircularInt::operator<=(const CircularInt &ci){
	    if(ci.hour>this->hour&&ci.hour==this->hour) return true;
        return false;
	}
	
	//overload <= operator when int <= obj
	bool operator<=(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a<ci.hour&&a==ci.hour) return true;
        return false;
    }

    //overload >= operator when obj >= int
	bool CircularInt::operator>=(int a){
	   a=realHour(a,this->min,this->max);
	    if(a<this->hour&&a==this->hour) return true;
        return false;
	}
	
	//overload >= operator when obj >= obj
	bool CircularInt::operator>=(const CircularInt &ci){
	    if(ci.hour < this->hour&&ci.hour==this->hour) return true;
        return false;
	}
	
	//overload >= operator when int >= obj
	bool operator>=(int a,const CircularInt &ci){
         a=realHour(a,ci.min,ci.max);
	    if(a>ci.hour&&a==ci.hour) return true;
        return false;
    }
    
    CircularInt& CircularInt::operator/=(int n){
    	int check=this->hour;	
		this->hour= this->hour/n;
		if(this->hour*n!=check){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(n)+"="+to_string(check);
 			throw msg ;//exception
		}
		this->hour=this->getRange();
		return *this;
    }
    
	CircularInt& CircularInt::operator/=(const CircularInt &ci){
		int check=this->hour;
		this->hour= this->hour/ci.hour;
		if(this->hour*ci.hour!=check){
			string msg="There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(ci.hour)+"="+to_string(check);
 			throw msg ;//exception
		}
		this->hour=this->getRange();
		return *this;
	}
	
	int operator/=(int n ,const CircularInt &ci){
		n=realHour(n,ci.min,ci.max);
		int ans= n/ci.hour;
		if(ci.hour*ans!=n){
			string msg="There is no number x in {"+to_string(ci.min)+","+to_string(ci.max)+"} such that x*"+to_string(ci.hour)+"="+to_string(n);
 			throw msg ;//exception
		}
		return ans;	
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

	CircularInt operator+(int a,const CircularInt &ci2){
		CircularInt temp(ci2.min,ci2.max);
		temp.hour = ci2.hour + a;
		temp.hour = temp.getRange();
		return temp;
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

	int operator+=(int n, const CircularInt &ci2){
		n = (ci2.hour + n);	
		n = realHour(n,ci2.min,ci2.max);
		return n;
	}

	//overload - operator changes the object to negative
	int CircularInt::operator-(){
		return max-this->hour;
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
	CircularInt operator-(int a, CircularInt &ci){
		int r= ci.max - ci.min +1;
		int temp = (a - ci.hour - ci.min) % r;
		int ans = (temp + r) % r + ci.min;
		ci.hour = ans;
		return ci;	
	}
	
	//overload - operator when obj - obj
	CircularInt CircularInt::operator-(CircularInt &ci2){
		int r= this->max - this->min +1;
		int temp = (this->hour - ci2.hour - this->min) % r;
		int ans = (temp + r) % r + this->min;
		CircularInt Cir(this->min,this->max);
		Cir.hour = ans;
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
	
	int operator-=(int n, const CircularInt &ci2){
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
		this->hour = (hour*ci.hour);
		this->hour = this->getRange();
		return *this;
	}
	CircularInt operator*=(int n, const CircularInt &ci){
		CircularInt temp(ci.min,ci.max);
		temp.hour = (temp.hour*n);
		temp.hour = temp.getRange();
		return temp;
	}
	
	int realHour(int a,int min,int max){
	if(a < min)
		return max - (min - a + 1);
	else if(a > max)
		return (a % max);
	return a;
}

