//main.cpp
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include "menu.hpp"
#include "start.hpp"
#include "input.hpp"


void userWinSize(int* winRow, int* winCol);



int main(){
    int userRowSize = 0;
    int userColSize = 0;
    userWinSize(&userRowSize, &userColSize);
    int centerCol = userColSize/2;
    int centerRow = userRowSize/2;
    const bool Sleep_Show = 1;
    Show_Game_Name(centerCol, Sleep_Show);
    Show_Menu(centerCol, centerRow);



    gotoxy(1,35);
    std::cout<<"\n\n";
    return  0;
}




void userWinSize(int* winRow, int* winCol)
{
        struct winsize w;
            ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
                *winRow = w.ws_row;
                    *winCol = w.ws_col;
                    
}

