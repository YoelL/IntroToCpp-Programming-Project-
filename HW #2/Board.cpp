//
//  Board.cpp
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Board.h"


//default C'tor
Board::Board(){
    
}

//C'tor
Board::Board(int m, int n , int k ){
    
    sizeX    = n;
    sizeY    = m;
    sequance = k;
    
    initBoard();
}

//D'tor
Board:: ~Board(){
    
    for(int i = 0; i < sizeY; ++i) {
        delete [] board[i];
    }
    delete [] board;
    
}

//Initiate the board
void Board:: initBoard(){
    
    //creates the board.
    board = new int*[sizeY];
    for(int i = 0; i < sizeY; ++i) {
        board[i] = new int[sizeX];}
    
    //init board with Zeros.
    for (int row = 0 ; row < sizeY; row++) {
        for (int col =0; col < sizeX; col++) {
            board[row][col]=0;
        }
    }
    
}

//Draw Board on console
bool Board:: drawBoard(){
    

    //Info
    //Black = 1 , White = 2.
    
    for (int row = 0 ; row < sizeY; row++) {
        for (int col =0; col < sizeX; col++) {
            
            int curValue = board[row][col];
            
            // if Black
            if ( curValue == 1  ) {
                cout<<" B ";
            }
            if ( curValue == 2  ) {
                cout<<" W ";
                
            }
            if ( curValue == 0  ) {
                cout<<" O ";
                
            }
        }
        cout<<row+1<<endl;
    }
    
    char alpha = 'A';
    for (int index  = 0 ; index < sizeX; index++) {
        cout<<" "<<alpha<<" ";
        alpha++;
    }
    
    cout<<endl<<endl;
    
    return true;
}
