//
//  main.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 31.07.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include <iostream>

#include "chapter1.cpp"
#include "chapter2.hpp"
#include "chapter3.hpp"
#include "bitwise_tutorial.hpp"

using namespace std;

double global_number;
string global_string;

int main(int argc, const char * argv[]) {
//    cout << global_number << endl; // 0
//    cout << global_string << endl; // ""
//    cerr << "I just wanted to write to stderr" << endl;
    
//    chapter1::initialization();
//    chapter1::scopes();
//    chapter1::references();
//    chapter1::pointers();
//    chapter1::pointers_references();
//    chapter1::const_qualifier();
//    chapter1::type_alias();
    
//    chapter2::testCount();
//    chapter2::testToBinary();
    
//    chapter3::test_string();
//    chapter3::test_iostream();

//    chapter3::test_vector();
//    chapter3::test_iterators();
    chapter3::test_array();
    
//    bitwise_tutorial::testBitwise();
    
    cout << endl;
    return 0;
}
