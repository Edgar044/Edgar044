#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include "input.hpp"
#include "fun.hpp"


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
  

    for(int i=0; i<board_size; ++i){
        gotoxy(15,4 + i);
        for(int j=0; j<board_size; ++j){
            std::cout<<std::setw(2)<<matrix[i][j]<<"  ";
        }
        std::cout<<"\n";
    }

}




#endif
