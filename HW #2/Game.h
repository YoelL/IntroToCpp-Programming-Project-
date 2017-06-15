//
//  Game.h
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __mnkGame__Game__
#define __mnkGame__Game__
#include <iostream>
#include "mnkGame.h"
using namespace std;

class Game{
    
public:

    //C'tos
    Game();
    Game(int m ,int n ,int k);
    
    //Methods
    bool run_mnkGame(int m ,int n ,int k);  //Game rutine function.
    bool checkInput(); // verifies that the MNK param ara valid.
    void getInput(); //gets MNK params.
    void setM(int m);
    void setN(int n);
    void setK(int k);
   
    int  quitGame(mnkGame game); //Deallocate and quits game.
    
    //Vars
    int M,N,K;

};
#endif /* defined(__mnkGame__Game__) */
