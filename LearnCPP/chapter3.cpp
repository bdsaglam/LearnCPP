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
#include "utils.hpp"

using namespace std;

namespace chapter3 {

template<typename T>
void print_vector(const vector<T>& vec) {
    for(auto& elem: vec) {
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
    
    {// get a reference to a character in string by indexing
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
    while (cin >> word && word != "q") // read until end-of-file or q
        cout << word << endl; // write each word followed by a new line
    
    string line;
    // read input a line at a time until end-of-file
    // it does not omit whitespaces
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
        cout << endl << "## Filling a vector after initialization" << endl;
        
        vector<int> evens;
        for(int i = 0; i < 100; ++++i) {
            evens.push_back(i);
        }
        print_vector(evens);
    }
    
    {// iteration by reference
        cout << endl << "## Iterating vectors with element references" << endl;
        
        vector<int> digits{0,1,2,3,4,5,6,7,8,9};
        for (int& d: digits) {
            d *= d;
        }
        print_vector(digits);
    }
    
    {// vector comparison works lexicographically
        cout << endl << "## Comparising vectors" << endl;
        
        vector<int> u{0,1,2};
        vector<int> v{2,1,0};
        vector<int> t{0,0,9};
        
        cout << (u < v) << endl; // true
        cout << (t < u) << endl; // true
    }
    
    {// vector indexing
        cout << endl << "## Indexing vectors" << endl;
        
        vector<int> digits{0,1,2,3,4,5,6,7,8,9};
        cout << digits[0] << endl;
        cout << digits[-2] << endl; // no error but no negative indexing like Python
            
        // indexing gives references
        int& a = digits[0];
        int& b = digits[1];
        swap(a, b);
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
        string name = "swift";
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
    cout << '[';
    for (int i = 0; i != S-1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[S-1] << ']';
    cout << endl;
}

void test_array() {
    {// array initialization
        int empty[5];
        print_array(empty);
        
        int ones[10] {1}; //only first element is 1, the rest is 0
        print_array(ones);
        
        int nums[3] = {-1, 0, 1};
        print_array(nums);
        
        int digits[] = {0,1,2,3,4,5,6,7,8,9}; // size is implicity
        print_array(digits);
    }
    
    {// char arrays
        cout << endl << "## Char arrays" << endl;
        
        char lang[] = "C++"; // = {'C', '+', '+', '\0'}, null terminator added automatically
            print_array(lang);
            
        //  char name[5] = "Chris"; // error: no space for null terminator
    }
    
    {// no copy or assignment
        int a[] = {2,7,1};
//        a = {3,1,4}; // error
//        int b[] = a; // error
//        int b[](a); // error
    }
    
    {// pointers and references to arrays
        cout << endl << "## Pointers and References" << endl;
        
        int* ptrs[3]; // array of 3 pointers to int
//        int& refs[3] = ... // error: no array of references
        int* (&x)[3] = ptrs; // x is a reference to an array of pointers
        
        int arr[] = {1,2,3,4,5};
        int (*p_array)[5] = &arr; // a pointer to 5 element int array
        int (&ref_array)[5] = arr; // a reference to 5 element int array
        print_array(arr);
        cout << "pointer to array: " <<  *p_array << endl;
        print_array(ref_array);
    }
    
    {// array indexing
        cout << endl << "## Indexing" << endl;
        
        int x[] = {0,1,2,3,4};
        unsigned int j = 0;
        cout << x[j] << endl;
        int i = 1;
        x[i] = -1;
        cout << x[i] << endl;
        
//        cout << x[-2] << endl; // no negative indexing
        
        // out-of-bound index
        // since an array is just a pointer under the hood, it does not check index bounds
        // hence, we can read memory outside of the array
        // which is a serious security thread
        // so, it is important to check indices before reading or writing with them
        for (int i = 5; i != 10; ++i) {
            cout << x[i] << ' ';
        }
        cout << endl;
    }
    {// array indexing
        {
            // here first and second are just copies
            // so swapping them won't change array
            int arr[] {2,3,1};
            
            int first = arr[0];
            int second = arr[1];
            cout << first << ' ' << second << endl; // 2 3
            swap(first, second);
            cout << first << ' ' << second << endl; // 3 2
            utils::print(cout, arr); // 2,3,1
            cout << endl;
        }
        
        {
            // here first and second are pointers to array elements
            // hence, swapping them change array
            int arr[] {2,3,1};
            
            int* first = &arr[0];
            int* second = &arr[1];
            cout << *first << ' ' << *second << endl; // 2 3
            swap(*first, *second);
            cout << *first << ' ' << *second << endl; // 3 2
            utils::print(cout, arr); // 3 2 1
            cout << endl;
        }
    }
    
    {// array pointer
        cout << endl << "## Array pointer" << endl;
        
        int x[] = {0,1,2,3,4,5,6,7,8,9}; // x is an array of ten ints
        auto ptr(x); // ptr is an int* that points to the first element in x
        int* ptr2(&x[0]);
        cout << x << ' ' << ptr << ' ' << ptr2 << endl; // ptr==ptr2
        
        // we can also subscript a pointer as long as it points to an object
        // p[1] is same as *(p+1)
        int* p = &x[3];
        cout << p[-1] << ' ' << *p << ' ' << p[1] << endl;
        
        // we can use negative indexing as such
        int* pe = end(x);
        cout << pe[-1] << endl; // yields last element as in Python
    }
    
    {// iterating arrays with pointers
        cout << endl << "## Iterating arrays with pointers" << endl;
        
        int arr[] = {0,1,2,3,4,5,6,7,8,9};
        int* pbeg = &arr[0];
        int* pend = &arr[10];
        while (pbeg != pend) {
            cout << *pbeg << ' ';
            ++pbeg;
        }
        cout << endl;
        
        // or we can use built-in begin and end functions to get pointers
        char x[] = "C++ vs Swift";
        char* pe = end(x);
        for (auto p = begin(x); p != pe; ++p) {
            cout << *p;
        }
        cout << endl;
    }
    
    {// array comparison
        cout << endl << "## Array comparison" << endl;
        
        int a[] {1,2,3};
        int b[] {1,2,3};
        int c[] {0,-1,-2};
        cout << "a == b " << (a == b) << endl; // array comparison always evaluate to false
        
        // compares pointers
        cout << "c < a " << (c < a) << endl;
        cout << "c < b " << (c < b) << endl;
        cout << "a < b " << (a < b) << endl;
        cout << "a <= b " << (a <= b) << endl;
    }
    
    {// create vector from array
        cout << endl << "## Array to vector" << endl;
        
        int x[] {1,2,3};
        vector<int> vec(begin(x), end(x)); // copies elements of x to vector
        print_array(x);
        print_vector(vec);
        
        x[0] = -1; // changes only array, not vector
        print_array(x);
        print_vector(vec);
    }
    
    {// multidimensional arrays
        cout << endl << "## Multidimensional arrays" << endl;
        
        int x[3][4]; // a 3 element array whose elements are 4 element arrays
//        x[0] = {1,2,3,4};
        print_array(x[0]);
        print_array(x[1]);
        print_array(x[2]);
        
        int y[2][3] {
            {0,1,2},
            {3,4,5}
        };
        for (int r = 0; r != 2; ++r) {
            print_array(y[r]);
        }
        
        int z[2][3] {0,1,2,3,4,5};
        for (int r = 0; r != 2; ++r) {
            print_array(z[r]);
        }
        
        int (&row)[3] = z[0];
//        row = {-1, -2, -3}; // error: array cannot be copied or assigned
        row[0] = -1; // legal
        for (auto& row: z) {
            for (auto& col : row) {
                cout << col << ' ';
            }
            cout << endl;
        }
        
        auto pr = &z[1]; // type: int (*)[3]
        (*pr)[1] = 9;
        print_array(*pr);
        
        // remember
        int *p[4]; // array of pointers to int
        int (*q)[4]; // pointer to an array of four ints
        
        // type alias to simplify array pointers
        using row_type = int[3];
        row_type& row2 = y[1];
        row2[2] = -1;
        print_array(row2);
        
    }
    
    {// empty array
        int arr[0];
    
        int* ptr = &arr[0];
        cout << ptr << ' ' << *ptr << endl;
        cout << sizeof(arr) << endl;
        cout << sizeof(ptr) << endl;
    }
}

void test_cstrings() {
    // in C, strings are char arrays and they end with null terminator
    
    char s[] {'C', '+', '+'}; // no null terminator
//    cout << strlen(s) << endl; // gives wrong value, since s is not null terminated
    
    {// comparison
        const char ca1[] = "A string example";
        const char ca2[] = "A different string";
//        if (ca1 < ca2) // undefined: compares two unrelated addresses
    }
    
    {// concatenate two char arrays
        char name[] = "grace";
        cout << strlen(name) << endl; // 5
        char surname[] = "hopper";
//        strcat(name, surname); // error: not enough space in first to add characters
    
        char s1[12] = "von ";
        char s2[8] = "neumann";
        strcat(s1, s2); // concatenates second array to first and returns first
        cout << s1 << endl;
    }
    
    {// copy
        char s[5];
        char name[] = "geoff hinton";
        strcpy(s, name); // copy second into first and returns first
        cout << s << endl;
        
        char first[] = "Charles ";
        char second[] = "Charles Darwin";
        strcpy(first, second); //copies on first as in copy assignment
        cout << first << endl;
    }
    
    {// convert C++ string to C string
        string s = {"Hello C"};
        const char* cs = s.c_str(); // have to be const
        cout << cs << endl;
    }
    
}

}
