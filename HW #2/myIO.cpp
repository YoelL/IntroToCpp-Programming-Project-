//
//  myIO.cpp
//  TicTacToe
//
//  Created by Yoel Lev on 11/27/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "myIO.h"

myIO::myIO(){
    
    
}

bool myIO:: checkPlayerName(string player ){
    
    int len = (int)player.length();
    
    if (len > 8  ) {
        return false;
    }
    
    for (int i = 0 ; i < len; i++) {
        if (!(isalpha(player[i]))) {
            return false;
        }
    }
    return true;
}
