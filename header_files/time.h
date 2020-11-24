#ifndef TIME_H
#define TIME_H
#include<iostream>
class Time{
    public:
    int hours;
    int min;
    Time() = default;
    Time(int hours, int min);
    std::string toString();
    friend std::ostream &operator<<(std::ostream &dout,const Time &rhs);
    friend std::istream &operator>>(std::istream &din, Time &rhs);
};
#endif