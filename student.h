#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>
class Student{
    std::string name;
    long roll_no;
    std::string hostel;
    std::string branch;
    int year;
    public:
    Student() = default;
    Student(std::string name_val, long roll_val, std::string hostel_val, std::string branch_val,int year_val);
    std::string get_name();
    std::string get_hostel();
    std::string get_branch();
    long get_roll_no();
    int get_year();
    friend std::ostream &operator<<(std::ostream &dout, const Student &rhs);
};

#endif