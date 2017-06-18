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

Simulation::  Simulation(size_t offenseRALen ,size_t oVectorLen ,size_t DGST,size_t DGSL,size_t DGSC,size_t deVectorLen,string **offenseMat,string **defenseMat,size_t gen,string OFP , string DFP){
    
    ofRALen=offenseRALen;
    defRALen =deVectorLen;
    dGroupSizeT=DGST;
    dGroupSizeL=DGSL;
    dGroupSizeC=DGSC;
    allDGroupSize = (dGroupSizeT+dGroupSizeL+dGroupSizeC);
    maxGen=gen;
    
    ofenseFPath=OFP;
    defenseFPath=DFP;
    
    //allocate offense array
    offense = new Package[ofRALen];
    //allocate defense array
    defense = new Package[allDGroupSize];
    
    tackle = new Tackle[dGroupSizeT];
    
    linebacker = new Linebacker[dGroupSizeL];
    linebacker->setLinebackerProbability(deVectorLen);
    
    cornerback = new Cornerback[dGroupSizeC];
   
    //init offense array & sets vector Length
    for (int indexAtPath = 0 ; indexAtPath < ofRALen; indexAtPath++){
        offense[indexAtPath].setPackage(*offenseMat[indexAtPath]);
        offense[indexAtPath].packLength=oVectorLen;
    }
    
    //init defense array & sets vector Length
    for (int indexAtPath = 0 ; indexAtPath < allDGroupSize; indexAtPath++){
        defense[indexAtPath].setPackage(*defenseMat[indexAtPath]);
        defense[indexAtPath].packLength=deVectorLen;
    }
    
    //init tackle array & sets vector Length
    for (int indexAtPath = 0 ; indexAtPath < dGroupSizeT; indexAtPath++){
        tackle[indexAtPath].setPackage(*defenseMat[indexAtPath]);
        tackle[indexAtPath].packLength=deVectorLen;
    }
    
    //init Linebacker array & sets vector Length
    int i = 0 ;
    for (int indexAtPath =(int)dGroupSizeT ; indexAtPath < (dGroupSizeT+dGroupSizeL) ; indexAtPath++){
        linebacker[i].setPackage(*defenseMat[indexAtPath]);
        linebacker[i].packLength=deVectorLen;
        i++;
    }
    
    //init cornerback array & sets vector Length
     i = 0 ;
    for (int indexAtPath =(int)(dGroupSizeT+dGroupSizeL); indexAtPath < (dGroupSizeT+dGroupSizeL+dGroupSizeC) ; indexAtPath++){
        cornerback[i].setPackage(*defenseMat[indexAtPath]);
        cornerback[i].packLength=deVectorLen;
        i++;
    }
    
    //creats genric LL
    LinkedList<string> simCyberLL(new Node<string>());
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
    cout<<"-all Defense_ "<<endl;
 
    for (int indexAtPath = 0 ; indexAtPath < allDGroupSize; indexAtPath++) {
        cout<<defense[indexAtPath].package<<endl;
        //cout<<"Strength:  "<<defense[indexAtPath].strength<<endl;
    }
    
    cout<<endl<<"-Tackle- "<<endl;
    
    for (int indexAtPath = 0 ; indexAtPath < dGroupSizeT; indexAtPath++) {
        cout<<tackle[indexAtPath].package<<endl;
        
    }
    
    cout<<endl<<"-linebacker-"<<endl;
    
    for (int indexAtPath = 0 ; indexAtPath < dGroupSizeL; indexAtPath++) {
        cout<<linebacker[indexAtPath].package<<endl;
        
    }
    
    cout<<endl<<"-cornerback-"<<endl;
    
    for (int indexAtPath = 0 ; indexAtPath < dGroupSizeC; indexAtPath++) {
        cout<<cornerback[indexAtPath].package<<endl;
        
    }
    
    
}

void Simulation:: startSimulation(){
    
    cout<<"ReStart Simulation"<<endl;
    
    //pre updates the TLC Packages with its Probability.
    preUpdatePackages();

    for (int i = 0 ; i < ofRALen; i++)
        updatePackages(i);
    
     QuickSort(defense,int(defRALen/2), (int)defense->getPackageLength());

  
}

void Simulation:: updatePackages(size_t ioffense){
  
    Package *temp = new Package[allDGroupSize];
    
    for (int i = 0 ; i < allDGroupSize; i++) {
        temp[i] = defense[i] % offense[ioffense];
    }
    
    srand ((int)time(NULL));
    
    int rT = rand()%dGroupSizeT+0;
    int rL = (int)rand()%(dGroupSizeL+0 );
    int rC = rand()%(allDGroupSize +0);
    
    simCyberLL.insertTH(temp[rT].package);
    simCyberLL.insertTH(temp[rL].package);
    simCyberLL.insertTH(temp[rC].package);
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
   
    //get items from LL and prints it
    const  Node<string> *a ;
    
    for (int i = 0 ; i < simCyberLL.getLinkedListSize(); i++) {
        a = &simCyberLL.getItems(i);
        
        string line = a->data;
    
        for (int bit = 0 ; bit < defRALen+1 ; bit++) {
            
            ofstream WFile(defenseFPath.c_str(),ios::app);
            WFile<<line[bit]<<" ";
            
            if (bit == (defRALen)) {
                WFile<<line[bit]<<endl;
                WFile.close();
            }
 
        }
        
    }
    cout<<"Found Match"<<endl;
    exit(1);
}

void Simulation:: addToGenricLL(){
    
    for (int add = 0 ; add < allDGroupSize; add++) {
        simCyberLL.insertTH(defense[add].package);
    }
}

void Simulation:: preUpdatePackages(){
    
    float r = RandomFloat(1.0, 0.0);
    
    if (r < 0.25 ) {
        for (int  row = 0 ; row < dGroupSizeT; row++) {
            xorString(tackle[row].package);
        }
    }
    
    
     r = RandomFloat(1.0, dGroupSizeC);
    
    if (r < dGroupSizeC ) {
        for (int  row = 0 ; row < dGroupSizeC; row++) {
            xorString(cornerback[row].package);
        }
    }
    
}

float Simulation:: RandomFloat(float a, float b) {
    srand ((int)time(NULL));
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void Simulation:: xorString(string pack){
    
    for (int i = 0 ; i < pack.size(); i++) {
        if (pack[i] == '0') {
            pack[i] = '1';
        }else if (pack[i] == '1'){
            pack[i] = '0';
        }
        
    }
}

bool Simulation:: checkPackage(){
    
    const  Node<string> *a ;
    a = &simCyberLL.getItems(0);
      string line = a->data;
    
    if ( isalpha(line[defRALen-1]) ) {
        finishSimulation();
        return true;
    }
    simCyberLL.clear();
    return false;
  
}

