//
//  main.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 31.07.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include <iostream>
#include "chapter1.cpp"

using namespace std;

double global_number;
string global_string;

int main(int argc, const char * argv[]) {
//    cout << global_number << endl; // 0
//    cout << global_string << endl; // ""
    
//    chapter1::initialization();
//    chapter1::scopes();
//    chapter1::references();
//    chapter1::pointers();
    chapter1::pointers_references();
    
    
    cout << endl;
    return 0;
}
