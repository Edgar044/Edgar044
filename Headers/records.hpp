#ifndef RECORDS_H
#define RECORDS_H
#include "user.hpp"

//writes in a file
void write_File(User* topUser, const int topUsers_count, std::string way);
//reads from a file
void read_File(User* topUser, const int topUsers_count, std::string way);
//change place users
void chenge_user(User &first, User &second);
//getting the level return the path to the file
std::string file_way(const int level);
//print top five names
void show_table(const int centerRow, const int name_hight, User* printUser, const int users_count);
//record main function
void Records_Game(const int centerRow, User currentUser, const int topUsers_count);
//capare players results
void campare_results(User currentUser,const int topUsers_count, const int level);

#endif // RECORDS_H
