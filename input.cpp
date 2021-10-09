#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

int tty_mode = 0;
struct termios orig_tty;
struct termios new_tty;

 //Sets up terminal for one-char-at-a-time reads
void cbreak(){
    if (tty_mode == 0){

             tcgetattr(0, &orig_tty);
             tty_mode = 1;
             new_tty = orig_tty;

       }

    new_tty.c_lflag &= ~(ICANON | ECHO);
    new_tty.c_cc[VMIN] = 1;
    new_tty.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_tty);

 }

        //Returns terminal to normal state after cbreak ()
void normal(){
    if (tty_mode == 1){
        tcsetattr(0, TCSANOW, &orig_tty);
        new_tty = orig_tty;
    }
}
       // Checks keyboard buffer (stdin) and returns key
       // pressed, or -1 for no key pressed
int keypress(){

    /*static*/
    char keypressed;
    struct timeval waittime;
    int num_chars_read;
    fd_set mask;
    FD_SET(0, &mask);
    waittime.tv_sec = 0;
    waittime.tv_usec = 0;
    if (select (1, &mask, 0, 0, &waittime)){
        num_chars_read = read (0, &keypressed, 1);
        if (num_chars_read == 1)
            return ((int)keypressed);
    }
    return -1;
}

void Color_Cout(std::string text, int text_color)
{
        switch(text_color)
        { 
            case  1: std::cout << "\x1b[90;1m" << text << "\x1b[0m\n"; break; // gray       1
            case  2: std::cout << "\x1b[34;1m" << text << "\x1b[0m\n"; break; // blue       2
            case  3: std::cout << "\x1b[32;1m" << text << "\x1b[0m\n"; break; // green      3
            case  4: std::cout << "\x1b[36;1m" << text << "\x1b[0m\n"; break; // cyan       4
            case  5: std::cout << "\x1b[31;1m" << text << "\x1b[0m\n"; break; // red        5
            case  6: std::cout << "\x1b[95;1m" << text << "\x1b[0m\n"; break; // pink       6
            case  7: std::cout << "\x1b[33;1m" << text << "\x1b[0m\n"; break; // yellow     7
            case  8: std::cout << "\x1b[97;1m" << text << "\x1b[0m\n"; break; // white      8
            default: std::cout << "\x1b[97;1m" << text << "\x1b[0m\n";
                                                                                                                                                                              }
}



void gotoxy(int x, int y){
    printf("%c[%d;%df",0x1B, y, x);
}

void Show_Game_Name(){
    system("clear");

Color_Cout("\t********  **        ****  *********   ****  ***      **   ********           ********     ***           **********    **********  **        ********",4); //sleep(1);  
Color_Cout("\t**        **         **    **     **   **   ***      **  **      **          **     **    ** **                **            **   **        **       ",4);// sleep(1);
Color_Cout("\t**        **         **    **     **   **   ** *     **  **      **          **     **    **  **              **            **    **        **       ",4); //sleep(1);
Color_Cout("\t**        **         **    **     **   **   **  *    **  **      **          **     **    **   **            **            **     **        *******  ",4); //sleep(1);
Color_Cout("\t********  **         **    **     **   **   **   *   **  **                  ********     ********          **            **      **        **       ",4); //sleep(1);
Color_Cout("\t      **  **         **    **     **   **   **    *  **  **   *****          **           **     **        **            **       **        **       ",4); //sleep(1);
Color_Cout("\t      **  **         **    **     **   **   **     * **  **      **          **           **      **      **            **        **        **       ",4); //sleep(1);
Color_Cout("\t      **  **         **    **     **   **   **      ***  **      **          **           **       **    **            **         **        **       ",4); //sleep(1);
Color_Cout("\t********  ********  ****  *********   ****  **      ***   ********           **           **        **  **********    **********  ********  ******** ",4); //sleep(1);

}

void Show_About_Game(){
    Show_Game_Name();
    gotoxy(80,12);
     
    Color_Cout("About Game\n",5);
    



}


