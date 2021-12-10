#include <iostream>
#include <stdlib.h>
#include "../Headers/menu.hpp"
#include "../Headers/input.hpp"
#include "../Headers/start.hpp"
#include "../Headers/user.hpp"
#include "../Headers/settings.hpp"
#include "../Headers/records.hpp"

//constexpr int Menu_Count = 5;
//int Menu_index = 0;
//void step(int** Mat, int &i, int &j, int size, int case_num) ;
//int board_size = 3;
//int Board_Color = 0;

/*Show_Menu functian nra hamar e vorpisi katari menyui funqcionaly ev 
 * usery aveli hesht haskana te inch hraman e uzum katarel
 * cucichi texasharjy katarvwum e keypress i ognutyamb:
 * 
 * */
void Show_Menu(const int centerRow, const int centerCol){
    User currentUser;
    constexpr int topUsers_count = 5; //top hngyak
    constexpr int Menu_Count = 5;
    int Menu_index = 0;
    std::string Menu[Menu_Count] = {"Start", "Settings", "Records", "About", "Exit"};
    static int board_size = 3;
    static int Board_Color = 4;
    constexpr int game_name_hight = 15;// xaxi anvan barcrutyuny 
    const bool Sleep_Show = 0;
    Show_Game_Name(centerRow, Sleep_Show);
    
    const int Menu_Col = centerRow - 3;
    constexpr int menu_color_value = 7;
    for(int i=0; i<Menu_Count; ++i){
       gotoxy(Menu_Col,game_name_hight + i); 
       color_cout(Menu[i],menu_color_value); std::cout << "\n";
    }    
    gotoxy(Menu_Col,15 + Menu_index); color_cout(Menu[Menu_index],3); //arajin tary nshelu hamar
    
    //help
    gotoxy(centerRow - 15, game_name_hight + Menu_Count + 5 );
    color_cout("Press 'W' for up Menu, or 'S' for down\n",3);
    gotoxy(centerRow - 15, game_name_hight + Menu_Count + 6);
    color_cout("Press 'Enter' to Enter\n",3);
    gotoxy(centerRow - 15, game_name_hight + Menu_Count + 7);
    color_cout("Press 'Esc' to Exit\n",3);

    for(char key = -1; key != 27; ){
        cbreak();
        key = keypress();

        switch(key){
            case 'w': case 'W':// "W" sexmelis cucichy kbarcrana verev 
                if(Menu_index != 0){
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], menu_color_value); 
                    --Menu_index;
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], 3);
                } else {
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], menu_color_value);
                    Menu_index = Menu_Count - 1;
                    gotoxy(Menu_Col,game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], 3);
                } break;
                
            case 's': case 'S':// "S"sexmelis cucichy kijni nerqev
                if(Menu_index != Menu_Count - 1){
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], menu_color_value);
                    ++Menu_index;
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index], 3);
                } else {
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index],menu_color_value);
                    Menu_index = 0;
                    gotoxy(Menu_Col, game_name_hight + Menu_index);
                    color_cout(Menu[Menu_index],3);
                } break;
    
            case 0x0A:// erb sexmenq enter kkatari hamapatasxan indexov "case"-y 
                 constexpr int start_Game = 0;
                constexpr int settings_Game = 1;
                constexpr int records_Game = 2;
                constexpr int about_Game = 3;
                constexpr int Exit = 4;
                switch(Menu_index){                    
                    case start_Game:
                        Start_Game(centerRow,centerCol, board_size, Board_Color, currentUser, topUsers_count);
                        break;
                    case settings_Game:
                        Settings_Game(centerRow, centerCol, &board_size, &Board_Color);
                        break;
                    case records_Game:
                        Records_Game(centerRow, centerCol, currentUser,topUsers_count);
                        break;
                    case about_Game:
                        Show_About_Game(centerRow);
                    case Exit:
                        system("reset"); exit(0);
                        break;                        
                }
                Show_Menu(centerRow, centerCol);          
        }
    } 
}


