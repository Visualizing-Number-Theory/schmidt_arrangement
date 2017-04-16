//  circle_class.cpp
//  circle_class

#include "circle_class.hpp"

using namespace std;

//constructor
Circle::Circle(float r, float x, float y, int p)
{
        
    new_info = new Info;
    
    new_info -> radius = r;
    new_info -> x_coor = x;
    new_info -> y_coor = y;
    new_info -> prime = p;

    new_info -> delta = -1;

    /*
    new_info = new Info;
    new_info -> radius = r;
    new_info -> x_coor = x;
    new_info -> y_coor = y;
    new_info -> delta = -1;
    */
    //change later to accept values if needed
}

/*
bool sa_algo::isPrime(int var)
{
    bool prime_check = true;
    
    for (int i = 2; i < var; i++)
        if (var % i == 0)
        {
            prime_check = false;
        }

    return prime_check;
}

//make sure input is valid
int sa_algo::check_conditions()
{
    int right_var = std::pow(x_coor, 2) + y_coor + std::pow(y_coor,2);

    if (right_var % radius != 0)
    {
        throw std::invalid_argument("The condition (1) does not hold.");
    }
    
    bool check_prime = isPrime(prime);
    
    if (check_prime == true)
    {
        if (radius % prime != 0)
        {
            throw std::invalid_argument("p does not divide r.");
        }
    }
    else{
        throw std::invalid_argument("p is not prime.");
    }
    
    return 0;
}
*/

/*
//setter methods
void Circle::find_ed()
{
    int var = 1 + new_info -> y_coor;

    if (var % (new_info -> prime) != 0)
    {
        new_info -> e_d = 0;
    }
    else
    {
        int e_r = (new_info -> radius) / (new_info -> prime);
        int e_x = (new_info -> x_coor) / (new_info -> prime);
        new_info -> e_d = std::min(e_r, e_x);
        
    }
}

void Circle::find_ebp_edp()
{
    if ((new_info -> y_coor) % (new_info -> prime) != 0)
    {
        new_info -> e_bp = 0;
        new_info -> e_dp = 0;
    }
    else
    {
        int e_r = (new_info -> radius) / (new_info -> prime);
        int e_x = (new_info -> x_coor) / (new_info -> prime);
        new_info -> e_bp = std::min(e_r, e_x);
        new_info -> e_dp = new_info -> e_bp;
    }
}

void Circle::find_dp()
{
    int iterations = (new_info -> radius) / (new_info -> prime);
    int p_to_edp = std::pow(new_info -> prime, new_info -> e_dp);
    while (iterations > 1)
    {
        p_to_edp = p_to_edp * p_to_edp;
        iterations = iterations - 1;
    }

    new_info -> d_p = p_to_edp;
    
}

void Circle::find_d()
{
    int left1 = new_info -> y_coor;
    int right1 = -(new_info -> d_p) * (new_info -> x_coor);

    int left2 = new_info -> x_coor;
    int right2 = (new_info -> d_p) * (1 + (new_info -> y_coor));

    int mod = std::pow(new_info -> prime, (new_info -> radius) / (new_info -> prime));

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
            new_info -> d = d_;
            break;
        }
    }
}

void Circle::find_bp()
{
    int left1 = (new_info -> d) * (new_info -> y_coor) + (new_info -> d_p) * (new_info -> x_coor);
    int right1 = -(new_info -> radius) * (new_info -> y_coor);

    int left2 = (new_info -> d) * (new_info -> x_coor) - (new_info -> d_p) * (1 + (new_info -> y_coor));
    int right2 = -(new_info -> radius) * (new_info -> x_coor);

    int mod = std::pow(new_info -> prime, (new_info -> radius) / ((new_info -> prime) + (new_info -> e_dp)));
    
    int arr[mod];
    for (int i=0; i < mod; i++)
    {
        arr[i] = i;
    }

    for (int bp=0; bp < mod; bp++)
    {
        int eqn1 = bp * left1 - right1;
        int eqn2 = bp * left2 - right2;

        if (eqn1 % mod == 0 && eqn2 % mod == 0)
        {
            new_info -> b_p = bp;
            break;
        }
    }

}

void Circle::find_points()
{
    new_info -> b = ((new_info -> radius) + (new_info -> b_p) * (new_info -> d)) / (new_info -> d_p);
    new_info -> a = ((new_info -> b) * (new_info -> x_coor) - (new_info -> b_p) * (1 + (new_info -> y_coor))) / (new_info -> radius);
    new_info -> a_p = ((new_info -> b) * (new_info -> y_coor) + (new_info -> b_p) * (new_info -> x_coor)) / (new_info -> radius);
    new_info -> c = ((new_info -> d) * (new_info -> x_coor) - (new_info -> d_p) * (1 + (new_info -> y_coor))) / (new_info -> radius);
    new_info -> c_p = ((new_info -> d_p) * (new_info -> x_coor) + (new_info -> d) * (new_info -> y_coor)) / (new_info -> radius);
}

void Circle::find_circle_matrix()
{
    std::complex<int> a_11(new_info -> a, new_info -> a_p);
    std::complex<int> a_12(new_info -> c, new_info -> c_p);
    std::complex<int> a_21(new_info -> b, new_info -> b_p);
    std::complex<int> a_22(new_info -> d, new_info -> d_p);

    //MatrixXcf X(2,2); //How to declare a complex matrix
    //X(0,0) = a_11;    //How to assign to complex matrix=

    new_info -> A[0][0] = a_11;
    new_info -> A[0][1]= a_12;
    new_info -> A[1][0] = a_21;
    new_info -> A[1][1] = a_22;

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
*/



//getter methods
float Circle::get_radius(){

    return new_info->radius;

}

float Circle::get_x(){

    return new_info->x_coor;

}

float Circle::get_y(){

    return new_info->y_coor;

}

/*

void Circle::get_ed()
{
    std::cout << "e_d: " << new_info -> e_d << std::endl;
}

void Circle::get_ebp_edp()
{
    std::cout << "e_bp: " << new_info -> e_bp << std::endl;
    std::cout << "e_dp: " << new_info -> e_dp << std::endl;
}

void Circle::get_dp()
{
    std::cout << "d_p: " << new_info -> d_p << std::endl;
}

void Circle::get_d()
{
    std::cout << "d: " << new_info -> d << std::endl;
}

void Circle::get_bp()
{
    std::cout << "b_p: " << new_info -> b_p << std::endl;
}

void Circle::get_points()
{
    std::cout << "\n" << std::endl;
    std::cout << "b: " << new_info -> b << std::endl;
    std::cout << "a: " << new_info -> a << std::endl;
    std::cout << "a_p: " << new_info -> a_p << std::endl;
    std::cout << "c: " << new_info -> c << std::endl;
    std::cout << "c_p: " << new_info -> c_p << std::endl;
}

void Circle::get_circle_matrix()
{
    std::cout << '\n' << "Matrix: (real, imag)" << std::endl;
    std::cout << '(' << new_info -> A[0][0] << new_info -> A[0][1] << std::endl;
    std::cout << new_info -> A[1][0] << new_info -> A[1][1] << ')' << std::endl;
}
*/


//deconstructor
Circle::~Circle() {}























