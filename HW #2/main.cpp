//
//  main.cpp
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.

#include <iostream>
#include <stdlib.h>
#include "Game.h"

//the sign  //* are for debuging purpose.


int main(int argc, const char * argv[]) {
  
    bool ValidInput;
    
    Game newGame;
    
    if (argc == 4) {
        newGame.setM(atoi(argv[1]));
        newGame.setN(atoi(argv[2]));
        newGame.setK(atoi(argv[3]));
        
        ValidInput = newGame.checkInput();
        
        if (ValidInput == false) {
            do {
                newGame.getInput();
                ValidInput = newGame.checkInput();
            } while (ValidInput == false);
        }
        
        newGame.run_mnkGame(newGame.M, newGame.N, newGame.K);
    }

    return 0;
}
