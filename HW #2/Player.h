//
//  Player.h
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __mnkGame__Player__
#define __mnkGame__Player__

#include <iostream>

using namespace std;

class Player{
    
public:
    
    //C'tors
    
    Player();
    Player(string player);
    
    //Vars
    string playerName ;
    int score;
    
    //methodss
    string getPlayerName();
    void   setPlayerName(string player);
    int    getScore();
    
    
};

#endif /* defined(__mnkGame__Player__) */
