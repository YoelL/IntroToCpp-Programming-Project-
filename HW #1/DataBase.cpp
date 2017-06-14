//
//  DataBase.cpp
//  CalculatorPro
//
//  Created by Yoel Lev on 11/14/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "DataBase.h"
#include <string>
#include <sstream>
#include <iomanip>

DataBase:: DataBase(){
    
    
    
}


//initialize the database of matrices
bool DataBase:: initDB(){
    
    arrayLen = 10;
    addedMatrices =0;
    dbArray  = new Matrix[arrayLen];

    return true;
}

void DataBase:: initMatNames(){
    
    for (int i = 0 ; i < getDBSize(); i++ ) {
        dbArray[i].matName="EMPTY";
    }
    
}

//resizes the DB if needed in the background.
bool DataBase:: reSizeDB(){
    
    arrayLen *= 2;
    Matrix *newArr = new Matrix[arrayLen];
    
    memcpy( newArr, dbArray, arrayLen * sizeof(Matrix));
    
    dbArray = newArr ;
    
    delete [] newArr;
    
    return true;
}

//deletes the DB.
bool DataBase:: deleteDB(){
    
    delete [] dbArray ;

    return true;
}

//gets Db current size.
int  DataBase:: getDBSize(){
    
    return (int)arrayLen;
    
}

//display the whole content of the Db.
void DataBase:: displayAllMatInDB(){
    
    for (int i = 0 ; i < getDBSize(); i++) {
      
        //prints the matrix Name.
       cout<<"The Matrix: "<<dbArray[i].matName<<" is in Index-"<<i<<endl;
        
        //print  Complex Matrix.

        int n = dbArray[i].getDim();
        for (int row = 0 ; row < n*n ; row++) {
            if (row % n == 0) {
                cout<<endl;
            }
                cout<<dbArray[i].matArray[row].real() <<"+"<<dbArray[i].matArray[row].imag()<<"i ";
            }
        cout <<endl<<" End Of Matrix  " << i <<endl;
        }
        
    
}

void DataBase:: autoFillMatrix(){
    
    //Auto Matrix Fill
    
    //fills the matrix with complex number
    
    for (int indexAtPath = 0 ; indexAtPath < getDBSize(); indexAtPath++) {
        int d = dbArray[indexAtPath].getDim();
            
            //fills the matrix with complex number
            for (int fill = 0 ; fill < d*d; fill++) {
              
                dbArray[indexAtPath].matArray[fill].real(1.2);
                dbArray[indexAtPath].matArray[fill].imag(3.4);

                
            }
        
    }
 
}

//adds a matrix to the DB with users info.
bool DataBase:: addMatrixToDB(string mat, unsigned dim , string matName ){
   
    //in case DB is Full,it will be resized twice the current size.
    if ( arrayLen ==  addedMatrices) {
        reSizeDB();
    }
    
    
    //inserts the Matrix details,after being checked to DB
    for (int i = 0 ; i < getDBSize(); i++) {
        
        if ((dbArray[i].matName == "EMPTY") ) {
            dbArray[i].matName = matName;
            dbArray[i].setDim(dim);

            stringToDouble(mat,i);
            return  true;
            
        }
    }
    
    CalacMesseges calcMesg;
    calcMesg.errMessage("Matrix was Not added to DB");
    return false;
    
}

//converts the string format to double.
bool DataBase:: stringToDouble(string complexNumber ,int atIndex){
    
    string s = complexNumber;
    string newStr ;
    char temp;
    posInMat=0;
    
    unsigned long len = s.length();
    
    for (int i = 0; i < len ; i++) {
        
        if (s[i] == '(' ) {
            
            newStr = s.substr(i,len);
            stringstream CN(newStr);
            
            CN >> temp >> realNum >> temp >> imgNum;
           // cout << realNum <<"+" <<imgNum<<"i"<<endl;
            
            dbArray[atIndex].matArray[posInMat].real(realNum);
            dbArray[atIndex].matArray[posInMat].imag(imgNum);
            posInMat++;
        }
        
    }
    return true;
}

//removes a specific matrix from DB using its name.
bool DataBase:: removeMatrixFromDB(string matrixName, DataBase currentDB){
    
    
    for (int indexAtPath = 0 ; indexAtPath < currentDB.getDBSize(); indexAtPath++ ) {
        if (matrixName == currentDB.dbArray[indexAtPath].matName) {
            cout<<"The Matrix: "<<matrixName<<" Was Found."<<endl;
            
            //delete matrix
            currentDB.dbArray[indexAtPath].matName = "EMPTY";
            currentDB.dbArray[indexAtPath].dim = 0;
            delete [] currentDB.dbArray[indexAtPath].matArray;
            cout<<"Matrix: "<<matrixName<<" Was Deleted."<<endl;
            
            return true;
            
        }
 
    }
    cout<<matrixName<<" was not found in DB."<<endl;
    return false;

}

