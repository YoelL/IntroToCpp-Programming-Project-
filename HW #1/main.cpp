//
//  main.cpp
//  CalculatorPro
//
//  Created by Yoel Lev on 11/13/14.
//  Copyright (c) 2014 Yoel Lev. All rights reserved.
//

// In each Header you will find a brief explenation of the Class perpuse.
//functions that are highlited in * are used for debuging purpeses Only, and are not part of the Ex.
// Logic of this Ex as folows
// The Main calls to an Instance of Calculator which lunches the Menu, an instance of DB is created, and it initiate the DataBase, all of the arithmatic function are located in the DB.h , it seems that i have a problem with the power func and i didnt got it to work properly.



#include "MyImports.h"
#include "DataBase.h"

int main(int argc, const char * argv[]) {
    
   
    Calculator newCal ;
    newCal.runCalculator();
    return 0;
}
