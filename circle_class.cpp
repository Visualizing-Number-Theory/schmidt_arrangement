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
sa_algo::sa_algo(float r, float x, float y, int c_r, int s, int t)
{
    radius = r;
    x_coor = x;
    y_coor = y;

    cr = c_r;
    cx = s;
    cy = t;
    prime = isPrime(cr);


    //std::cout << prime << std::endl;

    delta = -1;
}

//make sure input is valid
int sa_algo::check_conditions()
{
    int right_var = cx * cx + cy + cy * cy;
    if (right_var % cr != 0)
    {
        //throw std::invalid_argument("The condition (1) does not hold.");
        return 1;
    } 

    return 0;
}

int sa_algo::check_d_bp()
{
    if (d == 0 || b_p == 0)
    {
        return 1;
    }
    return 0;
}

int sa_algo::check_dp()
{
    if (d_p == 0)
    {
        return 1;
    }
    return 0;
}

//setter methods
void sa_algo::find_ed()
{
    int var = 1 + cy;
    if (var % prime != 0)
    {
        e_d = 0;
    }
    else
    {
        int e_r = cr / prime;
        int e_x = cx / prime;
        e_d = std::min(e_r, e_x);
        
    }
}

void sa_algo::find_ebp_edp()
{
    if (cy % prime != 0)
    {
        e_bp = 0;
        e_dp = 0;
    }
    else
    {
        int e_r = cr / prime;
        int e_x = cx / prime;
        e_bp = std::min(e_r, e_x);
        e_dp = e_bp;
    }
}

void sa_algo::find_dp()
{
    int iterations = cr / prime;
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
    int left1 = cy;
    int right1 = -d_p * cx;

    int left2 = cx;
    int right2 = d_p * (1 + cy);

    int mod = std::pow(prime, cr / prime);

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
            found_d = 0;
            break;
        }
    }
}

void sa_algo::find_bp()
{

    int left1 = d *  cy + d_p * cx;
    int right1 = -cr * cy;

    int left2 = d * cx - d_p * (1 + cy);
    int right2 = -cr * cx;

    int mod = std::pow(prime, (cr / prime) + e_dp);

    for (int bp=0; bp < mod; bp++)
    {
        int eqn1 = bp * left1 - right1;
        int eqn2 = bp * left2 - right2;

        if (eqn1 % mod == 0 && eqn2 % mod == 0)
        {
            b_p = bp;
            found_bp = 0;
            break;
        }
    }

}

void sa_algo::find_points()
{
    b = float((cr + b_p * d)) / d_p;
    a = float((b * cx - b_p * (1 + cy))) / cr;
    a_p = float((b * cy + b_p * cx)) / cr;
    c = float((d * cx - d_p * (1 + cy))) / cr;
    c_p = float((d_p * cx + d * cy)) / cr;
}

void sa_algo::find_circle_matrix()
{
    std::complex<float> a_11(a, a_p);
    std::complex<float> a_12(c, c_p);
    std::complex<float> a_21(b, b_p);
    std::complex<float> a_22(d, d_p);

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

    return radius;

}

int sa_algo::get_x(){

    return x_coor;

}

int sa_algo::get_y(){

    return y_coor;

}

int sa_algo::get_cr(){

    return cr;

}

int sa_algo::get_cx(){

    return cx;

}

int sa_algo::get_cy(){

    return cy;

}

int sa_algo::get_found_d()
{
    return found_d;
}

int sa_algo::get_found_bp()
{
    return found_bp;
}


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


//getter methods
void sa_algo::get_initial_variables()
{
    std::cout << "curve r: " << cr << std::endl;
    std::cout << "curve x: " << cx << std::endl;
    std::cout << "curve y: " << cy << std::endl;
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