//searches for a matrix in the DB and returns its Index.
int  DataBase:: searchForMatrix(string matrixName,DataBase currentDB) {
    
    
    for (int indexAtPath = 0 ; indexAtPath < currentDB.getDBSize(); indexAtPath++ ) {
        if (matrixName == currentDB.dbArray[indexAtPath].matName) {
            return indexAtPath;
        }
    }
    return -1;
  
}

//converts String to a complex number.
dcmplx DataBase:: stringToComplex(string complexNumber){
    
    char temp;

            stringstream CN(complexNumber);
            CN >> temp >> realNum >> temp >> imgNum;

    complex.real(realNum);
    complex.imag(imgNum);
    
    return complex;
}

//duplicates a matrix from Db.
bool DataBase:: copyMatrix(int indexInDB ,DataBase currentDB ){
    
    
    
    //in case DB is Full,it will be resized twice the current size.
    if ( arrayLen ==  addedMatrices) {
        reSizeDB();
    }
    
    //finds an empty place to copy the matrix
    for (int i = 0 ; i < getDBSize(); i++) {
        
        if ((dbArray[i].matName == "EMPTY") ) {
            
            newIndex= emptyPlaceInDB = i;
            
            
            dbArray[emptyPlaceInDB].matName = dbArray[indexInDB].matName ;
    int d = dbArray[indexInDB].getDim();
            dbArray[emptyPlaceInDB].setDim(d);
            
            for (int fill =0 ; fill  < d*d ; fill++) {
                
                dbArray[emptyPlaceInDB].matArray[fill] = dbArray[indexInDB].matArray[fill];
                }
            
            addedMatrices++;
            return  true;
            }
        }
            return  false;
    }

//multyplies a matrix with a given sclar that its format is a complex number.
void DataBase:: multyByScalar(dcmplx a , dcmplx *b, int n ){
    
    unsigned dim = n;
    dcmplx c,d ;
    
    for (int i = 0 ; i < dim*dim ; i++) {
        b[i] = a* b[i];
        
    }
    
}

//Powers up a given matrix
void DataBase:: matrixPow(int power , int atIndex , DataBase DB  ){
    
   
    int dim = DB.dbArray[atIndex].getDim();
   dcmplx  *tempMat = new dcmplx[dim*dim];
 
    //copys wanted matrix
    
    for (int fill = 0 ; fill < dim*dim ; fill++) {
        
        tempMat[fill]= DB.dbArray[atIndex].matArray[fill];
    }
    
    //multyplays matrix by itself Power times.
  
    int times = 0;
    while (times < power-1) {
        
        tempMat =  MultiplyMatrix(dim, tempMat, tempMat);
        times++;
    }
    
    //insert the Powerd Matrix to db.
    for (int fill = 0 ; fill < dim*dim ; fill++) {
        
        DB.dbArray[atIndex].matArray[fill]=tempMat[fill];
    }
    
    cout<< tempMatName;
    DB.dbArray[atIndex].matName = tempMatName;
    
}

//calculats the Det of a matrix
dcmplx DataBase:: matrixDet( dcmplx *mat ,int dim ){
    
    dcmplx det,tempMat[1000];
    
   int p, h, k, i, j ;
    
    det.real(0.0);
    det.imag(0.0);
    
    
    if(dim == 1) {
        return  mat[0];
    } else if(dim == 2) {
        det =  (mat[0] * mat[3]) -(mat[1]*mat[2]);
        return det;
    }else {
        for(p = 0 ; p < dim ; p++) {
            h = 0 ;
            k = 0 ;
            
            for(i=1;i<dim;i++) {
                
                for( j=0 ;j<dim ;j++) {
                   
                    if(j == p) {
                        continue;
                    }
                    tempMat[h+k+2] = mat[i+j+2];
                    k++;
                    if( k == dim-1) {
                        h++;
                        k = 0;
                    }
                }
            }
            det+=mat[0+p] * pow(-1,p) * matrixDet(tempMat,dim-1);
        }
    }

   return det;
}

//display to screen a spcific matrix 
void DataBase:: displayMat(int atIndex ,DataBase currentDB ){
    
   
        
        //prints the matrix Name.
        cout<<dbArray[atIndex].matName<<" = [ "<<endl;
        
        //print  Complex Matrix.
        int n = dbArray[atIndex].getDim();
        
        for (int row = 0 ; row < n*n ; row++) {
            if (row % n == 0) {
                cout<<endl;
            }
            cout<<"("<<setprecision(4)<<dbArray[atIndex].matArray[row].real()<<","<<setprecision(4)<<dbArray[atIndex].matArray[row].imag()<<") ";
        }
  
    cout<<endl<<endl<<"]"<<endl;
}


dcmplx * DataBase:: MultiplyMatrix( int dim , dcmplx *mat1 ,dcmplx *mat2 ){
    
    dcmplx  *pro = new dcmplx[dim*dim];
    
    int i =0;
    for (int row = 0; row < dim; row++) {
        for (int col = 0; col < dim; col++) {
            for (int inner = 0; inner < dim; inner++) {
                pro[row+col] += mat1[row+inner] * mat2[inner+col];
            }
            dbArray[emptyPlaceInDB].matArray[i] =pro[row+col];
        }
       
    }
    
    return pro;
}

