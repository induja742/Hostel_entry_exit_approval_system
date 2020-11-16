#include<iostream>
#include"header_files/time.h"
using namespace std;

Time::Time(int hours, int min): hours{hours},min{min}{}

ostream &operator<<(ostream &dout,const Time &rhs){
    dout<<rhs.hours<<":"<<rhs.min;
    return dout;
}

istream &operator>>(istream &din,Time &rhs){
    cin>>rhs.hours>>rhs.min;
    return din;
}