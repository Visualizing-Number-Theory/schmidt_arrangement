//
//  circle_class.cpp
//  circle_class
//
//  Created by Paul Laliberte on 2/2/17.
//  Copyright © 2017 Paul Laliberte. All rights reserved.
//

#include "circle_class.hpp"
#include <iostream>
#include <vector>

using namespace std;

template<class t>
Circle<t>::Circle() {}

template<class t>
void Circle<t>::zoom()
{
    //zoom function
    cout << "Zooming in/out" << endl;
}

template<class t>
void Circle<t>::set_info()
{
    //Extract info about circle
    float r = 10.0;
    float x_c = 5.0;
    float y_c = 9.0;

    new_info = new Info;

    vector<vector<float> > M(5);
    for (float i=0.0; i < 5.0; i++)
        M[i].resize(5);

    new_info -> radii = r;
    new_info -> x_coor = x_c;
    new_info -> y_coor = y_c;
    new_info -> matrix = M;

}

template<class t>
void Circle<t>::get_info()
{
    cout << "Radii = " << new_info -> radii << endl;
    cout << "x_coor = " << new_info -> x_coor << endl;
    cout << "y_coor = " << new_info -> y_coor << endl;

    vector<vector<float>> M;

    M = new_info -> matrix;

    cout << "Matrix = \n";

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            cout << M[i][j];
        }
        cout << endl;
    }
}

template<class t>
Circle<t>::~Circle()
{
    //Delete the new_info struct, but I'm too lazy
}
