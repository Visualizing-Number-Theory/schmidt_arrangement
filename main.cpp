//  main.cpp
//  circle_class

#include "circle_class.hpp"
#include "circle_class.cpp"
#include "circle_group.hpp"
#include "circle_group.cpp"
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
	timer = al_create_timer(0.1);

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
    bool change = true;
    int high = -1;
    int oldhigh = -1;
    float initpos_x;
    float initpos_y;
    float pos_x;
    float pos_y;

    CircleGroup Apollo;

    while(!done){

        ALLEGRO_EVENT ev;

        if(change){
            al_clear_to_color(al_map_rgb(0, 0, 0));
            Apollo.show();
            al_flip_display();
        }

        al_wait_for_event(event_queue, &ev);


        switch(ev.type){

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            change = false;
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            al_set_timer_count(timer, 0);
            al_start_timer(timer);
            initpos_x = ev.mouse.x;
            initpos_y = ev.mouse.y;
            down = true;
            change = false;
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            if(down){
                al_stop_timer(timer);
                if(al_get_timer_count(timer) <= 2.5){
                    //CLICK => circle selection
                    change = false;
                }
                else{
                    //DRAG => zoom
                    Apollo.zoom(initpos_x, ev.mouse.x, initpos_y, ev.mouse.y);
                    change = true;
                }
            }
            down = false;
            break;

        case ALLEGRO_EVENT_MOUSE_AXES:
            //circle highlighting
            pos_x = ev.mouse.x;
            pos_y = ev.mouse.y;
            change = true;
            if(al_get_timer_count(timer) >= 2.5 && down){
                al_draw_rectangle(initpos_x, initpos_y, pos_x, pos_y, al_map_rgb(255, 0, 0), 1);
            }
            else{
                high = Apollo.highlight(pos_x, pos_y);
                if(oldhigh != -1 && high != oldhigh){
                    change = true;
                }else{
                    change = false;
                }
                oldhigh = high;
            }
            break;

        }

        al_flip_display();


    }

    /*Circle<float> new_circle;
    new_circle.set_info();
    new_circle.get_info();*/

    return 0;

}
