//
//  main.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 31.07.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include <iostream>
#include <vector>

#include "extensions.hpp"
#include "utils.hpp"
#include "chapter1.hpp"
#include "chapter2.hpp"
#include "chapter3.hpp"
#include "chapter4.hpp"
#include "chapter6.hpp"
#include "bitwise_tutorial.hpp"

using namespace std;
    
double global_number;
string global_string;

int main(int argc, const char * argv[]) {
//    cout << global_number << endl; // 0
//    cout << global_string << endl; // ""
//    cerr << "I just wanted to write to stderr" << endl;
    
//    bitwise_tutorial::testBitwise();
    
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
//    chapter3::test_array();
//    chapter3::test_cstrings();
    
//    chapter4::test_precedence();
//    chapter4::test_casting();
    
//    chapter6::test_functions();
    
    vector<int> vec {1,2,3};
    cout << vec << endl;
    
    cout << "Baris Deniz" << endl;
    
    int nums[] {1,2,3};
    cout << nums << endl;
    utils::write(cout, nums);
    
    char letters[] = "The Office";
    cout << letters << endl;
    
    string best_boss = "Michael Scott";
    cout << best_boss << endl;
    
    
//    int& a = vec[0];
//    int& b = vec[1];
//    swap(a, b);

//    int x = 1;
//    utils::print(x);
    
//    utils::print({1,2,3,4});
    
    
    cout << endl;
    return 0;
}
