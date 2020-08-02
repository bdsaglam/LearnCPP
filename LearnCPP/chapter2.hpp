//
//  chapter2.hpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 1.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#ifndef chapter2_hpp
#define chapter2_hpp

#include <stdio.h>
#include <vector>

namespace chapter2 {

int count(const std::vector<int>&, int);
void testCount();

std::vector<int> toBinary(const std::vector<int>&);
void testToBinary();


}

#endif /* chapter2_hpp */
