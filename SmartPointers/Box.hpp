//
//  Box.hpp
//  Pointer
//
//  Created by Srushti Desai on 12/27/23.
//

#ifndef BOX_hpp
#define BOX_hpp

#include <stdio.h>

class Box {
  public:
    Box();
    Box(int length);
    Box(const Box& copyBox);
    Box(Box&& copyBox);
    Box& operator=(const Box& copyBox);
    Box& operator=(Box&& copyBox);
    int m_len;
    ~Box();
};
#endif /* Box_hpp */
