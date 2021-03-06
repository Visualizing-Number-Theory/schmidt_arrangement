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
#include <boost/rational.hpp>
#include <pthread.h>

//using namespace Eigen;  //uncomment if using Eigen

using namespace std;

#ifndef class_sa_hpp
#define class_sa_hpp

class sa_algo
{
private:
    //initial variables
    float radius, x_coor, y_coor;
    int cr, tile_x, tile_y, prime, matrix_x, matrix_y;

    //d_p
    int d_p;
    
    //d, bp
    int d, b_p;
    
    //points to find
    float a, b, a_p, c, c_p;
    
    //matrix (store variables in array)
    std::complex<float> A[2][2];


public:
    //constructor
    sa_algo(float r, float x, float y, int c_r, int s, int t);
    
    //check conditions
    int check_conditions();
    int check_circle_equivalence();
    
    //setter methods
    void find_d();
    void find_gaussian_matrix();
    
    //getter methods
    void get_initial_variables();
    void print_bp();
    void print_dp();
    void print_d();

    void get_points();
    void get_gaussian_matrix();

    int get_prime();
    int get_cr();
    int get_tile_x();
    int get_tile_y();
    int get_radius();
    int get_x();
    int get_y();
    int get_dp();
    int get_matrix_x();
    int get_matrix_y();
        
    //destructor
    ~sa_algo();
};



#endif /* class_sa_hpp */
