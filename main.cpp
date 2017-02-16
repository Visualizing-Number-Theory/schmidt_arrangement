//
//  main.cpp
//  circle_class
//
//  Created by Paul Laliberte on 2/2/17.
//  Copyright © 2017 Paul Laliberte. All rights reserved.
//

#include "circle_class.hpp"
#include "circle_class.cpp"
#include <iostream>
#include "allegro5/allegro5.h"
#include "allegro5/allegro_primitives.h"

int main(int argc, const char * argv[])
{

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;

	if(!al_init()){
		return -1;
	}

	display = al_create_display(700, 700);
	timer = al_create_timer(0.5);

	if(!display){
        return -1;
	}

    if(!timer){
        return -1;
    }

	al_init_primitives_addon();
	al_install_mouse();

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    bool done = false;
    bool down = false;
    float pos_x;
    float pos_y;

    while(!done){

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        switch(ev.type){

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;

        case ALLEGRO_EVENT_MOUSE_AXES:
            //circle highlighting
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;


        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            cout<<"mouse down"<<endl;
            al_start_timer(timer);
            down = true;

        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if(down == true){
                al_stop_timer(timer);
                if(al_get_timer_count(timer) <=1){
                    cout<<"click"<<endl;
                }
                else{
                    cout<<"drag"<<endl;
                }
                down = false;
            }

        }



    }

    /*Circle<float> new_circle;
    new_circle.set_info();
    new_circle.get_info();*/

    return 0;

}
