#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include "input.hpp"
#include "fun.hpp"

void Show_Board(int size);


void Start_Game(const int board_size){
    int num=0;
    int matrix[board_size][board_size];
    system("clear");
    Show_Game_Name();     
    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
          matrix[i][j]=++num;
        }
    }
    
    Show_Board(board_size);
    
    for(int i=0; i<board_size; ++i){
        gotoxy(80,15 + 2*i);
        for(int j=0; j<board_size; ++j){
            std::cout<<std::setw(2)<<matrix[i][j]<<" |";
        }
        std::cout<<"\n";
    }

}


void Show_Board(int size){
    int lenght = size * 4;
    int hight = size * 2;

    for(int i = 0; i < lenght; ++i ){
        gotoxy(80 + i, 14); std::cout<<"-";
    }
          
    

    for(int i=0; i<size; i++){
        for(int j=0; j<lenght; j++){
             gotoxy(80 + j,16 + (i * 2)); std::cout<<"-";
        }
    }

    for(int i=0; i<hight + 1; i++){
        gotoxy(79,14 + i); std::cout<<"|";
        gotoxy(79 + lenght,14 + i); std::cout<<"|";
         }

}



#endif
