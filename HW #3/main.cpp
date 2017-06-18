//
//  main.cpp
//  SimCyber-Ex3
//
//  Created by Yoel Lev on 12/30/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.


#include <iostream>
#include "PreSimulation.h"
#include "Simulation.h"
#include "Package.h"


int main(int argc, const char * argv[]) {
    
    bool res ;
    if (argc != 4 ) {
        cout<<"Wrong parameters !"<<endl;
        exit(1);
    }else{
        
        PreSimulation simCyber(argv[1],argv[2],argv[3]);
        Simulation newSim(simCyber.offenseGroupSize,simCyber.vectorLength,simCyber.defenseGroupSize,simCyber.vectorLength,simCyber.offense,simCyber.defense,simCyber.maxGen,simCyber.offenseFile,simCyber.defenseFile);
        
        //cleans "defense.dat" file
        std::ofstream aFile;
        aFile.open("defense.dat", std::ofstream::out | std::ofstream::trunc);
        aFile.close();
        
        size_t maxRounds =newSim.maxGen;
        
        do {
            
            res = newSim.startSimulation();
            maxRounds--;
            
        } while (res == false || maxRounds > 0 );
        
    }
    
    return 0;
}
