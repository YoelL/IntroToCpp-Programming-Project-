//
//  Package.cpp
//  CyberWarfare-Ex3
//
//  Created by Yoel Lev on 12/25/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Package.h"

//C'tor

Package::Package(){
    
   // cout<<"in Package C'tor 1"<<endl;
    setStrength(0);
    setPackageLength(0);
    
}

Package::Package(string p){
    
   // cout<<"in Package C'tor 2"<<endl;
    setPackage(p);
    setStrength(0);
    setPackageLength(p.length());
}

Package::Package(size_t PL){
    
    cout<<"in Package C'tor 3"<<endl;
    setPackageLength(PL);
}

//Copy C'tor
Package::Package(const Package& p){
    
    package=p.package;
    packLength=p.packLength;
    strength=p.strength;
}


Package::~Package(){
    
    
    
    
}


Package Package:: operator %(Package& p){
    
    updatePackage(p.package);

    return package ;

}


int Package:: operator== (const Package& p1){
  
    int count= 0;

    for (int index = 0 ; index < packLength-1; index++) {
        
        if (p1.package[index] == package[index]) {
            
            count++;
        }
        
    }
    return count;
}


int Package:: operator[](size_t index ){
   
    char c  = this->package[index];
    
    return atoi(&c);
}

/*
Package Package:: operator=( Package& p){
    
    package   = p.package;
    packLength= p.packLength;
    strength  = p.strength ;
    
    return p;
}*/

void Package::setPackage(string Package){
    package=Package;
}

void Package:: setStrength(size_t Strength){
    strength=Strength;
}

void Package:: setPackageLength(size_t packLen){
    packLength=packLen;
}

string Package:: getPackage(){
    return package;
}

size_t Package:: getPackageStrength(){
    return strength;
}

size_t Package:: getPackageLength(){
    return packLength;
}

void Package::displayPackage(){
    
    cout<<package<<endl;
    cout<<"package length is:"<<getPackageLength()<<endl;
    cout<<"package Strength is:"<<strength<<endl;
  
}

void Package:: updatePackage(string otherPackage){
    
    int start,end ;
    string temp,temp2;
    
    /* initialize random seed: */
    srand ((int)time(NULL));
    
    do {
        
        start = rand() % getPackageLength()-1 + 1 ;
        end   = rand() % getPackageLength()-1 + start;
        
        
    } while (end >= getPackageLength()-1);
   
   // cout<<"update package from:"<<start<<" To "<<end<<endl;
   // cout<<"current package:"<<endl<<package<<endl<<otherPackage<<endl;
    
    temp=package.substr(start,end);
    temp2=otherPackage.substr(start,end);
    
    otherPackage.replace(start,end,temp);
    package.replace(start,end,temp2);
    

  // cout<<"Updated packages:"<<endl<<package<<endl<<otherPackage<<endl;
    
}

ostream& operator<<( ostream& o ,Package B ){
    o<< B.package<<endl;
    return o;
}