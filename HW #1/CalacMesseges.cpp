//
//  CalacMesseges.cpp
//  CalculatorPro
//
//  Created by Yoel Lev on 11/15/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

#include "CalacMesseges.h"

//displays the option menu on screen
int CalacMesseges:: displayMenu(){
    
    cout<<"            Welcome to ProAlgebraCalc"<<endl;
    cout<<" -------------------------------------------------------"<<endl;
    cout<<"- Press [0] To Quit at all time                          -"<< endl;
    cout<<"- Press [1] To Add new Matrix to Database                -"<<endl;
    cout<<"- Press [2] To Delete Matrix from Databse                -"<<endl;
    cout<<"- Press [3] To Scalar product of a Matrix                -"<<endl;
    cout<<"- Press [4] For Calculating a Matrix to the power        -"<<endl;
    cout<<"- Press [5] For Calculating the determinants of a matrix -"<<endl;
    cout<<"- Press [6] To Display Current Matrix                    -"<<endl;
    cout<<" -------------------------------------------------------"<<endl;
    cout<< "Please Enter Your Choise : ";
    cin>>selectedOption;
    
    return selectedOption;
}

//output an error msg on screen
void CalacMesseges:: errMessage(string errMsg){
    
    cout << errMsg<<endl;
 
}

//output on screen that the matrix was added to th Db.
void CalacMesseges:: saveMessage(){
    
    cout << "Matrix was added succusfuly to DB."<<endl;
    
    
}
