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
    vector<Circle> circles;

public:
    //constructor
    CircleGroup();
    //methods
    void zoom(float x_0, float y_0, float dist);
    void show();
    void highlight(float x, float y);
    //destructor
    virtual ~CircleGroup();
};

#endif /* circle_group_hpp */
