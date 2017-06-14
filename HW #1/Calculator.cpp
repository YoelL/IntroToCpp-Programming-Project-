//
//  Calculator.cpp
//  CalculatorPro
//
//  Created by Yoel Lev on 11/14/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "Calculator.h"
#include "DataBase.h"
#include "MyImports.h"


//runs the calculator, the whole menu reside in this function.
bool Calculator:: runCalculator(){
    
    
    DataBase *myDB = new DataBase();
    CalacMesseges calcMessges ;
    
    myDB->initDB();
    myDB->initMatNames();
    

    do {
        
      calcMessges.selectedOption= calcMessges.displayMenu();
        
        switch (calcMessges.selectedOption) {
            case 0:
                cout <<"Bye Bye"<<endl;
                
                //deallocates the memory that was allocated in the heap.
                
                //deletes all of matrices in DB array
                for (int i = 0 ; i < myDB->getDBSize() ; i++) {
                    
                    delete myDB->dbArray[i].matArray;
                }
                
                //delete DB array
                delete myDB ;
                
                break;
                
            case 1:
            {
                //adding a new matrix to the DB
                
                cout <<"Option [1]"<<endl;;
                if (matrixInput() == true && isValidMatrix(matNumbers) == true) {
                    
                    myDB->addMatrixToDB(matNumbers, matDim, matName);
                    myDB->addedMatrices++ ;
                    calcMessges.saveMessage();
                }
                
                break;
            }
                
            case 2:
            
                //Deletes a matrix
            
                cout<<"Please enter Matrix Name you wish to Delete."<<endl;
                cin>>matName;
                
                myDB->removeMatrixFromDB(matName, *myDB);
                
                break;
                
            case 3:
            {
                //Multiplie by a scalar
                cout<<"Please enter Matrix Name you wish to Multiplie by a scalar."<<endl;
                cin>>matName;
                
            int posInDB=myDB->searchForMatrix(matName, *myDB);
                
                if (posInDB != (-1)) {
                    
                   
                    cout <<"Please enter the Complex Scalar Number in this format:(Re,Im)"<<endl;
                    cin>>scalar;
                    
                    myDB->stringToComplex(scalar);
                    
                    //check if scalar is a valid number
                    if (isValidMatrix(scalar) ==false) {
                        break;
                    }
                    
                    cout<< "Please enter the Matrix Name you wish to save the result in :";
                    cin>>myDB->tempMatName;
                    
                    int MatrixToCopy = (myDB->searchForMatrix(myDB->tempMatName, *myDB));
                    
                    //if the user puts a matrix name that already exists it will overwrite it with the new result
                    if ( MatrixToCopy != (-1) ) {
                      
                        myDB->multyByScalar(myDB->complex ,myDB->dbArray[MatrixToCopy].matArray,myDB->dbArray[MatrixToCopy].getDim());

                    }else{
                      
                        myDB->copyMatrix(myDB->emptyPlaceInDB, *myDB);
                        
                        myDB->multyByScalar(myDB->complex ,myDB->dbArray[myDB->emptyPlaceInDB].matArray,myDB->dbArray[myDB->emptyPlaceInDB].getDim());
                        
                        myDB->dbArray[myDB->emptyPlaceInDB].matName =myDB->tempMatName;
                        cout<<"The New Scalar was saved."<<endl;
  
                    }
                }

                break;
            }
                
            case 4:
            {
                
                int power;
                cout<<"Please enter Matrix Name you wish to Power."<<endl;
                cin>>matName;
                
                cout<<"Please enter the Power, must be a Natural number!."<<endl;
                cin>>power;
                if (power < 0) {break;}
                
                cout<<"Please enter Matrix Name you wish to save the result in ."<<endl;
                cin>>tempName;
                
                if (matName == tempName) {
                    
                  int atIndex= myDB->searchForMatrix(matName, *myDB);
                
                    myDB->matrixPow(power,atIndex,*myDB);
                    
                }else{
                    
                 int atIndex = myDB->searchForMatrix(matName, *myDB);
                     myDB->copyMatrix(atIndex, *myDB);
                     myDB->matrixPow(power,myDB->newIndex,*myDB);
                }
                
                
                break;
            }
                case 5:
            {
                cout<<"Please Enter the name of the matrix you wish to Determinant"<<endl;
                cin>>tempName;
                
                int atIndex = myDB->searchForMatrix(tempName, *myDB);
                
                if ( atIndex != -1) {
                    
                 dcmplx result =  myDB->matrixDet(myDB->dbArray[atIndex].matArray,myDB->dbArray[atIndex].getDim());
                   cout<<"The Determinant value is : "<<result.real()<<" (+) "<< result.imag()<<"i"<<endl;
                }else{
                    
                    cout<<"No Matrix with the name : "<<tempName <<" exists"<<endl;
                }
                break;
            }
                
            case 6:
            {
                
                cout<<"Please Enter the name of the matrix you wish to Display"<<endl;
                cin>>tempName;
                cout<<endl;
                int atIndex = myDB->searchForMatrix(tempName, *myDB);
               
                if (atIndex != -1 ) {
                     myDB->displayMat(atIndex, *myDB);
                }
               
                
                break;
            }
           
            default:{
               
             
                myDB->matrixPow(2, 0, *myDB);
               
                break;
            }
                
        }
        
        
    } while (calcMessges.selectedOption );
    
    
    
    return true;
}

