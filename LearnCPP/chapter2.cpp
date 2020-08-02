//
//  chapter2.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 1.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter2.hpp"
#include <iostream>
#include <assert.h>
#include <vector>
#include <list>

using namespace std;

namespace chapter2 {

int count(const vector<int>& v, int value) {
    int c = 0;
    for (int elem : v) {
        if (elem==value) c++;
    }
    return c;
}

vector<int> toBinary(int n) {
    vector<int> bits(64);
    int index = 63;
    while (n) {
        int bit = n % 2;
        bits[index] = bit;
        n /= 2;
        index--;
    }
    vector<int> slice(bits.begin() + index + 1, bits.end());
    return slice;
}

void testCount(){
    vector<int> v = {1,2,3,4,5,6,7,1,2,3};
    int elem = 1;
    int expected = 2;
    
    int actual = count(v, 1);
    assert(actual==expected);
    cout << "There are " << actual << ' ' << elem << " in v" << endl;
}

void testToBinary(){
    int n = 11;
    vector<int> expected = {1, 0, 1, 1};
    
    vector<int> actual = toBinary(n);
    assert(actual==expected);
    for (auto d: actual) {
        cout << d;
    }
    cout << endl;
}

}
