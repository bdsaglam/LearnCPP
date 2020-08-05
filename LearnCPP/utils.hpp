//
//  utils.hpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 5.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>

namespace utils {

template<typename Iter>
std::ostream& write(std::ostream &strm,
                    Iter pbegin,
                    Iter pend,
                    const std::string& prefix="",
                    const std::string& sep=" ",
                    const std::string& suffix="") {
    
    if (pbegin == pend) return strm;
    
    strm << prefix;
    while(pbegin != (pend - 1)) {
        strm << *pbegin << sep;
        ++pbegin;
    }
    strm << *pbegin << suffix;
    return strm;
}

template<typename T>
std::ostream& write(std::ostream& strm,
                    std::initializer_list<T> args,
                    const std::string& prefix="",
                    const std::string& sep=" ",
                    const std::string& suffix="") {
    
    return write(strm, args.begin(), args.end(), prefix, sep, suffix);
}

template<typename T, std::size_t S>
std::ostream& write(std::ostream &strm,
                    T (&arr)[S],
                    const std::string& prefix="",
                    const std::string& sep=" ",
                    const std::string& suffix="") {
    
    return write(strm, std::begin(arr), std::end(arr), prefix, sep, suffix);
}

}

#endif /* utils_hpp */
