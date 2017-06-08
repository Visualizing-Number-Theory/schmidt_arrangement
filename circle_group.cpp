
//  circle_group.cpp
//  circle_group

#include "circle_group.hpp"

using namespace std;

CircleGroup::CircleGroup() {

    x = 0;
    y = 0;
    dist = 1;
    //r is curvature
    for(int r = 1; r < 19; r++){
        for(int s = 0; s < 3*r; s++){
            for(int t = 0; t < 3*r; t++){
                if((s*s + t*t - t) % r == 0 % r){
                    float xcoor = 700*(2*s)/(2*r);
                    float ycoor = 700*(2*t-1)/(2*r);
                    float radi = 700*1/(2*r);
                    
                    circles.push_back(sa_algo(radi, xcoor, ycoor, r, s, t, 2*s, -2*t+2*r+1)); // Kate changed this.
                }
            }
        }
    }

}

void CircleGroup::zoom(float x1, float x2, float y1, float y2){

    circles.clear();
    x1 = (x1/700)*dist + x;
    x2 = (x2/700)*dist + x;
    y1 = (y1/700)*dist + y;
    y2 = (y2/700)*dist + y;

    std::cout << "x1: " << x1 << "  x2: " << x2 << "  y1: " << y1 << "  y2: " << y2 << std::endl;

    if(x1 < 0){
        x1 = 0;
    }
    if(x2 < 0){
        x2 = 0;
    }
    if(y1 < 0){
        y1 = 0;
    }
    if(y2 < 0){
        y2 = 0;
    }

    if(x1 > 1){
        x1 = 1;
    }
    if(x2 > 1){
        x2 = 1;
    }
    if(y1 > 1){
        y1 = 1;
    }
    if(y2 > 1){
        y2 = 1;
    }



    if(x2<x1){
        float tmp = x2;
        x2 = x1;
        x1 = tmp;
    }

    if(y2<y1){
        float tmp = y2;
        y2 = y1;
        y1 = tmp;
    }

    if(x2-x1 < .05 && y2-y1 < .05){
        cout<<"Can't zoom in that far!"<<endl;
    }else{
        if((x2-x1)>=(y2-y1)){
            dist = x2-x1;
        }else{
            dist = y2-y1;
        }
        x = x1;
        y = y1;
    }

    for(int r = 1; r < 20/dist; r++){
        for(int s = x*r; s < (x + 1.5*dist)*r; s++){
            for(int t = y*r; t < (y+1.5*dist)*r; t++){
                if((s*s + t*t - t) % r == 0 % r){
                    float xcoor = (700/dist)*(2*s)/(2*r)-700*x/dist;
                    float ycoor = (700/dist)*(2*t-1)/(2*r)-700*y/dist;
                    float radi = (700/dist)*1/(2*r);
                    if(xcoor + radi > x or xcoor - radi < x + dist or ycoor + radi > y or ycoor - radi < y + dist){

                        circles.push_back(sa_algo(radi, xcoor, ycoor, r, s, t, 2*s, -2*t+2*r+1));
                    }
                }
            }
        }
    }

}

void CircleGroup::show(){

    for(int i = 0; i < circles.size(); i++){
        al_draw_circle(circles[i].get_x(), circles[i].get_y(), circles[i].get_radius(), al_map_rgb(255, 255, 255), 1);
    }

}

sa_algo CircleGroup::click(float posx, float posy)
{
    float dsq = 0;
    float rsqmax = 0;
    float rsqmin = 0;


    for(int i = 0; i < circles.size(); i++){
        dsq = (posx-circles[i].get_x())*(posx-circles[i].get_x()) + (posy-circles[i].get_y())*(posy-circles[i].get_y());
        rsqmax = circles[i].get_radius()*circles[i].get_radius()*1.05 + 150;
        rsqmin = circles[i].get_radius()*circles[i].get_radius()*0.95 - 150;

        if(dsq >= rsqmin && dsq <= rsqmax){
            return circles[i];
        }
    }
    //need return an error (or identifier for an error)
    return sa_algo(0,0,0,0,0,0,0,0);

}


int CircleGroup::highlight(float posx, float posy){

    float dsq = 0;
    float rsqmax = 0;
    float rsqmin = 0;


    for(int i = 0; i < circles.size(); i++){
        dsq = (posx-circles[i].get_x())*(posx-circles[i].get_x()) + (posy-circles[i].get_y())*(posy-circles[i].get_y());
        rsqmax = circles[i].get_radius()*circles[i].get_radius()*1.05 + 150;
        rsqmin = circles[i].get_radius()*circles[i].get_radius()*0.95 - 150;

        if(dsq >= rsqmin && dsq <= rsqmax){
            al_draw_circle(circles[i].get_x(), circles[i].get_y(), circles[i].get_radius(), al_map_rgb(255, 0, 0), 3);
            return i;
        }
    }
    return -1;

}

CircleGroup::~CircleGroup() {
    while(circles.size() != 0){
        circles.pop_back();
    }
}

