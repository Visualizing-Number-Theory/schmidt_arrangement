//  circle_group.hpp
//  circle_group


#ifndef circle_group_hpp
#define circle_group_hpp

#include <stdio.h>
#include <vector>
#include "circle_class.hpp"

using namespace std;

class CircleGroup
{
private:
    float x;
    float y;
    float dist;
    vector<Circle> circles;

public:
    //constructor
    CircleGroup();
    //methods
    void zoom(float x1, float x2, float y1, float y2);
    void show();
    int highlight(float x, float y);
    //destructor
    virtual ~CircleGroup();
};

#endif /* circle_group_hpp */
