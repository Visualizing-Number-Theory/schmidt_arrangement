//  circle_class.cpp
//  circle_class

#include "circle_class.hpp"

using namespace std;


int isPrime(int num)
{
    int prime_number = -1;

    for (int i=2; i <= num; i++)
    {
        if (num % i == 0)
        {
            prime_number = i;
            return prime_number;
        }
    }
        
    return prime_number;
}


//constructor
sa_algo::sa_algo(float r, float x, float y, int cr, int cs, int ct)
{
    radius1 = r;
    x_coor1 = x;
    y_coor1 = y;

    radius = cr;
    x_coor = cs;
    y_coor = ct;
    prime = isPrime(r);


    //std::cout << prime << std::endl;

    delta = -1;
}

//make sure input is valid
int sa_algo::check_conditions()
{
    int right_var = x_coor * x_coor + y_coor + y_coor * y_coor;
    if (right_var % radius != 0)
    {
        //throw std::invalid_argument("The condition (1) does not hold.");
        return 1;
    } 

    return 0;
}


//setter methods
void sa_algo::find_ed()
{
    int var = 1 + y_coor;
    if (var % prime != 0)
    {
        e_d = 0;
    }
    else
    {
        int e_r = radius / prime;
        int e_x = x_coor / prime;
        e_d = std::min(e_r, e_x);
        
    }
}

void sa_algo::find_ebp_edp()
{
    if (y_coor % prime != 0)
    {
        e_bp = 0;
        e_dp = 0;
    }
    else
    {
        int e_r = radius / prime;
        int e_x = x_coor / prime;
        e_bp = std::min(e_r, e_x);
        e_dp = e_bp;
    }
}

void sa_algo::find_dp()
{
    int iterations = radius / prime;
    int p_to_edp = std::pow(prime, e_dp);

    //std::cout << iterations << " " << p_to_edp << std::endl;
    
    while (iterations > 1)
    {
        p_to_edp = p_to_edp * p_to_edp;
        iterations = iterations - 1;
    }

    d_p = p_to_edp;
    
}

void sa_algo::find_d()
{
    int left1 = y_coor;
    int right1 = -d_p * x_coor;

    int left2 = x_coor;
    int right2 = d_p * (1 + y_coor);

    int mod = std::pow(prime, radius / prime);

    int arr[mod];
    for (int i=0; i < mod; i++)
    {
        arr[i] = i;
    }

    for (int d_=0; d_ < mod; d_++)
    {
        int eqn1 = d_ * left1 - right1;
        int eqn2 = d_ * left2 - right2;

        if (eqn1 %  mod == 0 && eqn2 % mod == 0)
        {
            d = d_;
            break;
        }
    }
}

void sa_algo::find_bp()
{
    int left1 = d *  y_coor + d_p * x_coor;
    int right1 = -radius * y_coor;

    int left2 = d * x_coor - d_p * (1 + y_coor);
    int right2 = -radius * x_coor;

    int mod = std::pow(prime, radius / (prime + e_dp));
    
    for (int bp=0; bp < mod; bp++)
    {
        int eqn1 = bp * left1 - right1;
        int eqn2 = bp * left2 - right2;

        if (eqn1 % mod == 0 && eqn2 % mod == 0)
        {
            b_p = bp;
            break;
        }
    }

}

void sa_algo::find_points()
{
    b = (radius + b_p * d) / d_p;
    a = (b * x_coor - b_p * (1 + y_coor)) / radius;
    a_p = (b * y_coor + b_p * x_coor) / radius;
    c = (d * x_coor - d_p * (1 + y_coor)) / radius;
    c_p = (d_p * x_coor + d * y_coor) / radius;
}

void sa_algo::find_circle_matrix()
{
    std::complex<int> a_11(a, a_p);
    std::complex<int> a_12(c, c_p);
    std::complex<int> a_21(b, b_p);
    std::complex<int> a_22(d, d_p);

    //MatrixXcf X(2,2); //How to declare a complex matrix
    //X(0,0) = a_11;    //How to assign to complex matrix=

    A[0][0] = a_11;
    A[0][1]= a_12;
    A[1][0] = a_21;
    A[1][1] = a_22;

}

int sa_algo::get_prime()
{
    return prime;
}

int sa_algo::get_radius(){

    return radius1;

}

int sa_algo::get_x(){

    return x_coor1;

}

int sa_algo::get_y(){

    return y_coor1;

}

int sa_algo::get_radius2(){

    return radius;

}

int sa_algo::get_x2(){

    return x_coor;

}

int sa_algo::get_y2(){

    return y_coor;

}


/*
int sa_algo::check_circle_equivalence()
{
    std::tuple<int, int, int> coordinates;
    coordinates = std::make_tuple(radius, x_coor, y_coor);
    if (delta == -1)
    {
        std::tuple<int, int, int> check;
        check = std::make_tuple(b * d_p - b_p * d, b * c_p - a_p * d, a_p * d_p - b_p * c_p);
        if (check != coordinates)
        {
            throw std::invalid_argument("Matrix not valid - error occurred");
        }
    }
    else
    {
        std::tuple<int, int, int> check;
        check = std::make_tuple(b_p * d - b * d_p, a_p * d - b * c_p, b * c - a * d);
        if (check != coordinates)
        {
            throw std::invalid_argument("Matrix not valid - error occurred");
        }
    
    }
    return 0;
}
*/

//getter methods
void sa_algo::get_initial_variables()
{
    std::cout << "radius: " << radius << std::endl;
    std::cout << "x-coordinate: " << x_coor << std::endl;
    std::cout << "y-coordinate: " << y_coor << std::endl;
    std::cout << "prime: " << prime << std::endl;
}


void sa_algo::get_ed()
{
    std::cout << "e_d: " << e_d << std::endl;
}

void sa_algo::get_ebp_edp()
{
    std::cout << "e_bp: " << e_bp << std::endl;
    std::cout << "e_dp: " << e_dp << std::endl;
}

void sa_algo::get_dp()
{
    std::cout << "d_p: " << d_p << std::endl;
}

void sa_algo::get_d()
{
    std::cout << "d: " << d << std::endl;
}

void sa_algo::get_bp()
{
    std::cout << "b_p: " << b_p << std::endl;
}

void sa_algo::get_points()
{
    std::cout << "\n" << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a_p: " << a_p << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "c_p: " << c_p << std::endl;
}

void sa_algo::get_circle_matrix()
{
    std::cout << '\n' << "Matrix: (real, imag)" << std::endl;
    std::cout << '(' << A[0][0] << A[0][1] << std::endl;
    std::cout << A[1][0] << A[1][1] << ')' << std::endl;
}



//deconstructor
sa_algo::~sa_algo() {}
