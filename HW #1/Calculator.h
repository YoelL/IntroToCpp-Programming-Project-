//
//  Calculator.h
//  CalculatorPro
//
//  Created by Yoel Lev on 11/14/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//
// this class runs the calculator  from the main, and is also responsible to manipulate user input.


#ifndef __CalculatorPro__Calculator__
#define __CalculatorPro__Calculator__

#include "MyImports.h"
using namespace std;

class Calculator{
    
public:
    
    //runs the whole calaulator
   bool runCalculator();
    
    //gets user input
   bool matrixInput();
    
    //vhecks if the matrix input is correct
   bool  isValidMatrix( string matrix );
    
  //  return a substring from a string.
   bool  getSubStr( string str );
    
    //Vars
    
    string matName;
    string matNumbers;
    string scalar;
    string tempName;
    unsigned matDim ;
 
};

#endif /* defined(__CalculatorPro__Calculator__) */
