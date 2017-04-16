//  circle_class.cpp
//  circle_class

#include "circle_class.hpp"

using namespace std;


Circle::Circle(float r, float x, float y) {

    new_info = new Info;

    new_info -> radius = r;
    new_info -> x_coor = x;
    new_info -> y_coor = y;

}

void Circle::set_info()
{

}

float Circle::get_radius(){

    return new_info->radius;

}

float Circle::get_x(){

    return new_info->x_coor;

}

float Circle::get_y(){

    return new_info->y_coor;

}

void Circle::print_info()
{
    cout << "Radius = " << new_info -> radius << endl;
    cout << "x_coor = " << new_info -> x_coor << endl;
    cout << "y_coor = " << new_info -> y_coor << endl;

}

Circle::~Circle()
{
    ///some drama here that needs to be figured out
    //delete new_info;
}























