//
//  Screen.hpp
//  LearnCPP
//
//  Created by Barış Deniz Sağlam on 6.08.2020.
//  Copyright © 2020 BDS. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

class Screen;

class WindowManager {
    std::vector<Screen*> screens;
    
public:
    using ScreenIndex = std::vector<Screen*>::size_type;
    void clear(ScreenIndex index);
    WindowManager& add(Screen* screen);
    void display_screens() const;
};

inline WindowManager& WindowManager::add(Screen* screen) {
    screens.push_back(screen);
    return *this;
}


class Screen {
public:
    using pos = std::string::size_type;
    
    // constructors
    Screen() = default;
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) {}
    Screen(pos h, pos w, std::string s): height(h), width(w), contents(s) {}
    
    // public members
    char get() const { return contents[cursor]; }
    inline char get(pos y, pos x) const;
    Screen& move(pos y, pos x);
    Screen& set(char c);
    Screen& set(char c, pos y, pos x);
    Screen& display(std::ostream& os);
    const Screen& display(std::ostream& os) const;
    
    // friends
    friend void WindowManager::clear(WindowManager::ScreenIndex);
    
private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    
    void do_display(std::ostream& os) const {
        for (int i = 0; i != height; ++i) {
            for (int j = 0; j != width; ++j) {
                std::cout << get(i, j);
            }
            std::cout << '\n';
        }
    }
};

// explicitly define inline
inline Screen& Screen::move(pos y, pos x) {
    cursor = width * y + x;
    return *this;
}

// declared as inline in class
char Screen::get(pos y, pos x) const {
    pos idx = width * y + x;
    return contents[idx];
}

inline Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::display(std::ostream &os){
    do_display(os);
    return *this;
}

inline const Screen& Screen::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

inline void WindowManager::display_screens() const {
    for (Screen* ptr: screens) {
        ptr->display(std::cout);
    }
}

inline void WindowManager::clear(ScreenIndex index) {
    screens.erase(screens.begin() + index);
}

// tests
void test_screen();

#endif /* Screen_hpp */
