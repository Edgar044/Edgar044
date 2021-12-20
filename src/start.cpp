#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>
#include "../Headers/input.hpp"
//#include "../Headers/menu.hpp"
#include "../Headers/records.hpp"
#include "../Headers/start.hpp"

//the Start main function
void Start_Game(const int centerRow, const int board_size,const int board_color, User &currentUser, const int topUsers_count){
    constexpr bool Sleep_Show = 0;
    constexpr int game_name_hight = 15;
    const int game_level = board_size - 2;// xaxataxtaki chaperic imanum enq xaxi makardaky 
    Show_Game_Name(centerRow, Sleep_Show);
    
    std::string nameTemp;
    gotoxy(centerRow - 12, game_name_hight);
    std::cout<<"Enter name: \n";
    gotoxy(centerRow, game_name_hight);
    normal();
    std::cin >> nameTemp;
    currentUser.Set_name(nameTemp);
    
    //sksum e xaxy
    Show_Game_Name(centerRow, Sleep_Show);
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
        
    Show_Board(centerRow, board_size, board_color);
    const int Board_Col = centerRow - (board_size * 4)/2; //vorpisi tpi mejtexic
    const int real_size = board_size * 2 + 1; 
    int index_i = board_size - 1;                         //matrici skzbnakan i indexy
    int index_j = board_size - 1;                         //matrici skzbnakan j indexy
    int ptr_x = Board_Col + index_i * 4;                  //cucichi
    int ptr_y = game_name_hight + index_j * 2;            //skzbnakan kordinatnery
    
    std::time_t result = std::time(nullptr);             // for start time
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
        
        time_value = secunds_timer(start_time);// jamanaki tpum verevy dzax ankyunum
        gotoxy(centerRow - 20, 12);
        std::cout<<"Time: ";
        print_time(time_value, board_color, centerRow - 14, 12);
       
        gotoxy(centerRow + 5, 12);          // verevy aj ankyunum 
        std::cout<<"Step Count: ";
        gotoxy(centerRow + 17, 12);
        color_cout(step_count, board_color); // tpum e qayleri qanaky
        
        gotoxy(centerRow - 20, game_name_hight + real_size); //pleyeri anuny nerqevy aj ankyunum 
        std::cout<<"Player Name: "; 
        color_cout(currentUser.Get_name(), board_color);

        gotoxy(centerRow + 5, game_name_hight + real_size);
        std::cout << "Level: ";  color_cout(game_level, board_color);

       //diliting matrix
        if(key_1 == 27 || win == 1){  
            for(int i=0; i<board_size; ++i){
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        gotoxy(centerRow - 20, game_name_hight + real_size + 5);
        color_cout("Press 'Esc' for back to main menu\n",3);
        gotoxy(centerRow - 20, game_name_hight + real_size + 6);
        color_cout("Press 'R' to reset\n",3);
        
    } 
    
    if(win){
      gotoxy(Board_Col + 1 + (board_size - 1) * 4, 15 + (board_size - 1) * 2);
      std::cout<<std::setw(2) << board_size * board_size;
      for(char key_2 = -1; ; ){
            int color = rand() % 8;
            gotoxy(centerRow - 3, real_size + game_name_hight + 3); 
            color_cout("YOU WIN\n",color);
            usleep(100000);
            cbreak();
            key_2 = keypress();
            if(key_2 == 27){
                break;         
            }
        }
      //Recordy grancum e matricum
      currentUser.Set_step_count(step_count);
      currentUser.Set_record_time(time_value);
      campare_results(currentUser, topUsers_count, game_level);

    } else { 
        std::cout<<"\n"; // grum enq nor toxic vorpiso 0.0 ketum axb chtpi 
    }
}

//functions bodies
void Show_Board(const int centerRow, int size, const int color){
    int lenght = size * 4;
    int hight = size * 2;
    int Board_Col = centerRow - (lenght / 2 );
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

int secunds_timer (int start_time){
    std::time_t currentTime = time(nullptr);
    return currentTime - start_time;
}

