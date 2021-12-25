#include <iostream>
#include <string>
#include "../include/user.hpp"
  
//defoult constructor
User::User(){        
    name = "Name";
    step_count = 0;
    record_time = 0;
}

//constructor
User::User(std::string name){
    this->name = name;    
}

//copy constructor
User::User(const User &cloneUser){
    name = cloneUser.name;
    step_count = cloneUser.step_count;
    record_time = cloneUser.record_time;
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

//print time in normal format
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

//print users info
void User::Print(){
    std::cout<<name<<"   |    "<<step_count<<"      |   ";
    Show_record_time();
    std::cout<<"      |";
}

//destructor
User::~User(){
    //std::cout<<"work destruktor\n";
};


