//
//  sorting.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 5.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "sorting.hpp"
#include "assert.h"
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& vec) {
    for (int i = 1; i != vec.size(); ++i) {
        int k = i;
        for (int j = i-1; j != -1; --j) {
            if (vec[k] < vec[j]) {
                swap(vec[k], vec[j]);
                --k;
            } else {
                break;
            }
        }
    }
}

void insertion_sort2(vector<int>& vec) {
    for (int i = 1; i != vec.size(); ++i) {
        int* ptr = &vec[i];
        for (int j = i-1; j != -1; --j) {
            int* ptr2 = &vec[j];
            if (*ptr < *ptr2) {
                swap(*ptr, *ptr2);
                ptr = ptr2;
            } else {
                break;
            }
        }
    }
}

void test_insertion_sort() {
    {
        vector<int> scores {1, 2, 0, -1, 4, 3, 4, 1, -2};
        insertion_sort(scores);
        assert(is_sorted(scores.begin(), scores.end()));
    }
    {
        vector<int> scores {1, 2, 0, -1, 4, 3, 4, 1, -2};
        insertion_sort2(scores);
        assert(is_sorted(scores.begin(), scores.end()));
    }
}

