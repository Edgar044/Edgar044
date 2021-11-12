#ifndef START_H
#define START_H
#include <iostream>
#include <iomanip>
#include "input.hpp"
#include "fun.hpp"
//head of functions for Start_Game
void Show_Board(const int Center, int size);
void step(int **Mat, int &i, int &j, int size,  char step_num, const int Board_Col );
bool chek_win(int **Mat, const int size);
//the Start main function
void Start_Game(const int Center, const int board_size){
    
    int num=0;
    int** matrix = new int*[board_size];
    for(int i = 0; i < board_size; ++i){
        matrix[i] = new int[board_size];
    }
    
    Show_Game_Name(Center);
    for(int i=0; i<board_size; ++i){
        for(int j=0; j<board_size; ++j){
          matrix[i][j]=++num;
        }
    }
    
    Show_Board(Center, board_size);
    int Board_Col =Center - (board_size * 4)/2; //vorpisi tpi mejtexic

    for(int i=0; i<board_size; ++i){
        gotoxy(Board_Col + 1,15 + 2*i);
        for(int j=0; j<board_size; ++j){
            std::cout<<std::setw(2)<<matrix[i][j]<<" ║";
        }
         std::cout<<"\n";
    }

    int index_i = board_size - 1;
    int index_j = board_size - 1;
    int ptr_x=Board_Col + index_i*4;//cucichi
    int ptr_y=15 + index_j*2;//skzbnakan kordinatnery
    
    bool mix=0, win = 0;    
    for(char key_1 = -1; key_1 != 27;){
        ptr_x=Board_Col + 1 + index_j*4; 
        ptr_y=15 + index_i*2;
        gotoxy(ptr_x, ptr_y);std::cout<<"  ";
        cbreak();
        
        if(!mix){
            mix=1; // xarnum e xaxaqarery
            do{
                int step_key; step_key= (rand()%4+1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col);
            }while(matrix[board_size-1][board_size-1] != 1);

            do{
                int step_key; step_key= (rand()%4+1) * 2;
                step(matrix, index_i, index_j, board_size, step_key, Board_Col);
            }while(matrix[board_size-1][board_size-1] != board_size*board_size);
            //step(matrix, index_i, index_j, board_size, 8);
        }
       
    
        key_1 = keypress();
        step(matrix, index_i, index_j, board_size, key_1,Board_Col);
        win = chek_win(matrix, board_size);
        //normal();
        //
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
      for(char key_2 = -1;;){
            int color = rand()%8;
            gotoxy(Board_Col,20);Color_Cout("YOU WIN\n",color);
            cbreak();
            key_2 = keypress();
            if(key_2 == 'q'){
                break;             }
        }  
    } else { 
        std::cout<<"\n"; // grum enq nor toxic vorpiso 0.0 ketum axb chtpi 
    }

    
}

//functions bodies
void Show_Board(const int Center, int size){
    int lenght = size * 4;
    int hight = size * 2;
    int Board_Col = Center - (lenght / 2 );
    for(int i=0; i<size; i++){
        if(i == 0){

            for(int j = 0; j < lenght; ++j ){
                gotoxy(Board_Col + j, 14); 
                if((j%4==0) && (j!=0)){
                    std::cout<<"╤";
                }else{
                    std::cout<<"═";
                }
                
            }
        }
        for(int j=0; j<lenght; j++){
            gotoxy(Board_Col + j,16 + (i * 2)); 
            if(j % 4 == 0){
                std::cout<<"┼";
            } 
            std::cout<<"―";
        }
        if(i == (size-1)){

            for(int j=0; j<lenght; ++j){
                gotoxy(Board_Col + j,14 + hight);
                if(j % 4 == 0){
                    std::cout<<"╧";
                }else{
                    std::cout<<"═";
                }
            }

        }
      
    }
    
   for(int i=0; i<hight + 1; i++){
        gotoxy(Board_Col,14 + i); std::cout<<"║";
        gotoxy(Board_Col + lenght,14 + i); std::cout<<"║";
         }

    gotoxy(Board_Col, 14); std::cout<<"╔";
    gotoxy(Board_Col, 14 + hight); std::cout<<"╚";
    gotoxy(Board_Col + lenght, 14); std::cout<<"╗";
    gotoxy(Board_Col + lenght, 14 + hight); std::cout<<"╝";

}


void step(int **Mat, int &i, int &j,const int size, char step_num,const int Board_Col ){

 switch(step_num){
          case '8': case 8://up
                if(i != size-1){
                    gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i+1][j]; 
                    Mat[i][j] = Mat[i][j] + Mat[i+1][j];
                    Mat[i+1][j] = Mat[i][j] - Mat[i+1][j];
                    Mat[i][j] = Mat[i][j] -  Mat[i+1][j];
                    ++i;

                }
                break;      
          case '2': case 2://down
                if(i != 0){
                    gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i-1][j];
                    Mat[i][j] = Mat[i][j] + Mat[i-1][j];
                    Mat[i-1][j] = Mat[i][j] - Mat[i-1][j];
                    Mat[i][j] = Mat[i][j] - Mat[i-1][j];
                    --i;
                }
                break; 
            case '4': case 4://left
                if(j != size-1){
                    gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j+1];
                    Mat[i][j] = Mat[i][j] + Mat[i][j+1];
                    Mat[i][j+1] = Mat[i][j] - Mat[i][j+1];
                    Mat[i][j] = Mat[i][j] - Mat[i][j+1];
                    ++j;
                }
                break; 
            case '6': case 6://right
                if(j != 0){
                    gotoxy(Board_Col + 1 + j*4, 15 + i*2); std::cout<<std::setw(2)<<Mat[i][j-1];
                    Mat[i][j] = Mat[i][j] + Mat[i][j-1];
                    Mat[i][j-1] = Mat[i][j] - Mat[i][j-1];
                    Mat[i][j] = Mat[i][j] - Mat[i][j-1];
                    --j;
                }
                break;
 };

};
 
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



#endif
