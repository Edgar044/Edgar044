#include <iostream>
#include "../Headers/input.hpp"
#include "../Headers/records.hpp"
#include "../Headers/settings.hpp"

void select_level(int *Board_Size, const int Settings_Col, const int Settings_hight, const int Settings_index, const char chek);
void select_color(std::string Colors[], const int Color_Count, int *Color_index, const int Settings_Col, const int Settings_hight, const int Settings_index, const char chek);

void Settings_Game(const int centerCol, int *Board_Size, int *Color_index){
    const bool Sleep_Show = 0;
    Show_Game_Name(centerCol, Sleep_Show);
    const int game_name_hight = 15;
    int Settings_index = 0;
    int Settings_Col = centerCol - 3;    
    constexpr int Settings_count = 3;
    std::string Settings[Settings_count] = {"Game level  _", "Board Color _","Users"};
    constexpr int Color_Count = 8;
    std::string Colors[Color_Count] = {"White  ", "Gray   ", "Blue   ", "Green  ",
                                       "Cyan   ", "Red    ", "Pink   ", "Yellow "};
   
    //tpum e hushumnery
    gotoxy(centerCol - 15, game_name_hight + Settings_count + 5 );
    color_cout("Press 'W' for up Menu, or 'S' for down\n", 3);
    gotoxy(centerCol - 15, game_name_hight + Settings_count + 6);
    color_cout("Press 'A' or 'D' for change variant\n", 3);
    gotoxy(centerCol - 15, game_name_hight + Settings_count + 7);
    color_cout("Press 'Esc' to return main Menu\n", 3);
   
    for(int i = 0; i < Settings_count; ++i){
        gotoxy(Settings_Col,game_name_hight + i);
        color_cout(Settings[i], 7); std::cout << "\n";
    }
    gotoxy(Settings_Col, game_name_hight + Settings_index); // arajnayin yntrvac toxy
    color_cout(Settings[Settings_index], 3);
    
    //print first board size
    gotoxy(Settings_Col + 13, game_name_hight + Settings_index);
    color_cout(*Board_Size, 5);
    gotoxy(Settings_Col + 16, game_name_hight + Settings_index);
    color_cout("X", 5);
    gotoxy(Settings_Col + 17, game_name_hight + Settings_index);
    color_cout(*Board_Size, 5);

    //print first color
    gotoxy(Settings_Col + 14, game_name_hight + 1 + Settings_index);
    color_cout(Colors[*Color_index], *Color_index);
    
    int Size;
    for(char key_2 = -1; key_2 != 27; ) {
        cbreak();
        key_2 = keypress();
        switch(key_2){    
            case 'w': case 'W': 
                if(Settings_index != 0){
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 7); 
                    --Settings_index;
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 3);
                } else {
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 7);
                    Settings_index = Settings_count - 1;
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 3);
                } break;
            
            case 's': case 'S':
                if(Settings_index != Settings_count - 1){
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 7);
                    ++Settings_index;
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 3);
                } else {
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 7);
                    Settings_index = 0;
                    gotoxy(Settings_Col, game_name_hight + Settings_index);
                    color_cout(Settings[Settings_index], 3);
                } break;

            case 'a': case 'A':
                if (Settings_index == 0){
                    select_level(Board_Size, Settings_Col, game_name_hight, Settings_index, key_2);
                } else if (Settings_index == 1) {
                    select_color(Colors, Color_Count, Color_index, Settings_Col, game_name_hight, Settings_index, key_2);
                }
                break;

            case 'd': case 'D':
                if (Settings_index == 0){
                    select_level(Board_Size, Settings_Col, game_name_hight, Settings_index, key_2); 
                } else if (Settings_index == 1) {
                    select_color(Colors, Color_Count, Color_index, Settings_Col, game_name_hight, Settings_index, key_2);
                }
                break;       
        }
    }
}


//change levels
void select_level(int *Board_Size, const int Settings_Col, const int Settings_hight, const int Settings_index, const char chek){
    constexpr int min_Board_Size = 3;
    constexpr int max_Board_Size = 6;

    if (chek == 'a' || chek == 'A'){
        if(*Board_Size == min_Board_Size){
            *Board_Size = max_Board_Size;
            gotoxy(Settings_Col + 13, Settings_hight + Settings_index);
            //color_cout(*Board_Size - 2, 5);
            color_cout(*Board_Size, 5);
            gotoxy(Settings_Col + 16, Settings_hight + Settings_index);
            color_cout("X", 5);
            gotoxy(Settings_Col + 17, Settings_hight + Settings_index);
            color_cout(*Board_Size, 5);
        } else {
            --*Board_Size;
            gotoxy(Settings_Col + 13, Settings_hight + Settings_index);
            //color_cout(*Board_Size - 2, 5);
            color_cout(*Board_Size, 5);
            gotoxy(Settings_Col + 16, Settings_hight + Settings_index);
            color_cout("X", 5);
            gotoxy(Settings_Col + 17, Settings_hight + Settings_index);
            color_cout(*Board_Size, 5);
        }
        return;
    } 
    
    if (chek == 'd' || chek == 'D'){
       if(*Board_Size == max_Board_Size){
            *Board_Size = min_Board_Size;
            gotoxy(Settings_Col + 13, Settings_hight + Settings_index);
            //color_cout(*Board_Size - 2, 5); 
           color_cout(*Board_Size, 5);
            gotoxy(Settings_Col + 16, Settings_hight + Settings_index);
            color_cout("X", 5);
            gotoxy(Settings_Col + 17, Settings_hight + Settings_index);
            color_cout(*Board_Size, 5);
        } else {
            ++*Board_Size;
            gotoxy(Settings_Col + 13, Settings_hight + Settings_index);
            //color_cout(*Board_Size - 2, 5);
             color_cout(*Board_Size, 5);
            gotoxy(Settings_Col + 16, Settings_hight + Settings_index);
            color_cout("X", 5);
            gotoxy(Settings_Col + 17, Settings_hight + Settings_index);
            color_cout(*Board_Size, 5);
        }
        return;
    }
}

//change colors
void select_color(std::string Colors[], const int Color_Count, int *Color_index, const int Settings_Col, const int Settings_hight, const int Settings_index, const char chek){
     
    if (chek == 'a' || chek == 'A'){
        if(*Color_index == 0){
            *Color_index = Color_Count - 1;
            gotoxy(Settings_Col + 14, Settings_hight + Settings_index);
            color_cout(Colors[*Color_index], *Color_index); 
        } else {
            --*Color_index;
            gotoxy(Settings_Col + 14, Settings_hight + Settings_index);
            color_cout(Colors[*Color_index], *Color_index); 
        }
        return;
    } 
    
    if (chek == 'd' || chek == 'D'){
        if(*Color_index == Color_Count-1){
            *Color_index = 0;
            gotoxy(Settings_Col + 14, Settings_hight + Settings_index);
            color_cout(Colors[*Color_index], *Color_index);
        } else {
            ++*Color_index;
            gotoxy(Settings_Col + 14, Settings_hight + Settings_index);
            color_cout(Colors[*Color_index], *Color_index);
        }
        
        return;
    }
}

