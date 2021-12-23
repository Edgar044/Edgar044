#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include "../Headers/menu.hpp"
#include "../Headers/input.hpp"

//to get the window  size 
void userWinSize(int* winRow, int* winCol);

int main(){
    //to hide the pointer
    printf("\e[?25l");
    int userRowSize = 0;
    int userColSize = 0;
    userWinSize(&userRowSize, &userColSize);
    //finde center windows 
    const int centerCol = userColSize/2;
    const int centerRow = userRowSize/2;
    const bool sleep_show = 1;
    //animation show game name
    Show_Game_Name(centerCol, sleep_show);
    Show_Menu(centerCol);

    //for beautiful Exit
    gotoxy(1,35);
    std::cout<<"\n\n";
    return  0;
}

//to get the window  size 
void userWinSize(int* winRow, int* winCol){
        struct winsize w;
           ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
           *winRow = w.ws_row;
           *winCol = w.ws_col;
                    
}

