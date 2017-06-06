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

int find_gcd_3(int a, int b, int c)
{
    if (a % c == 0 && b % c == 0)
    {
        return c;
    }
    else
    {
        return find_gcd_3(a, b, c-1);
    }
}


//constructor
sa_algo::sa_algo(float r, float x, float y, int c_r, int s, int t)
{
    radius = r;
    x_coor = x;
    y_coor = y;

    cr = c_r;
    cx = s;
    cy = -t;
    prime = isPrime(cr);


    //std::cout << prime << std::endl;

    delta = -1;
}

//setters
//make sure input is valid
int sa_algo::check_conditions()
{
    int right_var = cx * cx + cy + cy * cy;
    if (right_var % cr != 0)
    {
        return 0;
    } 

    return 1;
}

int sa_algo::check_circle_equivalence()
{
    std::tuple<int, int, int> coordinates;
    coordinates = std::make_tuple(cr, cx, cy);
    if (delta == -1)
    {
        std::tuple<int, int, int> check;
        check = std::make_tuple(b_p * d - b * d_p, a_p * d - b * c_p, b * c - a * d);
        if (check != coordinates)
        {
            return 0;
        }
    }
    else if (delta != -1)
    {
        //pass for now
    }
    return 1;
}


void sa_algo::find_d()
{
    int left1 = cy;
    int right1 = -d_p * cx;

    int left2 = cx;
    int right2 = d_p * (1 + cy);

    int mod = cr;

    for (int d_=0; d_ < mod; d_++)
    {
        int eqn1 = d_ * left1 - right1;
        int eqn2 = d_ * left2 - right2;

        if (eqn1 % mod == 0 && eqn2 % mod == 0)
        {
            d = d_;
            break;
        }
    }
}

void sa_algo::find_gaussian_matrix()
{
    if (cr == 0)
    {
        //pass for now
    }
    else
    {
        b_p = find_gcd_3(std::abs(cr), std::abs(cx), std::abs(cy));
        d_p = b_p;
        find_d();
        b = (cr + b_p * d) / d_p;
        a = (b * cx - b_p * (1 + cy)) / cr;
        a_p = (b * cy + b_p * cx) / cr;
        c = (d * cx - d_p * (1 + cy)) / cr;
        c_p = (d_p * cx + d * cy) / cr;

        std::complex<float> a_11(a, a_p);
        std::complex<float> a_12(c, c_p);
        std::complex<float> a_21(b, b_p);
        std::complex<float> a_22(d, d_p);

        A[0][0] = a_11;
        A[0][1]= a_12;
        A[1][0] = a_21;
        A[1][1] = a_22;
    }
}

//getters 
void sa_algo::get_initial_variables()
{
    std::cout << "curve r: " << cr << std::endl;
    std::cout << "curve x: " << cx << std::endl;
    std::cout << "curve y: " << cy << std::endl;
    //std::cout << "prime: " << prime << std::endl;
}

void sa_algo::print_bp()
{
    std::cout << "b_p: " << b_p << std::endl;
}

void sa_algo::print_dp()
{
    std::cout << "d_p: " << d_p << std::endl;
}

void sa_algo::print_d()
{
    std::cout << "d: " << d << std::endl;
}

void sa_algo::get_points()
{
    std::cout << "\n" << std::endl;
    std::cout << "b_p: " << b_p << std::endl;
    std::cout << "d_p: " << d_p << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a_p: " << a_p << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "c_p: " << c_p << std::endl;
}

void sa_algo::get_gaussian_matrix()
{
    std::cout << '\n' << "Matrix: (real, imag)" << std::endl;
    std::cout << '(' << A[0][0] << A[0][1] << std::endl;
    std::cout << A[1][0] << A[1][1] << ')' << std::endl;
}

int sa_algo::get_prime()
{
    return prime;
}

int sa_algo::get_cr()
{
    return cr;
}

int sa_algo::get_cx()
{
    return cx;
}

int sa_algo::get_cy()
{
    return cy;
}

int sa_algo::get_radius()
{
    return radius;
}

int sa_algo::get_x()
{
    return x_coor;
}

int sa_algo::get_y()
{
    return y_coor;
}

int sa_algo::get_dp()
{
    return d_p;
}


//deconstructor
sa_algo::~sa_algo() {}
