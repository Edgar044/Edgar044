#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include "input.hpp"
#include "fun.hpp"

void Show_Board(int size);
void step(int **Mat, int &i, int &j, int size,  char step_num );
void Start_Game(const int board_size){// xaxy skselu hamar tpume xaxi dashty ev 
                                      // stexcum hamapatasxan matrixy
    int num=0;
    int** matrix = new int*[board_size];
    for(int i = 0; i < board_size; ++i){
        matrix[i] = new int[board_size];
    }
    system("clear");
    Show_Game_Name();     
    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
          matrix[i][j]=++num;
        }
    }
    
    Show_Board(board_size);
    
    for(int i=0; i<board_size; ++i){
        gotoxy(80,15 + 2*i);
        for(int j=0; j<board_size; ++j){
            std::cout<<std::setw(2)<<matrix[i][j]<<" ║";
        }
         std::cout<<"\n";
    }

    int index_i = board_size - 1;
    int index_j = board_size - 1;
    int ptr_x=80 + index_i*4;//cucichi
    int ptr_y=15 + index_j*2;//skzbnakan kordinatnery
    int degree_of_mix = 10;
    
    for(char key_1 = -1; key_1 != 27;){
        ptr_x=80 + index_j*4; 
        ptr_y=15 + index_i*2;
        gotoxy(ptr_x, ptr_y);std::cout<<"  ";
        cbreak();
        do{
            int step_key; step_key= (rand()%4+1) * 2;
            step(matrix, index_i, index_j, board_size, step_key);
        }while(index_i == index_j);
                   
        key_1 = keypress();
        step(matrix, index_i, index_j, board_size, key_1);

        //normal();
    }

}

void Show_Board(int size){
    int lenght = size * 4;
    int hight = size * 2;

    for(int i=0; i<size; i++){
        if(i == 0){

            for(int j = 0; j < lenght; ++j ){
                gotoxy(79 + j, 14); 
                if((j%4==0) && (j!=0)){
                    std::cout<<"╤";
                }else{
                    std::cout<<"═";
                }
                
            }
        }
        for(int j=0; j<lenght; j++){
            gotoxy(79 + j,16 + (i * 2)); 
            if(j % 4 == 0){
                std::cout<<"┼";
            } 
            std::cout<<"―";
        }
        if(i == (size-1)){

            for(int j=0; j<lenght; ++j){
                gotoxy(79 + j,14 + hight);
                if(j % 4 == 0){
                    std::cout<<"╧";
                }else{
                    std::cout<<"═";
                }
            }

        }
      
    }
    
   for(int i=0; i<hight + 1; i++){
        gotoxy(79,14 + i); std::cout<<"║";
        gotoxy(79 + lenght,14 + i); std::cout<<"║";
         }

    gotoxy(79, 14); std::cout<<"╔";
    gotoxy(79, 14 + hight); std::cout<<"╚";
    gotoxy(79 + lenght, 14); std::cout<<"╗";
    gotoxy(79 + lenght, 14 + hight); std::cout<<"╝";

}


void step(int **Mat, int &i, int &j,const int size, char step_num ){

 switch(step_num){
          case '8': case 8://up
                if(i != size-1){
                    gotoxy(80 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i+1][j]; 
                    Mat[i][j] = Mat[i][j] + Mat[i+1][j];
                    Mat[i+1][j] = Mat[i][j] - Mat[i+1][j];
                    Mat[i][j] = Mat[i][j] -  Mat[i+1][j];
                    ++i;

                }
                break;      
          case '2': case 2://down
                if(i != 0){
                    gotoxy(80 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i-1][j];
                    Mat[i][j] = Mat[i][j] + Mat[i-1][j];
                    Mat[i-1][j] = Mat[i][j] - Mat[i-1][j];
                    Mat[i][j] = Mat[i][j] - Mat[i-1][j];
                    --i;
                }
                break; 
            case '4': case 4://left
                if(j != size-1){
                    gotoxy(80 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j+1];
                    Mat[i][j] = Mat[i][j] + Mat[i][j+1];
                    Mat[i][j+1] = Mat[i][j] - Mat[i][j+1];
                    Mat[i][j] = Mat[i][j] - Mat[i][j+1];
                    ++j;
                }
                break; 
            case '6': case 6://right
                if(j != 0){
                    gotoxy(80 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j-1];
                    Mat[i][j] = Mat[i][j] + Mat[i][j-1];
                    Mat[i][j-1] = Mat[i][j] - Mat[i][j-1];
                    Mat[i][j] = Mat[i][j] - Mat[i][j-1];
                    --j;
                }
                break; 
 }

};

#endif
