//
//  extensions.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 5.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "extensions.hpp"
#include <vector>
#include <string>
#include "utils.hpp"

using namespace std;

void test_extensions() {
    vector<int> vec {1,2,3};
    cout << vec << endl;
    
    int& first = vec[0];
    int& second = vec[1];
    swap(first, second);
    cout << first << second << endl;
    
    cout << "Baris Deniz" << endl;
    
    int nums[] {1,2,3};
    cout << nums << endl;
    utils::print(cout, nums);
    
    char letters[] = "The Office";
    cout << letters << endl;
    
    string best_boss = "Michael Scott";
    cout << best_boss << endl;
    
}
