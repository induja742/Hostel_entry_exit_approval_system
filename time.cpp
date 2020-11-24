#include<iostream>
#include<string>
#include"header_files/time.h"
using namespace std;

Time::Time(int hours, int min): hours{hours},min{min}{}

ostream &operator<<(ostream &dout,const Time &rhs){
    if(rhs.hours<10){
        dout<<"0"<<rhs.hours;
    }
    else{
        dout<<rhs.hours;
    }
    if(rhs.min<10){
        dout<<":0"<<rhs.min;
    }
    else{
        dout<<":"<<rhs.min;
    }
    return dout;
}

istream &operator>>(istream &din,Time &rhs){
    cin>>rhs.hours>>rhs.min;
    return din;
}
std::string Time::toString(){
   string s;
   if(hours<10){
       s+='0';
       s+=to_string(hours);
   } 
   else{
       s+=to_string(hours);
   }
   if(min<10){
       s+='0';
       s+=to_string(min);
   } 
   else{
       s+=to_string(min);
   }
   return s;
}