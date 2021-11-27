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
void Show_Game_Name(const int Center, const bool sleep_show);//cuyc e talis xaxi anuny 

void Show_About_Game(const int Center);//cuyc e talis xaxi masin

void gotoxy(int x, int y);//kursori texasharji functia

void Color_Cout(std::string text, int text_color);//gunavorman functia

void Color_Cout(int text, int text_color);// gunavorman funqciai gerbernum interi hamar

#endif // INPUT_HPP

