//
//  Screen.cpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 6.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#include "Screen.hpp"

using namespace std;

void test_screen() {
    Screen screen {3, 4, '.'};
    screen.move(0, 2).set('a');
    screen.move(2, 0).set('b');
    screen.move(1, 1).set('c').display(cout);
    
    Screen screen2 {6, 8, '.'};
    screen2.move(0, 2).set('a');
    screen2.move(2, 0).set('b');
    screen2.move(1, 1).set('c').display(cout);
    
    cout << "--------" << endl;
    WindowManager wm;
    wm.add(&screen).add(&screen2);
    wm.display_screens();
    
    cout << "--------" << endl;
    wm.clear(0);
    wm.display_screens();
    
    cout << "--------" << endl;
    wm.clear(0);
    wm.display_screens();
}
