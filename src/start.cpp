#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>
#include "../include/input.hpp"
#include "../include/records.hpp"
#include "../include/start.hpp"

//the Start main function
void Start_Game(const int centerCol, const int board_size,const int board_color, User &currentUser, const int topUsers_count){
    constexpr bool Sleep_Show = 0;
    constexpr int game_name_hight = 15;
    //level determination by size
    const int game_level = board_size - 2; 
    Show_Game_Name(centerCol, Sleep_Show);
    
    //enter player name
    std::string nameTemp;
    gotoxy(centerCol - 12, game_name_hight);
    std::cout<<"Enter name: \n";
    gotoxy(centerCol, game_name_hight);
    normal();
    std::cin >> nameTemp;
    currentUser.Set_name(nameTemp);
    
    Show_Game_Name(centerCol, Sleep_Show);
    //creating board    
    int num=0;
    int** matrix = new int*[board_size];
    for(int i = 0; i < board_size; ++i){
        matrix[i] = new int[board_size];
    }
    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
          matrix[i][j] = ++num;
        }
    }
    
    Show_Board(centerCol, board_size, board_color);
    //find board cordinates
    const int Board_Col = centerCol - (board_size * 4)/2;
    const int real_size = board_size * 2 + 1; 
    //initialization matrix i and j index
    int index_i = board_size - 1;                         
    int index_j = board_size - 1;
    //initialization pointer cordinates
    int ptr_x = Board_Col + index_i * 4;                  
    int ptr_y = game_name_hight + index_j * 2;            
    //for start time
    std::time_t result = std::time(nullptr);             
    int start_time = result; 
    bool mix = 0, win = 0;
    int step_count = 0;
    int time_value = 0;
    for(char key_1 = -1; key_1 != 27;){
        ptr_x = Board_Col + 1 + index_j * 4; 
        ptr_y = game_name_hight + index_i * 2;
        gotoxy(ptr_x, ptr_y); std::cout<<"  ";
        cbreak();
        
        if(!mix){
            result = std::time(nullptr);     // for start time
            start_time = result;                 
            step_count = 0;                  // 0a acnum e qaylery
            mix = 1;                         // xarnum e xaxaqarery
            do{
                int step_key; step_key= (rand()% 4 + 1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col, step_count);
            }while(matrix[board_size - 1][board_size - 1] != 1);
                 
            do{
                int step_key; step_key = (rand()% 4 + 1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col, step_count);
            }while(matrix[board_size - 1][board_size - 1] != board_size * board_size);
         step_count = 0;                      //jamanakvor minhev Helpy kgrem   
        }
       
        key_1 = keypress();
        step(matrix, index_i, index_j, board_size, key_1, Board_Col, step_count);
        win = chek_win(matrix, board_size);
        if ((key_1 == 'r') || (key_1 == 'R')){
            mix = 0;
        }
        
        //print time
        time_value = secunds_timer(start_time);
        gotoxy(centerCol - 20, 12);
        std::cout<<"Time: ";
        print_time(time_value, board_color, centerCol - 14, 12);
        //print step count
        gotoxy(centerCol + 5, 12);          
        std::cout<<"Step Count: ";
        gotoxy(centerCol + 17, 12);
        color_cout(step_count, board_color); 
        //print user name
        gotoxy(centerCol - 20, game_name_hight + real_size);  
        std::cout<<"Player Name: "; 
        color_cout(currentUser.Get_name(), board_color);
        //print level  
        gotoxy(centerCol + 5, game_name_hight + real_size);
        std::cout << "Level: ";
        color_cout(game_level, board_color);

        //diliting dinamic matrix
        if(key_1 == 27 || win == 1){  
            for(int i=0; i<board_size; ++i){
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        gotoxy(centerCol - 20, game_name_hight + real_size + 5);
        color_cout("Press 'Esc' for back to main menu\n",3);
        gotoxy(centerCol - 20, game_name_hight + real_size + 6);
        color_cout("Press 'R' to reset\n",3);
        
    } 
    
    if(win){
      gotoxy(Board_Col + 1 + (board_size - 1) * 4, 15 + (board_size - 1) * 2);
      std::cout<<std::setw(2) << board_size * board_size;
      for(char key_2 = -1; ; ){
            int color = rand() % 8;
            gotoxy(centerCol - 3, real_size + game_name_hight + 3); 
            color_cout("YOU WIN\n",color);
            usleep(100000);
            cbreak();
            key_2 = keypress();
            if(key_2 == 27){
                break;         
            }
        }
      //campear result end write it in file
      currentUser.Set_step_count(step_count);
      currentUser.Set_record_time(time_value);
      campare_results(currentUser, topUsers_count, game_level);

    } else { 
        std::cout<<"\n"; //for garbige 
    }
}

//****functions bodies****
//printing board lines through symbols
void Show_Board(const int centerCol, int size, const int color){
    int lenght = size * 4;
    int hight = size * 2;
    int Board_Col = centerCol - (lenght / 2 );
    for(int i=0; i<size; i++){
        if(i == 0){
            for(int j = 0; j < lenght; j++){
                gotoxy(Board_Col + j, 14); 
                if((j%4==0) && (j!=0)){
                   color_cout("╦\n", color);
                } else {
                   color_cout("═\n", color);
                }                
            }
        }
        for(int j = 1; j < lenght; ++j){
            gotoxy(Board_Col + j, 16 + (i * 2)); 
            if(j % 4 == 0){
                color_cout("╬\n", color);
            } else { 
            color_cout("═\n", color);
            }
        }
        if(i == (size - 1)){
            for(int j=0; j<lenght; ++j){
                gotoxy(Board_Col + j, 14 + hight);
                if(j % 4 == 0){
                    color_cout("╩\n", color);
                }
            }
        }
    }

    for(int i=0; i < hight + 1; ++i){
       if(i % 2 == 0){
           gotoxy(Board_Col,14 + i); color_cout("╠\n", color);
           gotoxy(Board_Col + lenght, 14 + i); color_cout("╣\n", color);
       } else {
           for(int j = 0; j < size +  1; ++j){
               gotoxy(Board_Col + j*4, 14 + i); color_cout("║\n", color);
           }
       }
        
   gotoxy(Board_Col, 14); color_cout("╔\n",color);
   gotoxy(Board_Col, 14 + hight); color_cout("╚\n",color);
   gotoxy(Board_Col + lenght, 14); color_cout("╗\n",color);
   gotoxy(Board_Col + lenght, 14 + hight); color_cout("╝\n",color);
   }
}

//step function takes steps and changes values in the matrix
void step(int **Mat, int &i, int &j,const int size, char step_num, const int Board_Col, int &step){
    switch(step_num){ 
        case '8': case 8: case 'w': case 'W'://up
            if(i != size - 1){
                gotoxy(Board_Col + 1 + j * 4, 15 + i * 2); std::cout << std::setw(2) << Mat[i + 1][j]; 
                Mat[i][j] = Mat[i][j] + Mat[i + 1][j];
                Mat[i + 1][j] = Mat[i][j] - Mat[i + 1][j];
                Mat[i][j] = Mat[i][j] -  Mat[i + 1][j];
                ++i; ++step;                
            }
            break;     
        case '2': case 2: case 's': case 'S'://down
            if(i != 0){
                gotoxy(Board_Col + 1 + j * 4, 15 + i * 2); std::cout << std::setw(2) << Mat[i - 1][j];
                Mat[i][j] = Mat[i][j] + Mat[i - 1][j];
                Mat[i - 1][j] = Mat[i][j] - Mat[i - 1][j];
                Mat[i][j] = Mat[i][j] - Mat[i - 1][j];
                --i; ++step;
            }
            break; 
        case '4': case 4: case 'a':  case 'A'://left
            if(j != size - 1){
                gotoxy(Board_Col + 1 + j * 4, 15 + i * 2); std::cout << std::setw(2) << Mat[i][j + 1];
                Mat[i][j] = Mat[i][j] + Mat[i][j + 1];
                Mat[i][j + 1] = Mat[i][j] - Mat[i][j + 1];
                Mat[i][j] = Mat[i][j] - Mat[i][j + 1];
                ++j; ++step;
            }
            break; 
        case '6': case 6: case 'd': case 'D'://right
            if(j != 0){
                gotoxy(Board_Col + 1 + j * 4, 15 + i * 2); std::cout << std::setw(2) << Mat[i][j - 1];
                Mat[i][j] = Mat[i][j] + Mat[i][j - 1];
                Mat[i][j - 1] = Mat[i][j] - Mat[i][j - 1];        
                Mat[i][j] = Mat[i][j] - Mat[i][j - 1];
                --j; ++step;
            }
            break;
        }    
}
 
//chek is the matrix ascending or not?
bool chek_win(int **Mat, const int size){
    int count = 1; 
    for(int i = 0; i < size; ++i){
         for(int j=0; j < size; ++j){
             if(Mat[i][j] != count){
                 return 0;
             } ++count;
         }
     }
     return 1;
 }

//time count
int secunds_timer (int start_time){
    std::time_t currentTime = time(nullptr);
    return currentTime - start_time;
}

