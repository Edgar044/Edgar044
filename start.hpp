#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include <ctime>
#include "input.hpp"
#include "menu.hpp"
#include "user.hpp"
//head of functions for Start_Game
void Show_Board(const int Center, int size, const int color);
void step(int **Mat, int &i, int &j, int size,  char step_num, const int Board_Col, int &step);
bool chek_win(int **Mat, const int size);
int secunds_timer(int start_time);
//the Start main function
void Start_Game(const int Center, const int board_size,const int Board_color){
    std::time_t result = std::time(nullptr); // for start time
    int start_time = result;    
    int num=0;
    int** matrix = new int*[board_size];
    for(int i = 0; i < board_size; ++i){
        matrix[i] = new int[board_size];
    }
    const bool Sleep_Show = 0;
    Show_Game_Name(Center, Sleep_Show);
    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
          matrix[i][j]=++num;
        }
    }
    
    Show_Board(Center, board_size, Board_color);
    const int Board_Col = Center - (board_size * 4)/2; //vorpisi tpi mejtexic
    const int Real_Size = board_size * 2 + 1; 
    int index_i = board_size - 1;
    int index_j = board_size - 1;
    int ptr_x=Board_Col + index_i * 4; //cucichi
    int ptr_y=15 + index_j * 2;        //skzbnakan kordinatnery
    
    bool mix=0, win = 0;
    int step_count = 0;
    for(char key_1 = -1; key_1 != 27;){
        ptr_x = Board_Col + 1 + index_j * 4; 
        ptr_y = 15 + index_i*2;
        gotoxy(ptr_x, ptr_y);std::cout<<"  ";
        cbreak();
        
        if(!mix){
            result = std::time(nullptr); // for start time
            start_time = result;                 
            step_count = 0;// 0a acnum e qaylery
            mix = 1; // xarnum e xaxaqarery
            do{
                int step_key; step_key= (rand()%4+1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col, step_count);
            }while(matrix[board_size-1][board_size-1] != 1);

            do{
                int step_key; step_key= (rand()%4+1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col, step_count);
            }while(matrix[board_size-1][board_size-1] != board_size*board_size);
         step_count = 0; //jamanakvor minhev Helpy kgrem   
        }
           
        key_1 = keypress();
        step(matrix, index_i, index_j, board_size, key_1, Board_Col, step_count);
        win = chek_win(matrix, board_size);
        if ((key_1 == 'r') || (key_1 == 'R')){
            mix = 0;
        }


        gotoxy(Center - 15, 12);  
        int time= secunds_timer(start_time);
        std::cout<<"Time: "<< time/3600 << ":" << (time % 3600) / 60 << ":" << (time % 3600) % 60;
        
        gotoxy(Center + 2, 12);  // verevy aj ankyunum 
        std::cout<<"Step Count: "<<step_count<<"\n";// tpum e qayleri qanaky
        if(key_1 == 'q' ||  win == 1){  
            //diliting arrays
            for(int i=0; i<board_size; ++i){
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
    
    } 
    if(win){
      gotoxy(Board_Col + 1 + (board_size-1)*4, 15 + (board_size-1)*2); std::cout<<std::setw(2)<<board_size*board_size;
      for(char key_2 = -1; ; ){
            int color = rand() % 8;
            gotoxy(Center - 3, Real_Size + 15); Color_Cout("YOU WIN\n",color);
            cbreak();
            key_2 = keypress();
            //normal();
            if(key_2 == 'q'){
                break;             }
        }  
    } else { 
        std::cout<<"\n"; // grum enq nor toxic vorpiso 0.0 ketum axb chtpi 
    }

    
}

//functions bodies
void Show_Board(const int Center, int size, const int color){
    int lenght = size * 4;
    int hight = size * 2;
    int Board_Col = Center - (lenght / 2 );
    for(int i=0; i<size; i++){
        if(i == 0){

            for(int j = 0; j < lenght; ++j ){
                gotoxy(Board_Col + j, 14); 
                if((j%4==0) && (j!=0)){
                   Color_Cout("╦\n",color);
                }else{
                    Color_Cout("═\n",color);
                }
                
            }
        }
        for(int j = 1; j < lenght; j++){
            gotoxy(Board_Col + j,16 + (i * 2)); 
            if(j % 4 == 0){
                Color_Cout("╬\n",color);
            } else { 
            Color_Cout("═\n",color);
            }
        }
        if(i == (size-1)){

            for(int j=0; j<lenght; ++j){
                gotoxy(Board_Col + j,14 + hight);
                if(j % 4 == 0){
                    Color_Cout("╩\n",color);
                }
            }
        }
  }

    
   for(int i=0; i < hight + 1; i++){
       if(i % 2 == 0){
           gotoxy(Board_Col,14 + i); Color_Cout("╠\n",color);
           gotoxy(Board_Col + lenght,14 + i); Color_Cout("╣\n",color);
       } else {
           for(int j = 0; j < size +  1; j++){
               gotoxy(Board_Col + j*4,14 + i); Color_Cout("║\n",color);
           }
       }
        
   gotoxy(Board_Col, 14); Color_Cout("╔\n",color);
   gotoxy(Board_Col, 14 + hight); Color_Cout("╚\n",color);
   gotoxy(Board_Col + lenght, 14); Color_Cout("╗\n",color);
   gotoxy(Board_Col + lenght, 14 + hight); Color_Cout("╝\n",color);
   }
}
void step(int **Mat, int &i, int &j,const int size, char step_num,const int Board_Col,int &step){
    switch(step_num){ 
        case '8': case 8: case 'w': case 'W'://up
            if(i != size-1){
                gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i+1][j]; 
                Mat[i][j] = Mat[i][j] + Mat[i+1][j];
                Mat[i+1][j] = Mat[i][j] - Mat[i+1][j];
                Mat[i][j] = Mat[i][j] -  Mat[i+1][j];
                ++i;++step;
                
            }
            break;     
        case '2': case 2: case 's': case 'S'://down
            if(i != 0){
                gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i-1][j];
                Mat[i][j] = Mat[i][j] + Mat[i-1][j];
                Mat[i-1][j] = Mat[i][j] - Mat[i-1][j];
                Mat[i][j] = Mat[i][j] - Mat[i-1][j];
                --i;++step;
            }
            break; 
        case '4': case 4: case 'a':  case 'A'://left
            if(j != size-1){
                gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j+1];
                Mat[i][j] = Mat[i][j] + Mat[i][j+1];
                Mat[i][j+1] = Mat[i][j] - Mat[i][j+1];
                Mat[i][j] = Mat[i][j] - Mat[i][j+1];
                ++j;++step;
            }
            break; 
        case '6': case 6: case 'd': case 'D'://right
            if(j != 0){
                gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j-1];
                Mat[i][j] = Mat[i][j] + Mat[i][j-1];
                Mat[i][j-1] = Mat[i][j] - Mat[i][j-1];        
                Mat[i][j] = Mat[i][j] - Mat[i][j-1];
                --j;++step;
            }
            break;
        }
    
}
 
bool chek_win(int **Mat, const int size){
    int count = 1; 
    for(int i=0; i<size; ++i){
         for(int j=0; j<size; ++j){
             if(Mat[i][j] != count){
                 return 0;
             } count++;
         }
     }
     return 1;
 }

int secunds_timer (int start_time){
    std::time_t currentTime = time(nullptr);
    return currentTime - start_time;
}


#endif //START_H
