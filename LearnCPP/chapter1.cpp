//
//  chapter1.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 31.07.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

namespace chapter1 {

inline void initialization() {
    // multiple init in one line
    // x, y, z are int
    // y is initialized to a undefined value;
    int x = 1, y, z = 2;
    cout << x << y << z << endl;
    
    // auto conversion
    int pi = 3.14; // becomes 3
    cout << pi << endl;
    
    // list initialization do not auto convert
//    int ee {2.71}; // error
    int p {1}, q = {2};
    cout << p << q << endl;
    
    // paranthesis initialization, auto converts
    int a(1.1), b = (3.2);
    cout << a << b << endl;
    
    // default initialization
    // outside of function body, a variable is initialized to its default value
    // in function body, a variable of built-in type is uninitialized when not initialized
    // so it's value is undefine
    int c;
    bool d;
    double f;
    char g;
    string h;
    cout << c << ',' << d << ','<< f << ','<< g << ','<< h << endl;
    // output; some int, some bool, some double, '', ""
    
}

inline int reused = 42; // reused has global scope
inline void scopes() {
    int unique = 0; // unique has block scope
    std::cout << reused << " " << unique << std::endl; // 42 0
    
    int reused = 24; // hides outer scope reused
    std::cout << reused << " " << unique << std::endl; // 24 0
}

inline void references(){
    // a reference is just another name for the variable
    int x = 1;
    int& x_ref = x;
    cout << x << x_ref << endl; // 11
    
    // when we change x_ref, x changes as well
    x_ref = 2;
    cout << x << x_ref << endl; // 22
    
    // references must be initialized with an object
//    int& ref; // error
//    int& ref2 = 10; // error: initializer must be an object
    
    // when a reference is assigned to another variable
    // its value is copied, not itself
    // therefore, in below, original x does not change
    int y = x_ref;
    y = 3;
    cout << x << y << endl; // 23
    
    // once a reference is created, it cannot refer another object
    int a = 13;
    int b = 14;
    int& ref = a;
    ref = b; // it does not refer b, it just assigns value of b to a
    cout << "ref:" << ref << " a:" << a << " b:" << b << endl;
    
}

inline void pointers(){
    // a pointer is an object that provides indirect access to another object
    int x = 1;
    int* p = &x; // here & is adress operator
    int* q = p;
    cout << "x:" << x << " p:" << p << " q:" << q << endl;
    
    // dereferencing: we can access the object a pointer pointing by
    int y = *p; // here * is dereferencing operator
    int& z = *p; // create a reference to the object p pointing
    cout << "x:" << z << endl;
    cout << "y:" << y << endl;
    cout << "z:" << z << endl;
    
    // change the value object a pointer pointing
    *p = 2;
    cout << "x:" << z << endl;
    
    // nullptr is the global pointer which points nowhere
    // derefencing nullptr results in error
    int* np = nullptr;
    cout << "nullptr: " << np << endl;
//    cout << *np << endl; // error
    
    // pointer does not change when value of object changes
    int a = 2;
    int* pa = &a;
    int& b = *pa;
    cout << "a:" << a << " b:" << b << " pa:" << pa << endl;
    b = 3;
    cout << "a:" << a << " b:" << b << " pa:" << pa << endl;
    
    // unlike a reference, we can mutate a pointer
    int c = 4;
    int* pc = &c;
    cout <<  "*pc:" << *pc << " pc:" << pc << endl;
    int d = 5;
    pc = &d;
    cout <<  "*pc:" << *pc << " pc:" << pc << endl;
    
    // an uninitialized pointer points to an arbitrary address in memory
    // hence, its behavior is undefined and dangerous
    int* up;
    cout <<  "*up:" << *up << " up:" << up << endl;
    
    // any non-zero pointer evaluates to true
    int n = 0;
    int* pn = &n;
    if (pn) {
        cout << "if true" << endl;
        cout << "n: " << n << " pn: " << pn << endl;
    }
    int* zp = 0; // or zp = nullptr
    if (zp) {
        cout << "never reaches here" << endl;
    }
}

inline void pointers_references(){
    // a pointer may point to another pointer
    int a = 1;
    int* p = &a;
    int** pp = &p;
    cout << "a:" << a << " p:" << p << " pp:" << pp << endl;
    
    // a reference is not object, so it cannot be pointed
    int b = 2;
    int& ref = b;
//    int&* q = &ref; // error
    
    // but a reference may refer to a pointer
    int c = 3;
    int* pc = &c;
    int*& refp = pc;
    // read compound type from right to left, a reference to a pointer
    
    cout << "c:" << c << " pc:" << pc << " refp:" << refp << endl;
    if(pc==refp){
        cout << "pc==refp" << endl;
    }
}


}








