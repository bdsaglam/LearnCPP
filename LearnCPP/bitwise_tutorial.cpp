//
//  bitwise_tutorial.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 1.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "bitwise_tutorial.hpp"
#include <assert.h>
#include <limits>

using namespace std;

namespace bitwise_tutorial {

void testBitwise(){
    int imin = numeric_limits<int>::min();
    int imax = numeric_limits<int>::max();
    
    int imin2 = (1 << 31);
    int imax2 = imin2 - 1;
    
    assert(imin==imin2);
    assert(imax==imax2);
}


}
