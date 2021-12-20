#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "../Headers/input.hpp"
#include "../Headers/records.hpp"
#include "../Headers/settings.hpp"

void select_lavel()

void Settings_Game(const int centerRow, const int centerCol, int *Board_Size, int *Color_index){
    const bool Sleep_Show = 0;
    Show_Game_Name(centerRow, Sleep_Show);
    const int game_name_hight = 15;
    int Settings_index = 0;
    int Settings_Col = centerRow - 3;    
    constexpr int Settings_count = 3;
    std::string Settings[Settings_count] = {"Game level  _", "Board Color _","Users"};
    constexpr int Color_Count = 8;
    std::string Colors[Color_Count] = {"White  ", "Gray   ", "Blue   ", "Green  ",
                                       "Cyan   ", "Red    ", "Pink   ", "Yellow "};
   
    const int win_under_cordinat = centerCol + centerCol; //tpum e hushumnery
    gotoxy(centerRow - 15, game_name_hight + Settings_count + 5 );
    color_cout("Press 'W' for up Menu, or 'S' for down\n", 3);
    gotoxy(centerRow - 15, game_name_hight + Settings_count + 6);
    color_cout("Press 'Enter' to Enter\n", 3);
    gotoxy(centerRow - 15, game_name_hight + Settings_count + 7);
    color_cout("Press 'Esc' to Exit\n", 3);
   
    for(int i = 0; i < Settings_count; ++i){
        gotoxy(Settings_Col,game_name_hight + i);
        color_cout(Settings[i], 7); std::cout << "\n";
    }
    gotoxy(Settings_Col, game_name_hight + Settings_index); // arajbayin yntrvac toxy
    color_cout(Settings[Settings_index], 3);

    gotoxy(Settings_Col + 14, game_name_hight + Settings_index);// yntrvac chapi skzbnarjeqavorum
    color_cout(*Board_Size - 2, 5);
    
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

            case 0x0A:// erb sexme nq enter kkatari hamapatasxan indexov "case"-y 
                constexpr int min_Board_Size = 3;
                constexpr int max_Board_Size = 6;
                switch(Settings_index){                    
                    case 0:
                        for(char key = -1; key != 10;  ){
                            cbreak();
                            key = keypress();
                            switch(key){
                                case 'W': case 'w':
                                    if(*Board_Size == max_Board_Size){
                                        *Board_Size = min_Board_Size;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(*Board_Size - 2, 5);
                                    } else {
                                        ++*Board_Size;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(*Board_Size - 2, 5);
                                    }
                                    break;
                                case 'S': case 's':
                                    if(*Board_Size == min_Board_Size){
                                        *Board_Size = max_Board_Size;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(*Board_Size - 2, 5);
                                    } else {
                                        --*Board_Size;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                       color_cout(*Board_Size - 2, 5);
                                    }
                                    break;
                                    
                                case 10:
                                    std::cout<<"\n\n";
                                    break;
                            }                       
                        } break;
                    case 1:
                        for(char key = -1; key != 10;  ){  
                            cbreak();
                            key = keypress();
                            switch(key){
                                case 'W': case 'w':                                
                                    if(*Color_index == Color_Count-1){
                                        *Color_index = 0;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(Colors[*Color_index], *Color_index);
                                    } else {
                                        ++*Color_index;
                                        gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(Colors[*Color_index], *Color_index);
                                    }
                                    break;
                       
                                case 'S': case 's':
                                    if(*Color_index == 0){
                                       *Color_index = Color_Count - 1;
                                       gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                        color_cout(Colors[*Color_index], *Color_index); 
                                    } else {
                                       --*Color_index;
                                       gotoxy(Settings_Col + 14, game_name_hight + Settings_index);
                                       color_cout(Colors[*Color_index], *Color_index); 
                                    }
                                   break;
                            }
                        }  break;

                    case 2:
                        break;
                    
                } 
        }
    }

}
