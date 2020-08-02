//
//  chapter3.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 1.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter3.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace chapter3 {

template<typename T>
void print_vector(const vector<T>& vec) {
    for(auto elem: vec) {
        cout << elem << ' ';
    }
    cout << endl;
}

template <typename T>
bool binary_search(const vector<T>& vec, const T& target) {
    auto low = vec.begin();
    auto high = vec.end();
    
    while (low < high) {
        auto mid = low + (high - low) / 2;
        auto val = *mid;
        if (val == target){
            return true;
        }
        if (val < target){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return false;
}

template <typename C, typename E>
bool binary_search(const C& vec, const E& target) {
    auto low = vec.begin();
    auto high = vec.end();
    
    while (low < high) {
        auto mid = low + (high - low) / 2;
        auto val = *mid;
        if (val == target){
            return true;
        }
        if (val < target){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return false;
}

void test_string(){
    // repeat the char n time
    string s1(3, 'w'); // www
    string s2 = string(2, 'p'); // pp
    string s3(s1); // copy of s1
    string s4 = s1; // copy of s1
    
    // concatenate two string
    string title = "A tour of C++";
    string author = "Bjarne Strastroup";
    string message = title +", " + author;
    cout << message << endl;
        
    // string literals are char arrays, so we cannot concatenate them
//    string fullname = "Albert" + " Einstein"; // error
    
    // change a char in string
    string country = "turkey";
    country[5] = 'i';
    cout << country << endl;
    
    // length of string
    string word = "genius";
    string::size_type word_size = word.size();
    int word_len = word.size(); // implicit conversion
    cout << word_size << ' ' << word_len << endl;
    
    {// change characters of a string
        string s("Hello World!!!");
        // convert s touppercase
        for (auto &c : s) // for every char in s (note: c is a reference)
            c = toupper(c); // c is a reference, so the assignment changes the char in
        cout << s << endl;
    }
    
    {// change a single character
        string s("hello world!");
        s[0] = toupper(s[0]);
        cout << s << endl;
    }
    
}

void test_iostream(){
    // read from standard input
    string name;
    cout << "Enter you name: " ;
    cin >> name;
    cout << endl;
    cout << "Your name is: " << name << endl;
       
    string word;
    while (cin >> word && word != "q") // read until end-of-file
        cout << word << endl; // write each word followed by a new line
    
    string line;
    // read input a line at a time until end-of-file
    while (getline(cin, line) && line != "q")
        cout << line << endl;
}

void test_vector() {
    {// initialization
        vector<int> v0 = {1,2,3};
        vector<int> v1{1,2,3};
        vector<int> v2(v1); // copy elements of v1 into v2
        vector<int> v3 = v1; // copy elements of v1 into v3
        
        vector<int> u(10, -1); // ten elements, each -1
        print_vector(u);
        cout << "there are " << u.size() << " elements." << endl;
    }
    
    {// fill vector after initialization
        vector<int> evens;
        for(int i = 0; i < 100; i += 2) {
            evens.push_back(i);
        }
        print_vector(evens);
    }
    
    {// iteration by reference
        vector<int> digits{0,1,2,3,4,5,6,7,8,9};
        for (int& d: digits){
            d *= d;
        }
        print_vector(digits);
    }
    
    {// vector comparison works lexicographically
        vector<int> u{0,1,2};
        vector<int> v{2,1,0};
        vector<int> t{0,0,9};
        
        cout << (u < v) << endl; // true
        cout << (t < u) << endl; // true
    }
    
}

void test_iterators() {
    {// iterator pointers
        string filename = "my precious documents";
        for (auto it = filename.begin(); it != filename.end(); ++it) {
            char& c = *it;
            if (isspace(c)) {
                c = '_';
            }
        }
        cout << filename << endl;
    }
    
    {// const iterator pointers give read-only access to elements
        // for const objects, we can only get const iterator pointers
        const string filename = "my precious documents";
        for (auto it = filename.begin(); it != filename.end(); ++it) {
            const char& c = *it;
            cout << c;
        }
        cout << endl;
        
        // for const or non-const objects, we can get const iterator pointers by explicitly specifying them
        string name = "deniz";
        for (auto it = name.cbegin(); it != name.cend(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
    
    {// ptr->member = (*ptr).member
        vector<string> cities{"ankara", "izmir", "berlin"};
        for (auto it = cities.cbegin(); it != cities.cend(); ++it) {
            cout << *it << ' ' << it->size() << endl;
        }
    }
    
    {// custom iteration step
        string name = "alan turing";
        for (auto it = name.begin(); it != (name.end() - 1); it += 2) {
            char& c = *it;
            c = toupper(c);
        }
        cout << name << endl;
    }
    
    {// arithmetic operations with iterator pointers
        vector<int> vec{1,3,6,7,8};
        cout << binary_search(vec, 3) << endl;
        cout << binary_search(vec, 4) << endl;
        
        vector<int> vec2{1,3,6,7};
        cout << binary_search(vec2, 1) << endl;
        cout << binary_search(vec2, 9) << endl;
        
        string s {"acdgpt"};
        cout << binary_search(s, 'a') << endl;
        cout << binary_search(s, 'p') << endl;
        cout << binary_search(s, 'e') << endl;
    }
}

template <typename T, size_t S>
void print_array(T (&arr)[S]) {
    for (int i = 0; i != S; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void test_array() {
    int empty[5];
    for (int i = 0; i != 5; ++i) {
        cout << empty[i] << ' ';
    }
    cout << endl;
    
    int digits[] = {0,1,2,3,4,5,6,7,8,9};
    print_array(digits);
}

}
