//
//  Linebacker.h
//  SimCyber-Ex4
//
//  Created by Yoel Lev on 1/9/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#ifndef __SimCyber_Ex4__Linebacker__
#define __SimCyber_Ex4__Linebacker__

#include <iostream>
#include "Package.h"

class Linebacker :public Package{
    
public:
    
    //default C'tor
    Linebacker();
    Linebacker( size_t vectorSize );
    
    void setLinebackerProbability(size_t vectorSize);
    float LinebackerProbability;
 
};

#endif /* defined(__SimCyber_Ex4__Linebacker__) */
