#include<iostream>
#include<iomanip>
#include<fstream>
#include"header_files/student.h"
using namespace std;
//Utility functions
bool check_record(long key){
    string name,branch,hostel;
    long roll_no;
    int year;
    ifstream fin("records/registered_students");
    while(fin>>name>>roll_no>>branch>>hostel>>year){
        if(roll_no==key){
            return true;
        }
    }
    fin.close();
    return false;
}
int main(){    
    int choice;
    string welcome_string {"Welcome to main-menu"};
    while(1){
        cout<<endl;
        cout<<"=================================="<<endl;
        cout<<"<- "<<welcome_string<<" ->"<<endl;
        cout<<"For registering press 1:"<<endl;
        cout<<"If done press 2:"<<endl;
        cout<<"Press 3 to exit: "<<endl;
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
            bool flag;
            flag = check_record(roll_no);
            if(!flag){
                ofstream fout("records/registered_students",ios::app);
                if(!fout){
                    cerr<<"Error"<<endl;
                    return 1;
                }
                fout<<a<<"\n";
                cout<<"=================================="<<endl;
                cout<<"Successfully registered!"<<endl;
                fout.close();
            }
            else{
                cout<<"=================================="<<endl;
                cout<<"You are already registered! "<<endl;
            }
        }
        else if(choice==2){
            int choice2;
            cout<<"=================================="<<endl;
            cout<<"1.Open entry: "<<endl;
            cout<<"2.Close entry: "<<endl;
            cout<<"3.Apply for outpass: "<<endl;
            cout<<"4.Go back to main-menu "<<endl;
            cin>>choice2;
            switch(choice2){
                case 1: {

                }
                case 2:
                case 3:
                case 4: break;
            }
        }
        else{
            break;
        }
    }
    return 0;
}