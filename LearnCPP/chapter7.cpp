//
//  chapter7.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 6.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "chapter7.hpp"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

namespace chapter7 {

// constructors

Sale::Sale() = default;

Sale::Sale(const string& s): bookNo(s) {}
Sale::Sale(const string& s, int n, double p): bookNo(s), units_sold(n), revenue(n*p) {}
Sale::Sale(istream& is){
    parse(is, *this);
}

// public members

inline string Sale::isbn() const { return bookNo; }

inline double Sale::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

inline Sale& Sale::combine(const Sale& rhs){
    if (bookNo != rhs.isbn()){
        throw invalid_argument("ISBN of two sales must be same when combininig");
    }
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// friend members

Sale add(const Sale& lhs, const Sale& rhs) {
    Sale res = lhs;
    res.combine(rhs);
    return res;
}

// input transactions contain ISBN, number of copies sold, and sales price
istream& parse(istream &is, Sale &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sale &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

// tests
void test_structs() {
    Sale total; // variable to hold the running sum
    if (parse(cin, total)) { // read the first transaction
        Sale trans; // variable to hold data for the next transaction
        while(parse(cin, trans)) { // read the remaining transactions
            if (total.isbn() == trans.isbn()) // check the isbns
                total.combine(trans); // updatetherunningtotal
            else {
                print(cout, total) << endl;
                total = trans;
                break;
            }
        }
        print(cout, total) << endl;
    }
    else {
        cerr << "No data?!" << endl;
    }
}

void test_sale_class() {
//    Sale a0 = "A"; // error: explicit constructor
    Sale a0("A"); // explicit constructor allows direct initialization
    Sale a1{"A", 1, 1};
    Sale a2{"A", 2, 1.2};
    Sale a3{"A", 30, 0.5};
    Sale a_total = add(add(a1, a2), a3);
    print(cout, a_total) << endl;
    
    Sale b{"B", 2, 3};
    
    try {
        Sale total = add(a1, b);
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
}

}
