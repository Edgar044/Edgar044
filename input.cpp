#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

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
       // Checks keyboard buffer (stdin) and returns  key
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

void Color_Cout(std::string text, int text_color)// gunavor tpelu functia
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


void Color_Cout(int text, int text_color)// gunavor tpelu functia
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


void gotoxy(const int x,const int y){// kursori sharji hamar ogtagorcum enq printf hramany
                          // vorin vorpes parametrer talis enq kordinatnery
    printf("%c[%d;%df",0x1B, y, x);
}

void Show_Game_Name(const int centerCol, const bool sleep_show ){// xaxi anuny tpelu hamar
   const int startCol = centerCol - (146 / 2);
   int sleep_time = 0;
   if(sleep_show){
       sleep_time = 150000;
   }
 system("clear");
gotoxy(startCol,1);
Color_Cout("********  **        ****  *********   ****  ***      **   ********           ********     **      **  **********    **********  **        ******** ",4); usleep(sleep_time);
gotoxy(startCol,2);
Color_Cout("**        **         **    **     **   **   ***      **  **      **          **     **    **      **         **            **   **        **       ",4); usleep(sleep_time);
gotoxy(startCol,3);
Color_Cout("**        **         **    **     **   **   ** *     **  **      **          **     **    **      **        **            **    **        **       ",4); usleep(sleep_time);
gotoxy(startCol,4);
Color_Cout("**        **         **    **     **   **   **  *    **  **      **          **     **    **      **       **            **     **        *******  ",4); usleep(sleep_time);
gotoxy(startCol,5);
Color_Cout("********  **         **    **     **   **   **   *   **  **                  ********     **      **      **            **      **        **       ",4); usleep(sleep_time);
gotoxy(startCol,6);
Color_Cout("      **  **         **    **     **   **   **    *  **  **   *****          **           **      **     **            **       **        **       ",4); usleep(sleep_time);
gotoxy(startCol,7);
Color_Cout("      **  **         **    **     **   **   **     * **  **      **          **           **      **    **            **        **        **       ",4); usleep(sleep_time);
gotoxy(startCol,8);
Color_Cout("      **  **         **    **     **   **   **      ***  **      **          **           **      **   **            **         **        **       ",4); usleep(sleep_time);
gotoxy(startCol,9);
Color_Cout("********  ********  ****  *********   ****  **      ***   ********           **           **********  **********    **********  ********  ******** ",4); usleep(sleep_time);
}

void Show_About_Game(const int Center){//xaxi masin informacia
    const bool Sleep_Show = 0;
    Show_Game_Name(Center,Sleep_Show);
    int About_Col = Center - (66/2); // 66y mer mek toxi erkarutyunn e 
    gotoxy(Center - 5,12);
    Color_Cout("About Game\n",5);
    
    gotoxy(About_Col,14);
    std::cout<<"A sliding puzzle or fiften is a puzzle combination that chelenges\n"  ;      
    gotoxy(About_Col,15);
    std::cout<<"the player to slide along certain paths  in order to  establish a \n";
    gotoxy(About_Col,16);
    std::cout<<"certain final configuration. The moving parts can be simple shopes\n" ;
    gotoxy(About_Col,17);
    std::cout<<"tor they can be printed with colors, patterns, parts of a larger\n" ;
    gotoxy(About_Col,18);
    std::cout<<"timage, numbers or letters. Sliding puzzles are essentially\n"; 
    gotoxy(About_Col,19);
    std::cout<<"two-dimensional in nature. The oldest type of sliding puzzle is the \n";
    gotoxy(About_Col,20);
    std::cout<<"Fifteen puzzle, invented by Noyes Chapman in 1880: to Sam Loyd. \n";
    gotoxy(About_Col,21);
    std::cout<<"   It can be shown that exactly half of all possible 20,922,789,888,000\n";
    gotoxy(About_Col,22);
    std::cout<<"(= 16!) Initial positions of the tags cannot be brought to the\n";
    gotoxy(About_Col,23);
    std::cout<<"assembled form: \n";
    gotoxy(About_Col,24);
    std::cout<<"   If we allow the box to rotate 90 degrees, in which the images of the\n";
    gotoxy(About_Col,25);
    std::cout<<"tnumbers will be lying on their side, then we can translate the unsolvable\n";
    gotoxy(About_Col,26);
    std::cout<<"tcombinations into solvable ones (and vice versa). Thus, if instead of\n";
    gotoxy(About_Col,27);
    std::cout<<"tnumbers on the knuckles, you put dots and do not fix the position of the box,\n";
    gotoxy(About_Col,28);
    std::cout<<"then there will be no unsolvable combinations at all.\n";
    gotoxy(Center - 5,30);
    Color_Cout("How to play\n",5);
    


    for(char key = -1;;){ 
        cbreak();
        key = keypress();
        normal();
        if(key == 27){
            break;
        }

    }



}


