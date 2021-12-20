#include <iostream>
#include <fstream>
//#include <stdlib.h>
//#include "menu.hpp"
//#include "start.hpp"
#include "../Headers/input.hpp"
#include "../Headers/records.hpp"


void Records_Game(const int centerRow, const int centerCol, User currentUser, const int topUsers_count){
    const bool Sleep_Show = 0;
    Show_Game_Name(centerRow, Sleep_Show);
    const int game_name_hight = 9;
    
    User topUsers[topUsers_count]; 
    const int min_level = 1;
    const int max_level = 4;
    int level = 1;
    
    gotoxy(centerRow - 10, game_name_hight + 3);
    std::cout<<"Level:";
    color_cout(level, 4);
    read_File(topUsers, topUsers_count,file_way(level));
    show_table(centerRow, game_name_hight, topUsers, topUsers_count); 
    
    for(char key = -1; key != 27 ; ){
        cbreak();
        key = keypress();
        switch(key){
            case 'a': case 'A': case 4: 
                if(level == min_level){
                    level = max_level;
                    gotoxy(centerRow - 10, game_name_hight + 3);
                    std::cout<<"Level:";
                    color_cout(level, 4);
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerRow, game_name_hight, topUsers, topUsers_count);
                } else {
                    --level;
                    gotoxy(centerRow - 10, game_name_hight + 3);
                    std::cout<<"Level:";
                    color_cout(level, 4);
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerRow, game_name_hight, topUsers, topUsers_count); 
                }
                 break;
            case 'd': case 'D': case 6:
                if(level == max_level){
                    level = min_level;
                    gotoxy(centerRow - 10, game_name_hight + 3);
                    std::cout<<"Level:";
                    color_cout(level, 4);
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerRow, game_name_hight, topUsers, topUsers_count); 
                } else {
                    ++level;
                    gotoxy(centerRow - 10, game_name_hight + 3);
                    std::cout<<"Level:";
                    color_cout(level, 4);
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerRow, game_name_hight, topUsers, topUsers_count);               
                }
                 break;
        }
    }
    std::cout<<"\n";
}

void read_File(User* topUser, int topUsers_count, std::string way){
    std::ifstream readFile(way);
    for(int i = 0; i<topUsers_count; ++i){    
        std::string temp_name;
        std::string temp_step_count;
        std::string temp_record_time;
        
        std::getline(readFile, temp_name);
        std::getline(readFile, temp_step_count);
        std::getline(readFile, temp_record_time);
        
        topUser[i].Set_name(temp_name);
        topUser[i].Set_step_count(std::stoi(temp_step_count));
        topUser[i].Set_record_time(std::stoi(temp_record_time));
    }
    readFile.close();
}

void write_File(User* addUser, int addUsers_count, std::string way){
    std::ofstream writeFile(way);
    for(int i = 0; i<addUsers_count; ++i){
        writeFile << addUser[i].Get_name() << "\n";
        writeFile << addUser[i].Get_step_count() << "\n";
        writeFile << addUser[i].Get_record_time() << "\n";
    }
    writeFile.close();
}

void chenge_user(User &first, User &second){
    User temp;
    temp.Copy(first);
    first.Copy(second);
    second.Copy(temp);

}

std::string file_way(const int level){
    std::string Way;
    switch (level){
        case 1: Way = "records_file/records_1.txt"; break;
        case 2: Way = "records_file/records_2.txt"; break;
        case 3: Way = "records_file/records_3.txt"; break;
        case 4: Way = "records_file/records_4.txt"; break;
    }
    return Way;
}

void campare_results(User currentUser,const int topUsers_count, const int level){
   User topUser[topUsers_count];
   read_File(topUser, topUsers_count, file_way(level));
   
   for(int i = 0; i < topUsers_count; ++i){
       if(currentUser.Get_record_time() < topUser[i].Get_record_time()){
           chenge_user(currentUser, topUser[i]);
           write_File(topUser,topUsers_count, file_way(level)); 
       }
   }

}


void show_table(const int centerRow, const int name_hight, User* printUser, const int users_count){
    int X_table = centerRow - 20;
    int Y_table = name_hight + 5;
    gotoxy(X_table + 3, Y_table); std::cout<<"Name  |"<< "Step Count |"<<"Record Time |";
    std::cout<<"\033[J";//jmjum e nerqevi hatvacy
    int row_color = 4;
    
    for(int i=0; i< users_count; ++i){
        gotoxy(X_table, Y_table + i + 1);
        std::cout << i + 1 <<".";
    }
    
    for(int i = 0; i<users_count; ++i){
        if(printUser[i].Get_record_time() >= printUser[users_count - 1].Get_record_time()){
            std::cout<<"\n";   break;
        }
        gotoxy(X_table + 3, Y_table + i + 1); color_cout(printUser[i].Get_name(), row_color);
        gotoxy(X_table + 14, Y_table + i + 1); color_cout(printUser[i].Get_step_count(), row_color);
        print_time(printUser[i].Get_record_time(), row_color, X_table + 23, Y_table + i + 1);
        std::cout<<"\n";
    }
}
