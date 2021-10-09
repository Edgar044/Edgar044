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
       gotoxy(80,15 + i); 
       Color_Cout(Menu[i],7); std::cout << "\n";
    }

    
    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);

    
    for(char key = -1; key != 27; ){ 

        cbreak();
        key = keypress();
        normal();
        
        switch(key){
            case 'w': case 'W':
                if(Menu_index != 0){
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7); 
                    --Menu_index;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                   
                } else {

                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = Menu_Count - 1;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } break;
                
            case 's': case 'S':
                if(Menu_index != Menu_Count - 1){
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    ++Menu_index;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } else {

                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = 0;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);


                } break;

                

            case 0x0A:

                switch(Menu_index){
                    case 0: Start_Game(4); break;//start Game
                    case 1:  break;//open options
                    case 2: Show_About_Game(); break;
                    case 3: exit(0); break;

                }
            }

    }
}


#endif


