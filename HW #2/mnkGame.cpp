//
//  mnkGame.cpp
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "mnkGame.h"
#include <string>
#include <sstream>

//This is the games logic.

//defaulr C'tor
mnkGame:: mnkGame(){
    
}
//C'tor
mnkGame:: mnkGame( int M ,int N ,int K )
:GameBoard(M,N,K)
{
    this->sequenceTarget = K;
    turn = 0;
    x=N;
    y=M;
    z=K;
  //*  cout<<"mnk init"<<endl;
}
//C'tor
mnkGame:: mnkGame( int M ,int N ,int K ,string B , string W)
:GameBoard(M,N,K)
{
    Black.playerName=B;
    White.playerName=W;
    this->sequenceTarget = K;
    turn = 0;
    x=N ;
    y=M;
    z=K;
   //* cout<<"Players Were Created !"<<endl;
}

mnkGame::  ~mnkGame(){
    /*
    for (int i = 0 ; i < y ; i++) {
        delete [] GameBoard.board[i];
    }
    delete [] GameBoard.board ;
    
    cout<<"D'tor Calld"<<endl;*/
    
}


bool mnkGame:: getMove(){
    
    bool checksIf;
    
    do {
        // cout<<"Please enter your Move!"<<endl;
        cin>>playersMove;
        checksIf = validMove(playersMove);
    } while (checksIf == false);
    
    return true;
}

bool mnkGame:: makeMove(int alpha , int number,int player ){
    
    int currValue = GameBoard.board[number][alpha];
    
    if (currValue == 0) {
        GameBoard.board[number][alpha]=player;
        return true;
    }else{
        
        return false;
    }
    
    return true;
}

bool mnkGame:: validMove(string move){
    
    char alpha;
    int Num;
    
    int len = (int)move.length();

    if (move == "QUIT") {
        if (turn%2 == 1 ) {
            declalreWinner(1);
        }else{
            declalreWinner(2);
        }
        exit(1);
    }

    if (len > 3 ) {
        return false;
    }
    
    for (int i = 0 ; i < len; i++) {
        if (move[i]== ' ') {
            return false;
        }
    }
    
    if (!(isupper(move[0]))) {
        return false;
    }
    
    if (!(isdigit(move[1]))) {
        return false;
    }
    

    stringstream CN(move);
    CN >> alpha >> Num ;
    
    int curAlpha = alpha -'A';
    
    
    if (curAlpha >= x ) {
        return false;
    }
    if (Num >= y ) {
        return false;
    }
    
   //*  cout<<"Alpha: "<<alpha<<" Number: "<<Num<<endl;
    //transform Move
    
    convertMove(move);
    
    return true;
}

void mnkGame:: convertMove(string move){
    
    int alpha  = move[0] - 'A';
    int number = atoi(&move[1]);
    pawnPos[0] = alpha;
    pawnPos[1] = number-1;

   //* cout<<"Alpha "<<pawnPos[0]<<" Number "<< pawnPos[1]<<endl;
   
}

bool mnkGame:: searchForSequance(int fromCurrPosition[2] ,int forPlayer){
    
    int col = 0,row =0 ,mainD =0 ,secD=0;
    
     row   =sumRow(GameBoard.board, fromCurrPosition[1], GameBoard.sizeX, forPlayer);
     col   =sumCol(GameBoard.board, fromCurrPosition[0], GameBoard.sizeY, forPlayer);
     mainD =sumDiagonal(GameBoard.board, fromCurrPosition, GameBoard.sizeX,GameBoard.sizeY, forPlayer);
     secD  =sumSecDiagonal(GameBoard.board, fromCurrPosition, GameBoard.sizeX, GameBoard.sizeY, forPlayer);
    
    // Row
    if (row == sequenceTarget) {
        cout<<"Congratulations we Have a sequence Target of Row!"<<endl;
        return true;
    }
    //Col
    if (col == sequenceTarget) {
        cout<<"Congratulations we Have a sequence Target of Colum!"<<endl;
        return true;
    }
    
    //Main Diagonal
    if (mainD == sequenceTarget) {
        cout<<"Congratulations we Have a sequence Target of Diagonal!"<<endl;
        return true;
    }
    
    //Second Diagonal
    if (secD == sequenceTarget) {
        cout<<"Congratulations we Have a sequence Target of Second Diagonal1"<<endl;
        return true;
    }
    
    
    
    return false;
}

int  mnkGame:: sumRow(int** board,int row,int size,int player){
    
    //the Var row represent the row that is being search for a sequance.
    //the Var Size represent the length of the board.
    //the Var Player represent for which player the sequance is looked for.
    
    int sum = 0;
    
    for(int index = 0 ;index < size ;index++){
        
        int curVal=board[row][index];
        if (sum == sequenceTarget) {
            return sum;
        }
        if (curVal == player) {
            sum++;
        }else{
            sum =0;
        }
    }
    return sum;
}

int  mnkGame:: sumCol(int** board,int col,int size,int player){
    //the Var col represent the col that is being search for a sequance.
    //the Var Size represent the length of the board.
    //the Var Player represent for which player the sequance is looked for.
    
    int sum = 0;
    
    for(int index = 0 ;index < size ;index++){
        
        int curVal=board[index][col];
        if (sum == sequenceTarget) {
            return sum;
        }
        if (curVal == player) {
            sum++;
        }else{
            sum =0;
        }
    }
    return sum;
}

int  mnkGame:: sumDiagonal(int** board,int fromCurrPosition[2],int x,int y ,int player){
    
    int sum =0;
    int row = fromCurrPosition[1];
    int col = fromCurrPosition[0];
    
  //*  cout<<"Started at  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
   
    //go to begining of diagonal
    while (row != 0 && col !=0) {
        
        if (row != 0) {
            row--;
        }
        if (col != 0) {
            col--;
        }
      //*  cout<<"in  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
    }
    
   //* cout<<"stoped at  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
    
    //Sum diagonal
    while (col != x && row != y  ) {
        
        int curValue =board[row][col];
        
        if (sum == sequenceTarget) {
            return sum;
        }
        
        if (curValue == player) {
            sum++;
        }
        
        if (curValue == 0 ) {
            sum=0;
            col++;
            row++;
            continue;
        }
        
        col++;
        row++;
        
    }
    return sum;
    
}

int  mnkGame:: sumSecDiagonal(int** board,int fromCurrPosition[2],int x,int y,int player){
    
    int sum =0;
    int row = fromCurrPosition[1];
    int col = fromCurrPosition[0];
    
 //*   cout<<"Started at  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
    
    //go to begining of diagonal
    while (row != 0 && col != (x-1)) {
        
        if (row != 0) {
            row--;
        }
        if (col != (x-1) ) {
            col++;
        }
     //*   cout<<"in  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
    }
    
   //* cout<<"stoped at  position: "<<row<<"-"<<col<<" is "<<board[row][col]<<endl;
    
    //Sum diagonal
    while (col != x && row != y  ) {
        
        int curValue =board[row][col];
        
        if (sum == sequenceTarget) {
            return sum;
        }
        
        if (curValue == player) {
            sum++;
        }
        
        if (curValue == 0 ) {
            sum=0;
            col--;
            row++;
            continue;
        }
        
        col--;
        row++;
        
    }
    return sum;  
}

void mnkGame:: declalreWinner(int player){
    
    if (player == 1) {
        cout<<"Black Player was the Winner"<<endl;
    }
    if (player == 2) {
        cout<<"White Player was the Winner"<<endl;
    }
    
}
