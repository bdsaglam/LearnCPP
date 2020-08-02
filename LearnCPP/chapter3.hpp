//
//  chapter3.hpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 1.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#ifndef chapter3_hpp
#define chapter3_hpp

#include <stdio.h>
#include <vector>

namespace chapter3 {

template<typename T>
void print_vector(const std::vector<T>&);

template<typename T>
bool binary_search(const std::vector<T>&, const T&);

template <typename C, typename E>
bool binary_search(const C&, const E&);

void test_string();
void test_iostream();
void test_vector();
void test_iterators();

template <typename T, std::size_t S>
void print_array(T arr[S]);

void test_array();

}

#endif /* chapter3_hpp */
