#ifndef START_H
#define START_H
#include "user.hpp"
//heads of functions for Start_Game
void Show_Board(const int centerRow, int size, const int color);
void step(int **Mat, int &i, int &j, int size,  char step_num, const int Board_Col, int &step);
bool chek_win(int **Mat, const int size);
int secunds_timer(int start_time);

//the Start main function
void Start_Game(const int centerRow, const int centerCol, const int board_size,const int board_color, User &currentUser, const int topUsers_count);


#endif //START_H

