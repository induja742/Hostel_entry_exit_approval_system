#include<iostream>
#include<fstream>
#include"header_files/student.h"
using namespace std;
int main(){    
    int choice;
    while(1){
        cout<<"For registering press 1:"<<endl;
        cout<<"If done press 2:"<<endl;
        cin>>choice;
        if(choice==1){
            string name,branch,hostel;
            int year;
            long roll_no;
            cout<<"Enter name(for spaces use underscores): ";cin>>name;
            cout<<"Enter roll_no: ";cin>>roll_no;
            cout<<"Enter branch(for spaces use underscores): ";cin>>branch;
            cout<<"Enter hostel(for spaces use underscores): ";cin>>hostel;
            cout<<"Enter year(in numeric form): ";cin>>year;
            Student a(name,roll_no,hostel,branch,year);
            ofstream fout("records/registered_students",ios::app);
            if(!fout){
                cerr<<"Error"<<endl;
                return 1;
            }
            fout<<a<<"\n";
            fout.close();
        }
        else{
            break;
        }
    }
    return 0;
}