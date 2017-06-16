//
//  PreSimulation.h
//  SimCyber-Ex3
//
//  Created by Yoel Lev on 12/30/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __SimCyber_Ex3__PreSimulation__
#define __SimCyber_Ex3__PreSimulation__

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdlib.h>

using namespace std;

class PreSimulation{
    
public:
    
    //C'tors
    PreSimulation();
    PreSimulation(std::string configF,std::string offenseF ,std::string defenseF);
    ~PreSimulation();
   
    
    //Vars
    string configFile ,offenseFile ,defenseFile;
    string **offense ,**defense;
    size_t vectorLength;
    size_t defenseGroupSize;
    size_t offenseGroupSize;
    size_t maxGen;
    
    void getInfo();
    void getOffense();
    void createDeffenseMat();
    void createOffensMat();
    string toString(string line);
    string NumberToString ( int Number );
    void displayAllInfo();
    void doubleCheckParam();
    
};

#endif /* defined(__SimCyber_Ex3__PreSimulation__) */
