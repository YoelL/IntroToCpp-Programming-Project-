//
//  Package.h
//  CyberWarfare-Ex3
//
//  Created by Yoel Lev on 12/25/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#ifndef __CyberWarfare_Ex3__Package__
#define __CyberWarfare_Ex3__Package__

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */
#include <string>     /*append*/


using namespace std;
class Package{
    
public:
    
    //default C'tor
    Package();
    Package(string p);
    Package(size_t PL);
    Package(const Package& p); //copy constructor
    ~Package();
    
    Package operator %(Package& p); // update operator
    int operator== (const Package& p1); // returns the strength of the LHS package.
    int operator[](size_t index);  //returns a bit from spcipic index location.
   // Package operator= (Package& p);
    

    string package;
    size_t strength;
    size_t packLength;
    
    void setPackage(string Package);
    void setStrength(size_t Strength);
    void setPackageLength(size_t packLen);
    string getPackage();
    size_t getPackageStrength();
    size_t getPackageLength();
    void updatePackage(string otherPackage); //update packages
    void displayPackage();
    
     friend ostream& operator<<(ostream& o ,Package B );
};

   ostream& operator<<(ostream& o ,Package B );

#endif /* defined(__CyberWarfare_Ex3__Package__) */
