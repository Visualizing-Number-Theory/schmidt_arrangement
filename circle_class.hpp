//
//  circle_class.hpp
//  circle_class
//
//  Created by Paul Laliberte on 2/2/17.
//  Copyright © 2017 Paul Laliberte. All rights reserved.
//

#ifndef circle_class_hpp
#define circle_class_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Circle
{
private:
    struct Info
    {
        //t is an arbitrary type (int, float, char, ect.)
        float radii;
        float x_coor;
        float y_coor;
        vector<vector<float>> matrix;
    };

    Info *new_info;

public:
    //constructor
    Circle();
    //methods
    void zoom();
    void set_info();
    void get_info();
    //destructor
    virtual ~Circle();
};

#endif /* circle_class_hpp */
