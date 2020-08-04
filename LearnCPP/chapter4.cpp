//
//  chapter4.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 4.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter4.hpp"
#include <iostream>

using namespace std;

namespace chapter4 {

void test_precedence() {
    { // increment precedes dereference operator
        int arr[] = {1,2,3};
        int* p = arr;
        
        cout << *++p << endl; // 2
    }
    
    {
        int* p;
//        decltype(*p) == int&
//        decltype(&p) == int**
    }
    
    // we don't know the order of evaluation for expressions that have same precedence
    int i = 0;
    cout << i << " " << ++i << endl; // undefined behavior
    
    {// comparison operators
        // unlike Python chain of comparison operators are not supported in C++
        int i = 1, j = 3, k=2;
        if (i < j < k) {
            // it first computes i < j which yields 1 and then checks 1 < k, which is true
            
            cout << "This is printed since k > 0" << endl;
        }
        
        if (i < j && j < k) {
            cout << "This is not printed as expected" << endl;
        }
    }
    
    {// assignment operator =
        int a = 1; // this is initialization, not assignment
        
        // assignment is right associative
        int ival, jval;
        ival = jval = 0; // ok: each assigned 0
        
        // assignment has low precedence
        int i = 0;
        while (i = 3 < 4) { // i = 1
            cout << "i: "<< i << endl;
            break;
        }
        
        int j = 0;
        while ((j = 3) < 4) { // j = 3
            cout << "j: " << j << endl;
                break;
        }
        
    }
}



}
