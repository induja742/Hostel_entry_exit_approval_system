#include"header_files/student.h"
#include<iostream>
#include<string>
using namespace std;


//Constructors
Student::Student(string name_val, long roll_val, string hostel_val, string branch_val,int year_val,string room_val):name{name_val},roll_no{roll_val},hostel{hostel_val},branch{branch_val},year{year_val},room_no{room_val}{}
//Get methods
string Student::get_name(){return name;}
string Student::get_branch(){return branch;}
string Student::get_hostel(){return hostel;}
long Student::get_roll_no(){return roll_no;}
int Student::get_year(){return year;}
string Student::get_room_no(){return room_no;}
//Overloaded operators
ostream &operator<<(ostream &dout, const Student &rhs){
    dout<<rhs.name<<" "<<rhs.roll_no<<" "<<rhs.branch<<" "<<rhs.hostel<<" "<<rhs.year<<" "<<rhs.room_no<<"\n";
    return dout;
}