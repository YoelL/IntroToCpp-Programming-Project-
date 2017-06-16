//
//  Simulation.h
//  CyberWarfare-Ex3
//
//  Created by Yoel Lev on 12/26/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __CyberWarfare_Ex3__Simulation__
#define __CyberWarfare_Ex3__Simulation__

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include "Package.h"

/*Once all dtat from files was verified in the presimulation, it sends the info to the simulation and instanciate the Defense and Offense instences and starts the simulation */

using namespace std;

class Simulation{
public:
    
    //C'tors
    Simulation();
    Simulation(size_t offenseRALen ,size_t oVectorLen ,size_t defenseRALen,size_t deVectorLen,string **offenseMat,string **defenseMat,size_t gen,string OFP , string DFP);
    ~Simulation();
    
    
    //Vars
    size_t ofRALen;
    size_t defRALen;
    size_t maxGen;
    string ofenseFPath;
    string defenseFPath;
    
    //Defense & Offense instences
    Package *offense;
    Package *defense;
    
    //Methods
    
    void displayAllCurrentPackages();
    bool startSimulation();
    void updatePackages(size_t ioffense); // uses the % sign to update the packages.
    bool checkPackageIdentity(); //checks for equality from the offense package using the updated defense package.
    void tagStrengthToDefense();  // tags the strength of an updated package.
    void finishSimulation();// finishes simulation and write data to offense file.
    
    //Sort functions
    void QuickSort(Package a[], int beg, int end);
    int Partition(Package a[], int beg, int end);
    //Loading
    void  loading();
};

#endif /* defined(__CyberWarfare_Ex3__Simulation__) */
