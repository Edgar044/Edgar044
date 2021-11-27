//fun.hpp
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include "input.hpp"
#include "start.hpp"
#include "settings.hpp"

const int Menu_Count = 4;
int Menu_index = 0;
std::string Menu[Menu_Count] = {"Start", "Settings", "About", "Exit"};

void step(int** Mat, int &i, int &j, int size, int case_num) ;
int Board_Size = 2;
int Board_Color = 0;

/*Show_Menu functian nra hamar e vorpisi katari menyui funqcionaly ev 
 * usery aveli hesht haskana te inch hraman e uzum katarel
 * cucichi texasharjy katarvwum e keypress i ognutyamb:
 * 
 * */
void Show_Menu(const int centerCol, const int centerRow){

    const bool Sleep_Show = 0;
    Show_Game_Name(centerCol, Sleep_Show);
    int Menu_Col = centerCol - 3;
        for(int i=0; i<Menu_Count; ++i){
       gotoxy(Menu_Col,15 + i); 
       Color_Cout(Menu[i],7); std::cout << "\n";
    }    
    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],3); //arajin tary nshelu hamar
    gotoxy(centerCol - 20, 15 + Menu_Count + 15);
    std::cout <<"Press 'W' for up Menu, or 'S' for down\n";
    gotoxy(centerCol - 20, 15 + Menu_Count + 16);
    std::cout <<"Press 'Enter' to Enter\n";
    gotoxy(centerCol - 20, 15 + Menu_Count + 17);
    std::cout <<"Press 'Esc' to Exit\n";







    for(char key = -1; key != 27; ){
        cbreak();
        key = keypress();

        switch(key){
            case 'w': case 'W':// "W" sexmelis cucichy kbarcrana verev 
                if(Menu_index != 0){
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],7); 
                    --Menu_index;
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } else {
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = Menu_Count - 1;
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } break;
                
            case 's': case 'S':// "S"sexmelis cucichy kijni nerqev
                if(Menu_index != Menu_Count - 1){
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    ++Menu_index;
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } else {
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],7);
                    Menu_index = 0;
                    gotoxy(Menu_Col,15 + Menu_index); Color_Cout(Menu[Menu_index],3);
                } break;
    
            case 0x0A:// erb sexmenq enter kkatari hamapatasxan indexov "case"-y 
                bool return_to_menu = 0;
                switch(Menu_index){                    
                    case 0: Start_Game(centerCol, Board_Size, Board_Color ); return_to_menu = 1;break;//start Game
                    case 1: Settings_Game(centerCol, &Board_Size, &Board_Color); std::cout<<Board_Size; return_to_menu = 1;break;//open options
                    case 2: Show_About_Game(centerCol); return_to_menu = 1; break;
                    case 3: system("reset"); exit(0); break;
                            
                }
                Show_Menu(centerCol, centerRow);          
            }
    }
    
}



#endif


