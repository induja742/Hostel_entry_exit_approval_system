#include<iostream>
#include<iomanip>
#include<fstream>
#include"header_files/student.h"
#include"header_files/time.h"
using namespace std;
// Utility functions
bool check_registration_record(long key){
    string name,branch,hostel,room_no;
    long roll_no;
    int year;
    bool flag = false;
    ifstream fin("records/registered_students");
    if(fin){
        fin.seekg(0,ios::beg);
        while(fin>>name>>roll_no>>branch>>hostel>>year>>room_no){
            if(roll_no==key){
                flag = true;
                break;
            }
        }
        fin.close();
        return flag;
    }
    cout<<"Registration record not opened"<<endl;
    return false;
}
bool check_entry_record(long key){
    string room_no, t1,t2,date;
    long roll_no;
    ifstream fin("records/entry");
    bool flag = false;
    while(fin>>roll_no>>room_no>>date>>t1>>t2){
        if(key==roll_no && t2=="open1"){
            flag = true;
            break;
        }
    }
    fin.close();
    return flag;
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
            string name,branch,hostel,room_no;
            int year;
            long roll_no;
            cout<<"Enter name(for spaces use underscores): ";cin>>name;
            cout<<"Enter roll_no: ";cin>>roll_no;
            cout<<"Enter branch(for spaces use underscores): ";cin>>branch;
            cout<<"Enter hostel(for spaces use underscores): ";cin>>hostel;
            cout<<"Enter year(in numeric form): ";cin>>year;
            cout<<"Enter room_no(Use underscores for spaces): ";cin>>room_no;
            Student a(name,roll_no,hostel,branch,year,room_no);
            bool flag;
            flag = check_registration_record(roll_no);
            if(!flag){
                ofstream fout("records/registered_students",ios::app);
                if(!fout){
                    cerr<<"Error"<<endl;
                    return 1;
                }
                fout<<a;
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
                    long roll_no;
                    cout<<"Enter your roll_no: "; cin>>roll_no;
                    bool flag = check_registration_record(roll_no);
                    if(flag){
                        if(!check_entry_record(roll_no)){
                            Time exit_time;
                            string room_no,date;
                            cout<<"Enter Hostel exit time (hours min, use 24 hour format): "; cin>>exit_time;
                            cout<<"Enter your room number:(Use underscore in place of spaces) "; cin>>room_no;
                            cout<<"Enter date:(dd/mm/yy) "; cin>>date;
                            ofstream fout("records/entry",ios::app);
                            if(!fout){
                                cerr<<"Error in opening the entry file"<<endl;
                                return 1;
                            }
                            fout<<roll_no<<" "<<room_no<<" "<<date<<" "<<exit_time<<" open1"<<"\n";
                            fout.close();
                            cout<<"Your entry has been made. Enjoy your time!"<<endl;
                        }
                        else{
                            cout<<"You already have an open entry."<<endl;
                        }
                    }
                    else{
                        cout<<"You are not registered! Please register first."<<endl;
                    }
                }
                break;
                case 2:{
                    long roll_no;
                    cout<<"Enter your roll_no: "; cin>>roll_no;
                    bool flag = check_entry_record(roll_no);
                    if(!flag){
                        cout<<"You don't have an open entry"<<endl;
                        break;
                    }
                    else{
                        Time closing_time;
                        cout<<"Enter closing time: "; cin>>closing_time;
                        fstream f_file("records/entry");
                        long search;
                        string a1,a2,a3,time;
                        bool flag =false;
                        while(f_file>>search>>a1>>a2>>a3>>time){
                            if(search==roll_no && time == "open1"){
                                //Pending
                                    f_file<<closing_time;
                                    cout<<"Your entry has been closed"<<endl;
                                    flag = true;
                                    break;
                            }
                        }
                        if(!flag){
                            cout<<"Entry already closed"<<endl;
                        }
                    }    
                
                }
                break;
                case 3:{
                    long roll_no;
                    cout<<"Enter your roll number: "; cin>>roll_no;
                    ifstream fin("records/registered_students");
                    if(!fin){
                        cerr<<"Error in opening student record file. "<<endl;
                        return 1;
                    }
                    string a,b,c,d,e;
                    long key;
                    bool flag = false;
                    while(fin>>a>>key>>b>>c>>d>>e){
                        if(roll_no==key){
                            flag = true;
                            ofstream fout("records/new_outpass");
                            fout<<"Name: "<<a<<"\n";
                            fout<<"Roll Number: "<<roll_no<<"\n";
                            fout<<"Branch: "<<b<<"\n";
                            fout<<"Hostel: "<<c<<"\n";
                            fout<<"Year: "<<d<<"\n";
                            fout<<"Room Number: "<<e<<"\n";
                            string date,days;
                            Time x;
                            cout<<"Enter date of leaving(dd/mm/yy): "; cin>>date;
                            cout<<"Enter return date(dd/mm/yy): "; cin>>days;
                            cout<<"Enter time of leaving(24-hour-format): "; cin>>x;
                            fout<<"Date of leaving: "<<date<<"\n";
                            fout<<"Date of return: "<<days<<"\n";
                            fout<<"Time of leaving the hostel: "<<x<<"\n";
                            cout<<"Your outpass has been generated successfully"<<endl;
                            fout.close();
                            break;
                        }
                    }
                    fin.close();
                    if(!flag){
                        cout<<"You are not registered. Please register first"<<endl;
                    }
                }
                break;
                case 4: break;
            }
        }
        else{
            break;
        }
    }
    return 0;
}