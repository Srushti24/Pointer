//
//  Box.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "Box.hpp"
#include <iostream>

// Constructor
Box::Box() : m_len(0) { std::cout << "Box constructor created" << std::endl; }

// Destructor
Box::~Box() {
    std::cout << "Box destructor called" << std::endl;
}

// Param constructor
Box::Box(int length) : m_len(length) { std::cout << " Box Param constrcutor called " << std::endl; }

// Copy constructor
Box::Box(const Box& copyBox): m_len(copyBox.m_len) {
    std::cout << " Box Copy constructor is called" << std::endl;
}

// Copy Assignment operator
Box& Box::operator=(const Box& copyBox) {
    std::cout << " Box Copy Assignment is called" << std::endl;
    m_len         = copyBox.m_len;
    return *this;
}

// Move constructor
Box::Box(Box&& copyBox) : m_len(copyBox.m_len) {
    std::cout << " Box Move constructor is called" << std::endl;
    copyBox.m_len = 0;
}

// Move assignment operator
Box& Box::operator=(Box&& copyBox) {
    std::cout << " Box Move assignment operator is called" << std::endl;
    m_len         = copyBox.m_len;
    copyBox.m_len = 0;
}