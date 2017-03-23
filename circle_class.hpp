//  circle_class.hpp
//  circle_class

#ifndef circle_class_hpp
#define circle_class_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Circle
{
private:
    struct Info
    {
        //t is an arbitrary type (int, float, char, ect.)
        float radius;
        float x_coor;
        float y_coor;
        vector<vector<float>> matrix;
    };

    Info* new_info;

public:
    //constructor
    Circle();
    Circle(float r, float x, float y);
    //methods
    void set_info();
    float get_radius();
    float get_x();
    float get_y();
    void print_info();
    //destructor
    virtual ~Circle();
};

#endif /* circle_class_hpp */
