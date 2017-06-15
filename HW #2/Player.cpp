//
//  Player.cpp
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Player.h"

Player:: Player(){
    
}
Player:: Player(string player){
    playerName = player; 
}

string Player:: getPlayerName(){
    
    return this->playerName;
}


void Player:: setPlayerName(string player){
    
    playerName =player;
}