//fun.hpp
#ifndef FUN_H
#define FUN_H

#include <iostream>
#include <stdlib.h>
#include "input.hpp"
#include "start.hpp"

const int Menu_Count = 4;
int Menu_index = 0;
std::string Menu[Menu_Count] = {"Start", "Options", "About", "Exit"};


void Show_Menu(){
    
    
    for(int i=0; i<Menu_Count; ++i){
       gotoxy(18,3 + i); std::cout<<Menu[i]<<"\n";
    }

    
    gotoxy(15,3 + Menu_index); std::cout<<"> \n";

    
    for(char key = -1; key != 27; ){ 

        cbreak();
        key = keypress();
        normal();
        
        switch(key){
            case 'w': case 'W':
                if(Menu_index != 0){
                    gotoxy(15,3 + Menu_index); std::cout<<"  "; 
                    --Menu_index;
                    gotoxy(15,3 + Menu_index); std::cout<<"> \n  ";
                   
                } else {

                    gotoxy(15,3 + Menu_index); std::cout<<"  ";
                    Menu_index = Menu_Count - 1;
                    gotoxy(15,3 + Menu_index); std::cout<<"> \n  ";
                } break;
                
            case 's': case 'S':
                if(Menu_index != Menu_Count - 1){
                    gotoxy(15,3 + Menu_index); std::cout<<"  ";
                    ++Menu_index;
                    gotoxy(15,3 + Menu_index); std::cout<<"> \n  "; 
                } else {

                    gotoxy(15,3 + Menu_index); std::cout<<"  ";
                    Menu_index = 0;
                    gotoxy(15,3 + Menu_index); std::cout<<"> \n  ";

                } break;

                
;
            case 0x0A:

                switch(Menu_index){
                    case 0: Start_Game(4);//start Game
                    case 1: //open options
                    case 2: //About
                    case 3: exit(0);

                }
            }

    }
}


#endif


