//main.cpp
#include <iostream>
#include "fun.hpp"
#include "start.hpp"
#include "input.hpp"
#include <unistd.h>
#include <sys/ioctl.h>


void userWinSize(int* winRow, int* winCol);



int main(){
    int userRowSize = 0;
    int userColSize = 0;
    userWinSize(&userRowSize, &userColSize);
    int centerCol = userColSize/2; 
    Show_Menu(centerCol);



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

