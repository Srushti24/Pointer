//
//  Box.cpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#include "Box.hpp"
#include <iostream>

Box::Box():m_len(0), m_width(0), m_height(0)
{
    std::cout << "Box constructor created \n";  
}

Box::~Box()
{
    std::cout << "box constructor destroyed \n";
}
