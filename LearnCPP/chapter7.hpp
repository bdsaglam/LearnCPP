//
//  chapter7.hpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 6.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#ifndef chapter7_hpp
#define chapter7_hpp

#include <stdio.h>
#include <string>

namespace chapter7 {

// we declare the class in header file and implement members in cpp file

// The only difference between using class and using struct to define a class is the default access level.
// for struct, default access level is public
// for class, default access level is private
// functions defined class are implicity defined inline
class Sale {
public:
    // constructors
    Sale();
    explicit Sale(const std::string& s); // explicit keyword disables auto conversion of string to Sale type
    Sale(const std::string& s, int n, double p); // no need for explicit keyword since auto conversion only applies single argument constructors
    explicit Sale(std::istream&);
    
    // members
    inline std::string isbn() const;
    inline Sale& combine(const Sale&);
    inline double avg_price() const;
    
private:
    // private data
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;

public:
    // friend declarations for nonmember Sale operations added
    friend Sale add(const Sale&, const Sale&);
    friend std::istream& parse(std::istream&, Sale&);
    friend std::ostream& print(std::ostream&, const Sale&);

};

// non-member Sale interface functions
Sale add(const Sale&, const Sale&);
std::ostream &print(std::ostream&, const Sale&);
std::istream &parse(std::istream&, Sale&);

// tests
void test_structs();
void test_sale_class();

}

#endif /* chapter7_hpp */
