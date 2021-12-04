//fun.hpp
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdlib.h>
#include "input.hpp"
#include "start.hpp"
#include "user.hpp"
#include "settings.hpp"
#include "records.hpp"

constexpr int Menu_Count = 5;
int Menu_index = 0;
std::string Menu[Menu_Count] = {"Start", "Settings", "Records", "About", "Exit"};
User currentUser;
void step(int** Mat, int &i, int &j, int size, int case_num) ;
int board_size = 3;
int Board_Color = 0;

/*Show_Menu functian nra hamar e vorpisi katari menyui funqcionaly ev 
 * usery aveli hesht haskana te inch hraman e uzum katarel
 * cucichi texasharjy katarvwum e keypress i ognutyamb:
 * 
 * */
void Show_Menu(const int centerRow, const int centerCol){
    const int game_name_hight = 15;// xaxi anvan barcrutyuny 
    const int win_under_cordinat = centerCol + centerCol; //bervel e mejtexi kordinati
                                                         //vorpisi hesht lini dasavorel ekranin
    
    const bool Sleep_Show = 0;
    Show_Game_Name(centerRow, Sleep_Show);
    const int topUsers_count = 5; //top hngyak
    const int Menu_Col = centerRow - 3;
    const int menu_color_value = 7;
    for(int i=0; i<Menu_Count; ++i){
       gotoxy(Menu_Col,game_name_hight + i); 
       color_cout(Menu[i],menu_color_value); std::cout << "\n";
    }    
    gotoxy(Menu_Col,15 + Menu_index); color_cout(Menu[Menu_index],3); //arajin tary nshelu hamar
    
    gotoxy(centerRow - 20, win_under_cordinat - 4);
    color_cout("Press 'W' for up Menu, or 'S' for down\n",3);
    gotoxy(centerRow - 20, win_under_cordinat - 3);
    color_cout("Press 'Enter' to Enter\n",3);
    gotoxy(centerRow - 20, win_under_cordinat - 2);
    color_cout("Press 'Esc' to Exit\n",3);

    for(char key = -1; key != 27; ){
        cbreak();
        key = keypress();

        switch(key){
            case 'w': case 'W':// "W" sexmelis cucichy kbarcrana verev 
                if(Menu_index != 0){
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],menu_color_value); 
                    --Menu_index;
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],3);
                } else {
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],menu_color_value);
                    Menu_index = Menu_Count - 1;
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],3);
                } break;
                
            case 's': case 'S':// "S"sexmelis cucichy kijni nerqev
                if(Menu_index != Menu_Count - 1){
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],menu_color_value);
                    ++Menu_index;
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],3);
                } else {
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],menu_color_value);
                    Menu_index = 0;
                    gotoxy(Menu_Col,game_name_hight + Menu_index); color_cout(Menu[Menu_index],3);
                } break;
    
            case 0x0A:// erb sexmenq enter kkatari hamapatasxan indexov "case"-y 
                bool return_to_menu = 0;
                switch(Menu_index){                    
                    case 0: Start_Game(centerRow,centerCol, board_size, Board_Color, currentUser, topUsers_count); return_to_menu = 1;break;//start Game
                    case 1: Settings_Game(centerRow, centerCol, &board_size, &Board_Color); std::cout<<board_size; return_to_menu = 1;break;//open options
                    case 2: Records_Game(centerRow, centerCol, currentUser,topUsers_count);break;//records;
                    case 3: Show_About_Game(centerRow); return_to_menu = 1; break;
                    case 4: system("reset"); exit(0); break;
                            
                }
                Show_Menu(centerRow, centerCol);          
            }
    }
    
}



#endif


