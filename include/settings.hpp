//setings.hpp
#ifndef SETTINGS_H
#define SETTINGS_H

//change current level
void select_level(int *Board_Size, const int Settings_hight, const int Settings_index, const char chek);
//change current color
void select_color(std::string Colors[], const int Color_Count, int *Color_index, const int Settings_Col, const int Settings_hight, const int Settings_index, const char chek);
//settings main function
void Settings_Game(const int centerRow, int *Board_Size, int *Color_index);


#endif //SETTINGS_H
