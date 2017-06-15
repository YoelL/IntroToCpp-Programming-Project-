//
//  Game.cpp
//  mnkGame
//
//  Created by Yoel Lev on 12/3/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//
#include <stdlib.h> 
#include "Game.h"
#include "mnkGame.h"

Game:: Game(){
    
}

Game:: Game(int m ,int n ,int k){
    
    run_mnkGame(m, n , k);
}

bool Game ::run_mnkGame(int m ,int n ,int k){
  
    
    myIO stringCheck;
    string PlayerB,PlayerW;
    bool ValidInput;
    int turn,result = 0;
    enum players{BlackPlayer,WhitePlayer};
    
    
    //Gets Players Name.
    do {
        cout<<"Please Enter Black Player Name"<<endl;
        cin>>PlayerB;
        ValidInput = stringCheck.checkPlayerName(PlayerB);
        
    } while (ValidInput == false);
    
    do {
        cout<<"Please Enter White Player Name"<<endl;
        cin>>PlayerW;
        ValidInput = stringCheck.checkPlayerName(PlayerW);
    } while (ValidInput == false);
    
    
    //init mnkGame .
    mnkGame myGame(m, n, k, PlayerB, PlayerW);
    myGame.GameBoard.drawBoard();

    
    do {
        
        if (myGame.turn %2 == 0) {
            turn =0;
        }else{
            turn =1;
        }
    
        bool res;
        
        switch (turn) {
          
            case BlackPlayer :
              
            
                do {
                    cout<<myGame.Black.getPlayerName()<<":";
                    res = myGame.getMove();
                } while ( res  == false);

                    myGame.makeMove(myGame.pawnPos[0], myGame.pawnPos[1], 1);
                    myGame.GameBoard.drawBoard();
                    result =myGame.searchForSequance(myGame.pawnPos,1);
                    
                     if (result == true) {
                     myGame.declalreWinner(1);
                     quitGame(myGame);
                     }
                
                
                break;
        
            case WhitePlayer :
              
                do {
                    cout<<myGame.White.getPlayerName()<<":";
                    res = myGame.getMove();
                } while (res == false);
                    
                    myGame.makeMove(myGame.pawnPos[0], myGame.pawnPos[1], 2);
                    myGame.GameBoard.drawBoard();
                    result =myGame.searchForSequance(myGame.pawnPos,2);
                    
                     if (result == true) {
                     myGame.declalreWinner(2);
                     quitGame(myGame);
                     }
                break;

                
            default:
                break;
        }
        
        myGame.turn++;
        
    } while (true);
    
    return  true;
    
}

bool Game:: checkInput(){
    
    if (!(isdigit(M) || !(isdigit(N)) || !(isdigit(K)))) {
        return false;
    }
    
    //checks if Board args are valid.
    if ((M >=27 || M <= 2) || (N >=27 || N <= 2) ) {
        return false;
    }
    
    if (K > M && K > N) {
        return false;
    }
    
    return true;
}

void Game:: getInput(){
    
    int m,n,k;
    
    cout<<"Please enter M-N-K parameters to start."<<endl;
    cin>>m>>n>>k;
    
    setM(m);
    setN(n);
    setK(k);
}

void Game:: setM(int m){
    this->M = m;
    
}

void Game:: setN(int n){
    this->N = n;
    
}

void Game:: setK(int k){
    this->K = k;
}

int  Game:: quitGame(mnkGame game){
    
    //calls mnkGame D'tor end exits the game.
    game.~mnkGame();
    exit(0);
    
    return 0;
}