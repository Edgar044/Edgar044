//main.cpp
#include <iostream>
#include "fun.hpp"
#include "start.hpp"
#include "input.hpp"
#include <unistd.h>


int main(){ 
    Show_Game_Name();
    Show_Menu();

    gotoxy(1,35);
    std::cout<<"\n\n";
    return  0;

}
