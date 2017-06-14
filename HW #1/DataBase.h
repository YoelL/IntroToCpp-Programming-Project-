//
//  DataBase.h
//  CalculatorPro
//
//  Created by Yoel Lev on 11/14/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//



//this Class is responsible to manage the Whole DB of the matrices that are created by the user.
//




#ifndef __CalculatorPro__DataBase__
#define __CalculatorPro__DataBase__

#include "MyImports.h"

class DataBase {
    
public:
    
    DataBase();
    
    //initialize the database of matrices
    bool initDB();
   
    // *for dubging purpos Only!
    void initMatNames();
    
    //resizes the DB if needed in the background.
    bool reSizeDB();
    
    //deletes all of DB.
    bool deleteDB();
    
    //gets Db current size.
    int getDBSize();
    
    //*display the whole content of the Db.
    void displayAllMatInDB();
    
    //*
    void autoFillMatrix();
    
    //adds a matrix to the DB with users info.
    bool addMatrixToDB(string mat, unsigned dim , string matName );
    
    //converts the string format to double.
    bool stringToDouble(string complexNumber, int atIndex);
    
    //removes a specific matrix from DB using its name.
    bool removeMatrixFromDB(string matrixName,DataBase currentDB) ;
    
    //searches for a matrix in the DB and returns its Index.
    int  searchForMatrix(string matrixName,DataBase currentDB);
    
    //converts String to a complex number.
    dcmplx stringToComplex(string complexNumber);
    
    //duplicates a matrix from Db.
    bool copyMatrix(int indexInDB ,DataBase currentDB);
    
    //multyplies a matrix with a given sclar that its format is a complex number.
    void  multyByScalar(dcmplx a , dcmplx *b, int n);
   
    //Powers up a given matrix
    void  matrixPow(int power , int atIndex , DataBase DB );
   
    //calculats the Det of a matrix
    dcmplx matrixDet( dcmplx *mat ,int dim );
    
    //display to screen a spcific matrix
    void  displayMat(int atIndex ,DataBase currentDB );
    
    //Multyplies betwen 2 matrices
    dcmplx*  MultiplyMatrix( int dim , dcmplx *mat1 ,dcmplx *mat2);

    
    //Public Vars
    
    Matrix *dbArray ;
    double *tempArray;
    double realNum ,imgNum;
    int addedMatrices ;
    dcmplx complex ;
    int matToScalar;
    string tempMatName;
    int emptyPlaceInDB;
    int newIndex ;
    
    
    //Pivate Vars
private:
    
    size_t arrayLen ;
    int posInMat;
 
};



#endif /* defined(__CalculatorPro__DataBase__) */
