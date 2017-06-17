//
//  GenericSort.h
//  GenricLinkedList
//
//  Created by Yoel Lev on 1/4/15.
//  Copyright (c) 2015 Yoel Lev. All rights reserved.
//

#ifndef __GenricLinkedList__GenericSort__
#define __GenricLinkedList__GenericSort__

#include <iostream>

//Template Sort Function
template <class T > void Sort(T& a , int size ) {
    
    for (int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size; j++) {
            
            if (a[j] > a[j+1] ) {
                swap(a[j], a[j+1]);
            }
        }
        
    }
}


//template swap function
template <class T>void swap(T& a , T& b ) {
    
    T temp = a;
    a=b;
    b=temp;
}



#endif /* defined(__GenricLinkedList__GenericSort__) */
