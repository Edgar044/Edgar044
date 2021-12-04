#include <iostream>
#include "user.hpp"
#include <string>
                  
User::User(){        //defolt
    name = "Name";
    step_count = 99999;
    record_time = 99999;
}

User::User(std::string name){ //constructor
    this->name = name;    
}

void User::Set_name(std::string name){ //
    this->name = name;    
}

std::string User::Get_name(){
    return name;
}
void User::Show_name(){
    std::cout << name;
}

void User::Show_record_time(){
    std::cout << record_time/3600 << ":"<< (record_time % 3600) / 60<< ":"<< (record_time % 3600 ) % 60 ;
}

void User::Show_step_count(){
    std::cout << step_count;
}

void User::Set_record_time(int time){
    record_time = time;
}

int User::Get_record_time(){
    return record_time;
}
void User::Set_step_count(int count){
    step_count = count;
}
int User::Get_step_count(){
    return step_count;
}

void User::Print(){
    std::cout<<name<<"   |    "<<step_count<<"      |   ";
    Show_record_time();
    std::cout<<"      |";
}

void User::Copy(const User &cloneUser){
    name = cloneUser.name;
    step_count = cloneUser.step_count;
    record_time = cloneUser.record_time;
}


User::~User(){
    //std::cout<<"work destruktor\n";
};


