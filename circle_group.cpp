//  circle_group.cpp
//  circle_group

#include "circle_group.hpp"
#include <iostream>
#include <vector>

#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"

using namespace std;

CircleGroup::CircleGroup() {

    for(int r = 1; r < 10; r++){
        for(int s = 1; s < 3*r; s++){
            for(int t = 1; t < 3*r; t++){
                if((s*s + t*t - t) % r == 0 % r){
                    float xcoor = 200*(2*s)/(2*r);
                    float ycoor = 200*(2*t-1)/(2*r);
                    float radi = 200*1/(2*r);
                    circles.push_back(Circle(radi, xcoor, ycoor));
                }
            }
        }
    }

}

void CircleGroup::zoom(float x_0, float y_0, float dist){



}

void CircleGroup::show(){

    for(int i = 0; i < circles.size(); i++){
        al_draw_circle(circles[i].get_x(), circles[i].get_y(), circles[i].get_radius(), al_map_rgb(255, 255, 255), 1);
    }

}

void CircleGroup::highlight(float x, float y){

}

CircleGroup::~CircleGroup()
{
    while(circles.size() != 0){
        circles.pop_back();
    }
}
