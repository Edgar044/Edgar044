#ifndef INPUT_HPP
#define INPUT_HPP

/*
* Brief: Sets up terminal for one-char-at-a-time reads
*/
void cbreak();

/*
* Brief: Resets terminal to normal state after cbreak()
*/
void normal();

/*
* Brief: Checks keyboard buffer (stdin) and returns the pressed key
* Return: Pressed key or -1
*/
int keypress();

//My Functions
//print Game name 
void Show_Game_Name(const int centerRow, const bool sleep_show); 
//print game info
void Show_About_Game(const int Center);
//for cursor muvment
void gotoxy(int x, int y);
//coloring function for strings 
void color_cout(const std::string text, const int text_color);
//coloring function for integers
void color_cout(const int text, const int text_color);
//time printing in normal format
void print_time(const int secunds, const int color_value, int X, const int Y);

#endif // INPUT_HPP

