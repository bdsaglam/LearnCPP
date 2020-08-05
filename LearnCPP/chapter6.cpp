//
//  chapter6.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 4.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter6.hpp"
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include "extensions.hpp"

using namespace std;

namespace chapter6 {

// function parameters with default values
vector<int> to_base(int n, int base = 2) {
    vector<int> digits(32);
    int index = 31;
    while (n) {
        int d = n % base;
        digits[index] = d;
        n /= base;
        index--;
    }
    vector<int> slice(digits.begin() + index + 1, digits.end());
    return slice;
}

// function that takes a pointer and sets the pointed-to value to zero
// this pointer is the copy of the one passed
void reset(int* ip) {
    *ip = 0; // changes the value of the object to which ip points
    ip = 0; // changes only the local copy of ip; the argument is unchanged
}

int pop(vector<int>& vec) {
    int last = vec[vec.size() - 1];
    vec.pop_back();
    return last;
}

// Best practice: pass parameters as const references so that they are not copied and cannot be changed inside function.
// compare the length of two strings
bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

// standard library convention for passing arrays
// since we can only pass a pointer to array's first element to a function
// we need additional information about bounds of array
// we can either pass size of the array as another argument
// or we can pass begin and end pointers of array to the function as std
void print(int* beg, int* end){
    while (beg!=end) {
        cout << *beg << " ";
        ++beg;
    }
    cout << endl;
}

// variable number of arguments
void print(initializer_list<string> args, string sep = " "){
    for (const auto& s: args) {
        cout << s << sep;
    }
    cout << endl;
}

// Never Return a Reference or Pointer to a Local Object
// disaster: this function returns a reference to a local object
const string& manip() {
    string ret;
    // transformretinsomeway
    if (!ret.empty())
        return ret; // WRONG: returning a reference to a local object!
    else
        return "Empty";// WRONG:"Empty"isalocaltemporarystring
}

// we can return a reference to a non-local object
// we can assign to the result of a function that returns a reference to nonconst
char& find(string& s, char c){
    for (int i = 0; i != s.size(); ++i) {
        if (s[i]==c) return s[i];
    }
    
    return s[s.size()];
}

// list initialization of return value
vector<int> odd_digits(){
    return {1,3,5,7,9};
}

// return a pointer to array
using IAP = int[3];
IAP* square(IAP* parr) {
    int* pb = begin(*parr);
    int* pe = end(*parr);
    while (pb!=pe) {
        (*pb) = (*pb) * (*pb);
        ++pb;
    }
    return parr;
}

// or with new arrow syntax for return type
auto square2(int (*parr)[3]) -> int(*)[3]{
    int* pb = begin(*parr);
    int* pe = end(*parr);
    while (pb!=pe) {
        (*pb) = (*pb) * (*pb);
        ++pb;
    }
    return parr;
}

// function pointers
using comparator = bool (const int&, const int&);

bool smaller_than(const int& first, const int& second) {
    return first < second;
}

bool greater_then(const int& first, const int& second){
    return first > second;
}

// function parameters automatically passed by pointer
// so no need for explicitly stating that
void sort_by(vector<int>& vec, comparator f = smaller_than){
    for (int i = 1; i != vec.size(); ++i) {
        int k = i;
        for (int j = i-1; j != -1; --j) {
            if (f(vec[k], vec[j])) {
                swap(vec[k], vec[j]);
                --k;
            } else {
                break;
            }
        }
    }
}

//
void test_functions() {
    {// default parameters
        int n = 12;
        auto bits = to_base(n);
        auto octits = to_base(n, 8);
    }
    
    {// pass by reference
        vector<int> nums {1,2,3,4};
        int last = pop(nums);
        assert(last==4);
        assert(nums.size()==3);
    }
    
    {// pass by pointer
        cout << "## Pass by pointer" << endl;
        
        int a = 1;
        int* p = &a;
        cout << "p: " << p << endl;
        cout << "*p: " << *p << endl;
        reset(p);
        cout << "p: " << p << endl;
        cout << "*p: " << *p << endl;
    }
    
    {// passing arrays as two pointers
        cout << "## Passing an array as two pointers" << endl;
        
        int nums[] {1,2,3,4};
        print(begin(nums), end(nums));
    }
    
    {// returning a reference
        string planet = "earth";
        find(planet, 'a') = 'A';
        cout << planet << endl;
    }
    
    {
        int arr[3] {1,2,3};
        int (*parr)[3] = &arr;
        auto pres = square(parr);
        print(begin(*pres), end(*pres));
    }
    
    {
        int arr[3] {1,2,3};
        int (*parr)[3] = &arr;
        auto pres = square2(parr);
        print(begin(*pres), end(*pres));
    }
    
    {// pointer-to-function
        vector<int> scores {1, 2, 0, -1, 4, 3, 4, 1, -2};
        sort_by(scores, greater_then);
        cout << scores << endl;
    }
}

}
