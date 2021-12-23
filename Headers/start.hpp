#ifndef START_H
#define START_H
#include "user.hpp"
//heads of functions for Start_Game

//for print line board
void Show_Board(const int centerRow, int size, const int color);
//function for step
void step(int **Mat, int &i, int &j, int size,  char step_num, const int Board_Col, int &step);
//chek the matrix is aligned or not?
bool chek_win(int **Mat, const int size);
//geting start time count current
int secunds_timer(int start_time);
//the Start main function
void Start_Game(const int centerRow, const int board_size,const int board_color, User &currentUser, const int topUsers_count);


#endif //START_H

