//
//  Board.h
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __mnkGame__Board__
#define __mnkGame__Board__

#include <iostream>
using namespace std;

class Board{
    
public:
    
    //C'tors
    Board();
    Board(int m ,int n ,int k);
    
    //D'tor
    ~Board();
    
    //Methods
    void initBoard(); //allocate and init board with zeros.
    bool drawBoard(); //draws board on console.
    
    //Vars
    int **board;
    int sequance;
    int sizeX ;
    int sizeY ;
 
    
};

#endif /* defined(__mnkGame__Board__) */
