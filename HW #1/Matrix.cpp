//
//  Matrix.cpp
//  CalculatorPro
//
//  Created by Yoel Lev on 11/13/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Matrix.h"
//Default C'tor
Matrix::Matrix(){
    
}

//C'tor
Matrix :: Matrix(unsigned size){
    
    setDim(size);
}

//sets the matrix dim and allocs the apropriate size.
bool Matrix :: setDim(unsigned size){
    
    dim = size;
    setMatrix();
    return true;
}

//allocs the apropriate size of the matrix
bool Matrix:: setMatrix(){
    
    dim = getDim();
    matArray = new dcmplx [dim*dim];
    return true;
    
}

//getter
int Matrix:: getDim(){
    
    return dim;
}
