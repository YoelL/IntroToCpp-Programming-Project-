//
//  CalacMesseges.h
//  CalculatorPro
//
//  Created by Yoel Lev on 11/15/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//
// this calss displays general messges on screen


#ifndef __CalculatorPro__CalacMesseges__
#define __CalculatorPro__CalacMesseges__

#include <iostream>
using namespace std;

class CalacMesseges{
    
public:
    
    //Functions.
    int  displayMenu();
    
    void errMessage( string errMsg ="There was an error" );
    void  saveMessage() ;
    
    //Public Var.
    int selectedOption;
    
  
    
};

#endif /* defined(__CalculatorPro__CalacMesseges__) */
