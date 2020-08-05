//
//  chapter4.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 4.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter4.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace chapter4 {

void test_precedence() {
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
        cout << "## Assignment" << endl;
        int x = 1; // this is initialization, not assignment
        
        // in C++, assignment returns the assigned object
        int y;
        int a = (y = 3); // a becomes y
        cout << "a: " << a << endl;
        
        // assignment is right associative
        int ival, jval;
        ival = jval = 0; // ok: each assigned 0
        
        // assignment has low precedence
        int i = 0;
        while (i = 3 < 4) {
            // first evaluate 3 < 4, which is true, i.e. 1
            // then, assign it to i
            // last, test i, which is 1
            cout << "i: "<< i << endl;
            break;
        }
        
        int j = 0;
        while ((j = 3) < 4) { // j = 3
            cout << "j: " << j << endl;
                break;
        }
    }
    
    {// increment and decrement operators, ++ and --
        int i = 0;
        int j;
        j = ++i; // i = i + 1; j = i;
        j = i++; // j = i; i = i + 1
        
        // Prefer prefix increment/decrement operators if both prefix and postfix would do the job
        // because the program does not need to store unincremented value with prefix.
        
        // prefix increment precedes dereference operator
        // whereas postfix does not
        int arr[] = {1,2,3};
        int* p = arr;
        
        cout << *p << endl; // 1
        cout << *p++ << endl; // 1
        cout << *p << endl; // 2
        cout << *++p << endl; // 3
        
        string s= "bjarne";
        auto beg = s.begin();
        // the behavior of the following loop is undefined! since it changes the pointer in right handside of the expression
        while (beg != s.end() && !isspace(*beg)) {
            *beg = toupper(*beg++); // warning: this assignment is undefined
//            *beg = toupper(*beg); // execution if left-hand side is evaluated first
//            *(beg + 1) = toupper(*beg); // execution if right-hand side is evaluated first
        }
        cout << s << endl;
    }
    
    {// bitwise shift operators are left associative
        cout << endl << "## Bitwise shift operators" << endl;
        
        cout << "a" << "b" << endl; // is same as
        ((cout << "a") << "b") << endl;
        
        cout << 42 + 10 << endl; // ok: + has higher precedence, so the sum is printed
        cout << (10 < 42) << endl; // ok: parentheses force intended grouping; prints 1
//        cout << 10 < 42 << endl; // error: attempt to compare cout to 42!
    }
    
    {// sizeof operator returns the size in bytes
        cout << endl << "## sizeof operator" << endl;
        
        int i = 0;
        cout << (sizeof i) << endl;
        cout << (sizeof (int)) << endl;
        // sizeof a dereferenced pointer returns the size of an object of the type to which the pointer points; the pointer need not be valid.
        int arr[] = {1,2,3};
        int* p = &arr[3]; // invalid pointer
        cout << (sizeof *p) << endl;
        
        // sizeof an array is the size of the entire array.
        cout << (sizeof arr) << endl;
        
        // including null terminator there are 6 elements in following char array
        char carr[] = "salsa";
        cout << "size of char [6]:" << (sizeof carr) << ' ' << endl; // 6
        cout << "size of literal \"salsa\": " << (sizeof "salsa") << endl; // 6
        
        // sizeof a string or a vector returns only the size of the fixed part of these types; it does not return the size used by the object’s elements.
        string s = "salsa";
        string s2 = "bachata sensual";
        cout << "size of 5-letter string: " << (sizeof s) << endl; // 24
        cout << "size of 15-letter string: " << (sizeof s2) << endl; // 24
    }
    
}

void test_casting() {
    {// static casting
        int i = 4;
        int j = 3;
        double k = i/j;
        cout << k << endl; // 1, not 1.333
        
        double fk = static_cast<double>(i) / j;
        cout << fk << endl; // 1.333
    }
    
    {// reinterpret casting
        int a = 65;
        int* ptr = &a;
        char* cptr = reinterpret_cast<char*>(ptr);
        cout << *ptr << endl;
        cout << *cptr << endl; // A
    }
    
    {// const casting
            int a = 1;
            const int* p = &a; // a pointer to const
    //        *p = 2; // error: we cannot change a with p, eventhough a is not const
            // to do that, we removed `constness` in p
            int* q = const_cast<int*>(p); // now, we can change a with q since a is not const
            *q = 2;
            cout << a << endl; // 2
        }
    
    {// old-style casting
        // static casting
        double pi = 3.14;
        cout << ( (int) pi) << endl;
        
        // reinterpret casting
        int a = 65;
        int* p = &a;
        char* q = (char*) p;
        cout << *p << ' ' << *q << endl;
        
        // const casting
        int i = 1;
        const int* ptrc = &i;
        int* ptr = (int*)(ptrc);
        *ptr = 2;
        cout << i << endl; // 2
    }
    
    
}



}
