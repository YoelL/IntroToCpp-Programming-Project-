//
//  Simulation.cpp
//  SimCyber-Ex3
//
//  Created by Yoel Lev on 12/30/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Simulation.h"

//C'tors
Simulation::  Simulation(){
    
     maxGen =(10*10*10*10*10*10);
}

Simulation::  Simulation(size_t offenseRALen ,size_t oVectorLen ,size_t defenseRALen,size_t deVectorLen,string **offenseMat,string **defenseMat,size_t gen,string OFP , string DFP){
    
    ofRALen=offenseRALen;
    defRALen=defenseRALen;
    maxGen=gen;
    
    ofenseFPath=OFP;
    defenseFPath=DFP;
    
    //allocate offense array
    offense = new Package[ofRALen];
    //allocate defense array
    defense = new Package[defRALen];
    
    
    //init offense array & sets vector Length
    for (int indexAtPath = 0 ; indexAtPath < ofRALen; indexAtPath++){
        offense[indexAtPath].setPackage(*offenseMat[indexAtPath]);
        offense[indexAtPath].packLength=oVectorLen;
    }
    
    //init defense array & sets vector Length
    for (int indexAtPath = 0 ; indexAtPath < defRALen; indexAtPath++){
        defense[indexAtPath].setPackage(*defenseMat[indexAtPath]);
        defense[indexAtPath].packLength=deVectorLen;
    }

}


Simulation::  ~Simulation(){
    
    delete [] offense;
    delete [] defense;
 
}

void Simulation:: displayAllCurrentPackages(){
    
    
    //display offense package on cosole.
    cout<<"-Offense-"<<endl;
    for (int indexAtPath = 0 ; indexAtPath < ofRALen; indexAtPath++) {
        cout<<offense[indexAtPath].package<<endl;
    }
    cout<<endl;
    //display defense package on cosole.
    cout<<"-Defense_ "<<endl;
    for (int indexAtPath = 0 ; indexAtPath < defRALen; indexAtPath++) {
        cout<<defense[indexAtPath].package<<endl;
        //cout<<"Strength:  "<<defense[indexAtPath].strength<<endl;
    }
    
    
}

bool Simulation:: startSimulation(){
    
    cout<<"ReStart Simulation"<<endl;
    size_t option = maxGen;
    
    switch (option) {
    
        case 0:
            updatePackages(0);
            tagStrengthToDefense();
            finishSimulation();
            break;
            
        default:
            
            tagStrengthToDefense();
            
            for (int i = 0 ; i < ofRALen-1; i++) {
                updatePackages(i);
            }
            
             QuickSort(defense,int(defRALen/2), (int)defense->getPackageLength());
            
            if (checkPackageIdentity() == true) {
                cout<<"Match was found"<<endl;
                finishSimulation();
                return true;
            }else{
                //run another simulation
               
                return false;
            }
            
            
            break;
    }
    
    
    return false;
}


void Simulation:: updatePackages(size_t ioffense){
    
   // cout<<"in updatePackages"<<endl;
    size_t tempMaxGen = maxGen;
    Package temp;
    int tempStrengthBefore;
    int tempStrengthAfter;
    
    while (tempMaxGen > 0) {  //runs until maxGen is exusted
        
        for (int Idefense = 0 ; Idefense < defRALen ; Idefense++) {
            
                tempStrengthBefore =( defense[Idefense] == defense[ioffense]);
            
                temp = defense[Idefense] % offense[ioffense];
            
                tempStrengthAfter = (temp == offense[ioffense]);
            
            if(tempStrengthBefore < tempStrengthAfter){
                defense[Idefense] = defense[Idefense] % offense[ioffense];
            }

        }
        
        tempMaxGen--;
    }
    
    
    
}

bool Simulation:: checkPackageIdentity(){
    
     // cout<<"in checkPackageIdentity"<<endl;
    
    for (int i = 0 ; i < ofRALen; i++) {
        
        for (int j = 0 ; j < defRALen ; j++) {
            
            string op =offense[i].package;
            string dp = defense[j].package;
            
            if ( op==dp ) {
                offense[i].strength = defense->getPackageLength();
                return true;
            }
            
        }
    }
    
    return false;
}

void Simulation:: tagStrengthToDefense(){
    
   // cout<<"in tagStrengthToDefense"<<endl;
    
    for (int iO = 0 ; iO < ofRALen; iO++) {
        for (int iD =0; iD < defRALen; iD++) {
            
            defense[iD].strength = (defense[iD] == offense[iO]);

        }
    }

    
    
}

//Function to Find Pivot Point

int Simulation:: Partition(Package a[], int beg, int end){
    
    int p = beg, pivot=(int)a[beg].strength, loc;
    
    for(loc=beg+1;loc<=end;loc++){
        if(pivot>a[loc].strength){
            a[p].strength=a[loc].strength;
            a[loc].strength=a[p+1].strength;
            a[p+1].strength=pivot;
            
            p=p+1;
        }
				}
    return p;
}

void Simulation:: QuickSort(Package a[], int beg, int end){
    
    if(beg<end){
        int p=Partition(a,beg,end);
        QuickSort(a,beg,p-1);
        QuickSort(a,p+1,end);
    }
}


void Simulation:: finishSimulation(){
    // cout<<"in finishSimulation"<<endl;
    
    //write to file the outcome.
    for (int i = 0 ; i < defRALen; i++) {
        string line = defense[i].package;
        for (int bit = 0 ; bit < defRALen ; bit++) {
            
            ofstream WFile(defenseFPath.c_str(),ios::app);
            WFile<<line[bit]<<" ";
            if (bit == (defRALen-1)) {
                WFile<<line[bit]<<endl;
                WFile.close();
            }
 
        }
        
    }
    
    exit(1);
    
}
