#include <iostream>
#include <stdlib.h>
#include "../Headers/menu.hpp"
#include "../Headers/input.hpp"
#include "../Headers/start.hpp"
#include "../Headers/user.hpp"
#include "../Headers/settings.hpp"
#include "../Headers/records.hpp"


void Show_Menu(const int centerCol){
    User currentUser;
    //top five
    constexpr int topUsers_count = 5;
    
    //creating Menu list
    constexpr int Menu_Count = 5;
    int Menu_index = 0;
    std::string Menu[Menu_Count] = {"Start", "Settings", "Records", "About", "Exit"};
    
    //size and Color write static for doesn't change every time
    static int board_size = 3;
    static int Board_Color = 4;
    
    //hight game name in Y axis
    constexpr int game_name_hight = 15;// xaxi anvan barcrutyuny 
    const bool Sleep_Show = 0;
    Show_Game_Name(centerCol, Sleep_Show);
    const int Menu_Col = centerCol - 3;
    constexpr int menu_color_value = 7;
    for(int i = 0; i < Menu_Count; ++i){
       gotoxy(Menu_Col, game_name_hight + i); 
       color_cout(Menu[i], menu_color_value); std::cout << "\n";
    }    
    gotoxy(Menu_Col, 15 + Menu_index); color_cout(Menu[Menu_index], 3); //arajin tary nshelu hamar
    
    //help
    gotoxy(centerCol - 15, game_name_hight + Menu_Count + 5 );
    color_cout("Press 'W' for up Menu, or 'S' for down\n",3);
    gotoxy(centerCol - 15, game_name_hight + Menu_Count + 6);
    color_cout("Press 'Enter' to Enter\n",3);
    gotoxy(centerCol - 15, game_name_hight + Menu_Count + 7);
    color_cout("Press 'Esc' to Exit\n",3);

    for(char key = -1; key != 27; ){
        cbreak();
        key = keypress();

        switch(key){
            //when You click "W" the pointer will go up
            case 'w': case 'W':
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
            //when You click "S" the pointer will go down    
            case 's': case 'S':
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
    
            //when you press enter it will execute the field with the given pointe 
            case 0x0A: 
                constexpr int start_Game = 0;
                constexpr int settings_Game = 1;
                constexpr int records_Game = 2;
                constexpr int about_Game = 3;
                constexpr int Exit = 4;
                switch(Menu_index){                    
                    case start_Game:
                        Start_Game(centerCol, board_size, Board_Color, currentUser, topUsers_count);
                        break;
                    case settings_Game:
                        Settings_Game(centerCol, &board_size, &Board_Color);
                        break;
                    case records_Game:
                        Records_Game(centerCol, currentUser, topUsers_count);
                        break;
                    case about_Game:
                        Show_About_Game(centerCol);
                        break;
                    case Exit:
                        system("reset"); exit(0);
                        break;                        
                }
                //last after all iteration call the Menu function
                Show_Menu(centerCol);          
        }
    } 
}


