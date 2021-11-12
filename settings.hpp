//setings.hpp
#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "input.hpp"

const int Settings_Count = 2;
int Settings_index = 0;

void Settings_Game(const int Center){
    Show_Game_Name(Center);
    int Settings_Col = Center - 3;    
    std::string Settings[Settings_Count]={"Board Size", "Users"};

    for(int i = 0; i < Settings_Count; ++i){
        gotoxy(Settings_Col,15 + i);
        Color_Cout(Settings[i],7); std::cout<<"\n";
    }
    gotoxy(Settings_Col, 15 + Settings_index);
    Color_Cout(Settings[Settings_index],3);

    for(char key_2 = -1; key_2 != 27; ) {

        cbreak();
        key_2 = keypress();

        switch(key_2){

            case 's': case 'S': std::cout<<"S";

            
            case 'w': case 'W': std::cout<<"w";

        }
    }
    normal();
}

#endif
