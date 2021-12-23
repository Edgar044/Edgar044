#include <iostream>
#include <fstream>
#include "../Headers/input.hpp"
#include "../Headers/records.hpp"


void Records_Game(const int centerCol, User currentUser, const int topUsers_count){
    const bool Sleep_Show = 0;
    Show_Game_Name(centerCol, Sleep_Show);
    const int game_name_hight = 9;
    
    //crating array users
    User topUsers[topUsers_count]; 
    const int min_level = 1;
    const int max_level = 4;
    int level = 1;
    //reading file contents
    read_File(topUsers, topUsers_count,file_way(level));
    show_table(centerCol, game_name_hight, topUsers, topUsers_count, level); 
    
    for(char key = -1; key != 27 ; ){
        cbreak();
        key = keypress();
        switch(key){
            case 'a': case 'A': case 4: 
                if(level == min_level){
                    level = max_level;
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerCol, game_name_hight, topUsers, topUsers_count, level);
                } else {
                    --level;
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerCol, game_name_hight, topUsers, topUsers_count, level); 
                }
                 break;
            case 'd': case 'D': case 6:
                if(level == max_level){
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerCol, game_name_hight, topUsers, topUsers_count, level); 
                } else {
                    ++level;
                    read_File(topUsers, topUsers_count,file_way(level));
                    std::cout<<"\n";
                    show_table(centerCol, game_name_hight, topUsers, topUsers_count, level);               
                }
                 break;
        }
    }
    std::cout<<"\n";
}

//reads from file
void read_File(User* topUser, const int topUsers_count, std::string way){
    std::ifstream readFile(way);
    for(int i = 0; i < topUsers_count; ++i){    
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

//writes in a file
void write_File(User* addUser, const int addUsers_count, std::string way){
    std::ofstream writeFile(way);
    for(int i = 0; i < addUsers_count; ++i){
        writeFile << addUser[i].Get_name() << "\n";
        writeFile << addUser[i].Get_step_count() << "\n";
        writeFile << addUser[i].Get_record_time() << "\n";
    }
    writeFile.close();
}

//change users with the help of a copyconstructor
void chenge_user(User &first, User &second){
    User temp;
    temp = User(first);
    first = User(second);
    second = User(temp);

}

//getting the level return the path to the file
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

//campare current user whit top users
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

//print top five users
void show_table(const int centerCol, const int name_hight, User* printUser, const int users_count, const int level){
    //initialization x and y cordinats 
    int X_table = centerCol - 15;
    int Y_table = name_hight + 7;
    gotoxy(X_table + 10, Y_table - 3);
    std::cout<<"Level:";
    color_cout(level, 4);
    gotoxy(X_table + 3, Y_table - 1); std::cout<<"Name  |"<< "Step Count |"<<"Record Time |";
    //dilite inside section
    std::cout<<"\033[J";
    int row_color = 4;
    //numbness
    for(int i=0; i< users_count; ++i){
        gotoxy(X_table, Y_table + i);
        std::cout << i + 1 <<".";
    }
    //print users
    for(int i = 0; i<users_count; ++i){
        if(printUser[i].Get_record_time() > printUser[users_count - 1].Get_record_time()){
            std::cout<<"\n";   break;
        }
        gotoxy(X_table + 3, Y_table + i); color_cout(printUser[i].Get_name(), row_color);
        gotoxy(X_table + 14, Y_table + i); color_cout(printUser[i].Get_step_count(), row_color);
        print_time(printUser[i].Get_record_time(), row_color, X_table + 23, Y_table + i);
        std::cout<<"\n";
    }
    //help for control
    gotoxy(centerCol - 15, name_hight + Y_table + 5 );
    color_cout("Press 'A' for see previous level\n",3);
    gotoxy(centerCol - 15, name_hight + Y_table + 6);
    color_cout("Press 'D' for see next level\n",3);
    gotoxy(centerCol - 15, name_hight + Y_table + 7);
    color_cout("Press 'Esc' to return main Menu\n",3);
}

