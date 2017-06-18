//
//  Linebacker.cpp
//  SimCyber-Ex4
//
//  Created by Yoel Lev on 1/9/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#include "Linebacker.h"

Linebacker::Linebacker(){
    
    
}


Linebacker::Linebacker( size_t vectorSize ){
    
    setLinebackerProbability(vectorSize);
    
}

void Linebacker:: setLinebackerProbability(size_t vectorSize){
    
    
   LinebackerProbability  = (1/vectorSize);
    
}