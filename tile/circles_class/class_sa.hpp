//
//  class_sa.hpp
//  sa_algo
//
//  Created by Paul Laliberte on 3/18/17.
//  Copyright © 2017 Paul Laliberte. All rights reserved.
//

#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cmath>
//linear algebra package for matrix - several options
//complex numbers package for matrix and bp - several options

#ifndef class_sa_hpp
#define class_sa_hpp

class sa_algo
{
private:
    //initial variables
    int radius, x_coor, y_coor, prime;

    //e_d, e_bp, e_dp
    int e_d, e_bp, e_dp;

    // dp       // added 04/05/17
    int dp;

    //d, bp
    int d, bp;

    //points to find
    int a, b, ap, c, cp;

    //matrix

public:
    //constructor
    sa_algo();

    //check conditions
    bool isPrime(int var);
    int check_conditions();

    //setter methods
    void find_ed();
    void find_ebp_edp();
    void find_dp();
    void find_d();
    void find_bp();
    void find_points();
    void find_circle_matrix();

    //getter methods
    void get_initial_variables();
    void get_ed();
    void get_ebp_edp();
    void get_dp();
    void get_d();
    void get_bp();
    void get_points();
    void get_circle_matrix();
    //void get_dp();

    //destructor
    ~sa_algo();

};



#endif /* class_sa_hpp */
