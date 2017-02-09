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

	if(!al_init())
		return -1;

	display = al_create_display(700, 700);

	if(!display)
		return -1;

	al_init_primitives_addon();
	al_install_mouse();

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    bool done = false;
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


        }



    }

    /*Circle<float> new_circle;
    new_circle.set_info();
    new_circle.get_info();*/

    return 0;

}
