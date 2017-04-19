//  circle_class.hpp
//  circle_class

#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"

#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
//#include <Eigen/Dense>  //<-- use if matrix mul/add is needed
#include <complex>

//using namespace Eigen;  //uncomment if using Eigen

using namespace std;

#ifndef class_sa_hpp
#define class_sa_hpp

class sa_algo
{
private:
    //initial variables
    int radius, x_coor, y_coor, prime, delta;

    //e_d, e_bp, e_dp
    int e_d, e_bp, e_dp;

    //d_p
    int d_p;
    
    //d, bp
    int d, b_p;
    
    //points to find
    int a, b, a_p, c, c_p;
    
    //matrix (store variables in array)
    std::complex<int> A[2][2];


public:
    //constructor
    sa_algo(int r, int x, int y);
    
    //check conditions
    //int check_conditions();
    //int check_circle_equivalence();
    
    //setter methods
    void find_ed();
    void find_ebp_edp();
    void find_dp();
    void find_d();
    void find_bp();
    void find_points();
    void find_circle_matrix();

    int get_x();
    int get_y();
    int get_radius();
    
    //getter methods
    void get_initial_variables();
    void get_ed();
    void get_ebp_edp();
    void get_dp();
    void get_d();
    void get_bp();
    void get_points();
    void get_circle_matrix();
    
    //destructor
    ~sa_algo();
    
};



#endif /* class_sa_hpp */
