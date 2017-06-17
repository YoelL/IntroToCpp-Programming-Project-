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
#include "Tackle.h"
#include "Linebacker.h"
#include "Cornerback.h"
#include "GenericSort.h"
#include "LinkedList.h"

/*Once all dtat from files was verified in the presimulation, it sends the info to the simulation and instanciate the Defense and Offense instences and starts the simulation */

using namespace std;

class Simulation{
public:
    
    //default C'tor
    Simulation();
    Simulation(size_t offenseRALen ,size_t oVectorLen ,size_t DGST,size_t DGSL,size_t DGSC,size_t deVectorLen,string **offenseMat,string **defenseMat,size_t gen,string OFP , string DFP);
    ~Simulation();
    
    
    //Vars
    size_t ofRALen;
    size_t dGroupSizeT;
    size_t dGroupSizeL;
    size_t dGroupSizeC;
    size_t defRALen;
    size_t maxGen;
    size_t allDGroupSize;
    string ofenseFPath;
    string defenseFPath;
    
    //Defense & Offense instences
    Package    *offense;
    Package    *defense;
    //TLC Packages
    Tackle     *tackle;
    Linebacker *linebacker;
    Cornerback * cornerback;
    //Genric LL
    LinkedList<string> simCyberLL;
    
    
    //Methods
    
    void displayAllCurrentPackages();
    void startSimulation();
    void updatePackages(size_t ioffense); // uses the % sign to update the packages.
    bool checkPackageIdentity(); //checks for equality from the offense package using the updated defense package.
    void tagStrengthToDefense();  // tags the strength of an updated package.
    void finishSimulation();// finishes simulation and write data to offense file.
    
    //Sort functions
    void QuickSort(Package a[], int beg, int end);
    int Partition(Package a[], int beg, int end);
    
    //Loading
    void loading();
    
    //adds all the defense team to LL.
    void addToGenricLL();
    //preupdates the TLC packages.
    void preUpdatePackages();
    
    //generates a random float for the Probability of the packcages.
    float RandomFloat(float a, float b);
    
    //helper method to preUpdatePackages().
    void xorString(string pack);
    
    //verifies that the TLC package is valid
    bool checkPackage();
    
};

#endif /* defined(__CyberWarfare_Ex3__Simulation__) */
