//
//  Matrix.h
//  CalculatorPro
//
//  Created by Yoel Lev on 11/13/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//
//this Class is the entity of a Complex  Matrix


#ifndef __CalculatorPro__Matrix__
#define __CalculatorPro__Matrix__

#include "MyImports.h"
using namespace std;

typedef complex<double> dcmplx;

class Matrix{
    
public:
    
    //C'tors
    Matrix();
    Matrix(unsigned size);
    
    //getters & Setters
    bool  setDim(unsigned size);
    int   getDim();
    bool  setMatrix();
    
    //Vars
    string matName ;
    unsigned dim ;
    dcmplx *matArray;
    
    
};



#endif /* defined(__CalculatorPro__Matrix__) */
