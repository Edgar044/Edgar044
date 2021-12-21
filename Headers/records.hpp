#ifndef RECORDS_H
#define RECORDS_H
#include "user.hpp"

void write_File(User* topUser, const int topUsers_count, std::string way);
void read_File(User* topUser, const int topUsers_count, std::string way);
void chenge_user(User &first, User &second);
std::string file_way(const int level);
void show_table(const int centerRow, const int name_hight, User* printUser, const int users_count);

void Records_Game(const int centerRow, User currentUser, const int topUsers_count);

void campare_results(User currentUser,const int topUsers_count, const int level);

#endif // RECORDS_H