//gets user input for matrix name, dim, and complex number
bool Calculator:: matrixInput(){
    
    cout <<"Please enter Matrix name [A-Z] letters only"<<endl;
    cin >>matName;
    
    //Check If matName is correct.
    int strlength =(int)matName.length();
    
    if (strlength < 9 || strlength > 1 ) {
        
        for (int i = 0 ; i < strlength; i++) {
            
            if (!(isupper(matName[i])) ) {
                cout<< "You have entered a worng name"<<endl;
                return false;
            }
            
        }
    }
    
    
    cout <<"Please enter Matrix Dimension (up to 100 )"<<endl;
    cin >> matDim;
    
    //Checks if Matrix Dimension is correct.
    if (matDim > 101 || matDim < 1 ) {
        cout <<"The Dimension you have entered is not correct!"<<endl;
    }
    
    cout << "Matrix Ex->(1,0) (2,0)" <<endl;;
    string temp ="";
    
    std::cin.sync(); //clear buffer
    std::cin.get(); //wait
    
    for (int i = 0 ; i < matDim; i++) {
        cout <<"Please Enter Row number "<< i <<" of your Matrix"<<endl;
        std::getline(cin, matNumbers);
        
        //Check if matNumbers are correct!

        temp+=matNumbers;
        temp+=" ";
    }
    matNumbers=temp;
    
    if (isValidMatrix(matNumbers) == true) {
        return true;
    }else{
        return false;
    }
    
    
}

//checks if the matrix format is correct.
bool Calculator:: isValidMatrix( string matrix ){
    stringstream ss(matrix);
    
    double d1,d2;
    char openB,closeB,comma;
    
    ss >>openB>>d1>>comma>>d2>>closeB;
    
    
    if (openB != '(' || comma != ',' || closeB != ')' ){
        cout << " Incorrect matrix error"<<endl;
        return false;
    }
    return true;

}

//gets a sub string of the matrix input "(re,im)" and checks if it is valid.
bool Calculator:: getSubStr( string str ){
    
    string newStr ;
    string matrix = str ;
    
    for (int i = 0 ; i < matrix.length(); i++) {
        
        if (matrix[i] == ')') {
            i++;
            
            newStr = matrix.substr(0,i);
            //sends the sub string to isValidMatrix.
            if (isValidMatrix(newStr) == false) {
                return false;
            }else{
                
                matrix = matrix.substr(i,matrix.length());
                i=0;
            }
            
        }
        
    }
    
    return true;
}
