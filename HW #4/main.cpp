//
//  main.cpp
//  SimCyber-Ex4
//
//  Created by Yoel Lev on 1/9/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

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
     
    PreSimulation simCyber("config.dat" ,"offense.dat" ,"defense.dat");
  
    //display all data for deubg perpus
   //*  simCyber.displayAllInfo();
    
    size_t tempGen =simCyber.maxGen;
   
        do {
        
        Simulation newSim(simCyber.offenseGroupSize,simCyber.vectorLength,simCyber.defenseGroupSizeT,simCyber.defenseGroupSizeL,simCyber.defenseGroupSizeC,simCyber.vectorLength,simCyber.offense,simCyber.defense,simCyber.maxGen,simCyber.offenseFile,simCyber.defenseFile);
        
      //*newSim.displayAllCurrentPackages();
        
        //cleans "defense.dat" file
        std::ofstream aFile;
        aFile.open("defense.dat", std::ofstream::out | std::ofstream::trunc);
        aFile.close();
        
        
         newSim.startSimulation();
         res = newSim.checkPackage();
         tempGen--;
        
        } while (res == false  &&  tempGen > 1);
   
    }
    
    return 0;
}
