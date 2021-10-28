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

/*Show_Menu functian nra hamar e vorpisi katari menyui funqcionaly ev 
 * usery aveli hesht haskana te inch hraman e uzum katarel
 * cucichi texasharjy katarvwum e keypress i ognutyamb:
 * 
 * */

void step(int** Mat, int &i, int &j, int size, int case_num) ;

void Show_Menu(){
   
    for(int i=0; i<Menu_Count; ++i){
       gotoxy(80,15 + i); 
       Color_Cout(Menu[i],7); std::cout << "\n";
    }

    
    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);

    
    for(char key = -1; key != 27; ){ 

        cbreak();
        key = keypress();
        
        
        switch(key){
            case 'w': case 'W':// "W" swxmwlis cucichy kbarcrana verev 
                if(Menu_index != 0){
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7); 
                    --Menu_index;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                   
                } else {

                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = Menu_Count - 1;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } break;
                
            case 's': case 'S':// "S"sexmelis cucichy kijni nerqev
                if(Menu_index != Menu_Count - 1){
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    ++Menu_index;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } else {

                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = 0;
                    gotoxy(80,15 + Menu_index); Color_Cout(Menu[Menu_index],3);


                } break;

                

            case 0x0A:// erb sexmenq enter kkatari hamapatasxan indexov "case"-y 
                bool retur_to_menu = 0;
                switch(Menu_index){                    
                    case 0: Start_Game(4); break;//start Game
                    case 1:  break;//open options
                    case 2: Show_About_Game(); retur_to_menu = 1; break;
                    case 3: exit(0); break;

                } break;
            }

    }
    normal();
}

       
        





















#endif


