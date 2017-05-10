//
//  main.cpp
//  sa_algo
//
//  Created by Paul Laliberte on 3/18/17.
//  Copyright © 2017 Paul Laliberte. All rights reserved.
//

//#include "class_sa.hpp"
#include "class_sa.cpp"

void allegro_code()
{
    //sa_algo new_circle;
    //Chloe's code
    //
}

void find_matrix(sa_algo *some_circle)
{
    some_circle->find_ed();

    //add other setter functions
}

void get_variables(sa_algo *some_circle)
{

    //print out variables to test:
    some_circle->get_initial_variables();
    std::cout << "" << std::endl;
    some_circle->get_ed();

    //add other getter functions
}

int main()
{
    //initialize a new class
    sa_algo new_circle;
    sa_algo *circle;
    circle = &new_circle;

    //this is fine also (but change the print_variables function input too!):
    //sa_algo a_circle;
    //a_circle.get_initial_variables();


    //catch exceptions - do not change
    try
    {
        circle->check_conditions();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << "Try entering values again." << std::endl;
        return 0;
    }

    find_matrix(circle);
    get_variables(circle);

    return 0;
}
