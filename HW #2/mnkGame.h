//
//  mnkGame.h
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __mnkGame__mnkGame__
#define __mnkGame__mnkGame__

#include <stdlib.h> 
#include "Board.h"
#include "Player.h"
#include "myIO.h"

//This is the games logic.

using namespace std;

class mnkGame{
    
public:
    
    //C'tors
    mnkGame();
    mnkGame(int M,int N,int K);
    mnkGame(int M,int N,int K,string B , string W);
    
    //D'tor
    ~mnkGame();
    
    //instances of other Classes.
    Board GameBoard;
    Player Black;
    Player White;
    
    //methods
    bool getMove();//gets the players move.
    bool validMove(string);//gets the string and checks if it is a valid move.
    bool makeMove(int alpha , int number,int player );//makes the players move.
    bool searchForSequance(int fromCurrPosition[2],int forPlayer); //searches for any kind of sequance on board.
    void convertMove(string move);//converts valid move from string to coordinate.
    int sumRow(int** board,int row,int size,int player); //sums a row
    int sumCol(int** board,int col,int size,int player); //sums a colum
    int sumDiagonal(int** board,int fromCurrPosition[2],int x,int y,int player); //sums main diagonal
    int sumSecDiagonal(int** board,int fromCurrPosition[2],int x,int y,int player);//sums secendery diagonal
     void declalreWinner(int player);

    
    //Vars
    int sequenceTarget;
    string playersMove; //Holds the move.
    int turn; //counts the turns.
    int pawnPos[2]; //holds the current position (X,Y) on MNK Board.
    int x,y,z;
};


#endif /* defined(__mnkGame__mnkGame__) */
