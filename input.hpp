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
void Show_Game_Name();

void Show_About_Game();

void gotoxy(int x, int y);

void Color_Cout(std::string text, int text_color);
#endif // INPUT_HPP

