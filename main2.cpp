#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#include "CircularInt.hpp"
int main(){
    
    CircularInt hour {1, 12}; 
    CircularInt hour2 {1, 12}; 
    CircularInt hour3 {1, 12}; 
    
    hour=hour+2;//hour=3
	hour=hour+hour2;//hour=3+1=4
	hour3=4+hour;//plus=4+4=8
	cout << hour3 << endl;//////////8
	
    hour2=hour;//hour2=4
    cout << hour2 << endl;//////////4
    
	hour=hour%2;//hour=12
	
	hour=hour%hour2;//12%4=0=12
	
	hour3 =hour%5;//12%5=2
    cout << hour3 << endl;//////////2
    
    int count=0;
	if(hour==12) count++;
	if(hour==hour2) count--;
	if(4==hour2) count++;
	cout << count << endl;//////////2
	
	count=0;
	if(hour!=12) count++;
	if(hour!=hour2) count--;
	if(4!=hour2) count++;
	cout << count << endl;//////////-1
	
	count=0;
	if(hour<12) count++;
	if(hour<hour2) count--;
	if(4<hour2) count++;
	cout << count << endl;//////////0
	
    count=0;
	if(hour>12) count++;
	if(hour>hour2) count--;
	if(4>hour2) count++;
	cout << count << endl;//////////-1
	
	count=0;
	if(hour<=12) count++;
	if(hour<=hour2) count--;
	if(4<=hour2) count++;
	cout << count << endl;//////////2
	
    count=0;
	if(hour>=12) count++;
	if(hour>=hour2) count--;
	if(4>=hour2) count++;
	cout << count << endl;//////////1
	
	hour /= 2;//hour=6
		try {
	hour/=hour2;//hour=6/4=1X
		} catch (const string& message) {
		cout << message << endl; //////////There is no number x in {1,12} such that x*4=6
	}
	int diveq =12;
	diveq/=hour;//12/6=2
	cout << diveq << endl;//////////2

	hour += 2;//hour=8
	hour+=hour2;//hour=8+4=12
	int pleq =12;
	pleq+=hour2;//12+4=12
	cout << pleq << endl;//////////4
	
	cout << -hour << endl;//////////-12==12
	
	/// hour=12,hour2=4
	
	hour2=hour2-6;//hpur2=4-6=-2=10
	hour=hour-hour2;//hour=12-10=2
	hour3=5-hour;//5-2=3
	cout << hour3 << endl;////////////3
	
    hour2-=2;//hour2=8
	hour2-=hour;//hour2=6
	int dec=30;
	dec-=hour;//dec=30-2=28=4
	cout << dec << endl;/////////////4
	
	/// hour=2,hour2=6
	cout << hour++ << endl;/////////2
	//hour=3
	cout << ++hour << endl;/////////4
	--hour;
	hour--;
	hour2=hour2*2;//hour2=12
	hour=hour*hour2;//hour=12*2=12
	hour3=5*hour;//5*12=
	cout << hour3 << endl;////////////12
    
    hour=9;
    hour2=4;
	hour*=2;//hour=18=6
	hour*=hour2;//hour=6*4=24=12
	int multeq=7;
	multeq*=hour2;//7*4=28=4
	cout << hour << endl;////////////12
	cout << multeq << endl;////////////4
	
	int str;
	hour>>str;
	cout << str << endl;
	int i= 5;
	i>>hour;
	return 0;
	
}