//  main.cpp
//  circle_class

#include "circle_group.hpp"
#include "tile.hpp"

Tile toppling(Tile a_tile)
{
    int i,j;

    for (i = 1; i < a_tile.l_lat.size() - 1; i++)
    {
        for (j = 1; j < a_tile.l_lat.size() - 1; j++)
        {
            if (a_tile.l_lat[i][j] > 1)
            {
                a_tile.topple();
                a_tile.counter++;

                std::cout << "Number of times toppled: " << a_tile.counter << std::endl;

                if (a_tile.counter > 100)
                {
                    break;
                }

                i = 1;
                j = 1;
            }
        }

        if (a_tile.counter > 100)
        {
            break;
        }
    }

    return a_tile;
}

void find_pattern(sa_algo a_circle)
{
    Tile a_tile(a_circle.get_radius() / 700.0 , a_circle.get_x() / 700.0, a_circle.get_y() / 700.0, a_circle.get_cr());


    a_tile.find_Ac();
    a_tile.get_Ac();

    a_tile.find_sublat();
    std::cout << "PreLaplacian" << std::endl;
    a_tile.get_sublat();

    a_tile.laplacian();
    std::cout << "PostLaplacian" << std::endl;
    a_tile.get_l_lat();

    int counter = 0;

    Tile new_tile;

    new_tile = toppling(a_tile);

    new_tile.get_l_lat();

    //new_tile.draw_pattern();
}

void find_matrix(sa_algo some_circle)
{

    //int check = some_circle.check_conditions();
    int prime = some_circle.get_prime();

    //std::cout << check << " " << prime << std::endl;
    /*
    if (check == 0 && prime != -1)
    {
        some_circle.find_ed();
        //some_circle.get_ed();

        some_circle.find_ebp_edp();
        //some_circle.get_ebp_edp();

        some_circle.find_dp();
        //some_circle.get_dp();
        
        if (some_circle.check_dp() == 0)
        {

            some_circle.find_d();
            //some_circle.get_d();

            some_circle.find_bp();
            //some_circle.get_bp();
            
            if (some_circle.get_found_d() == 0 && some_circle.get_found_bp() == 0)
            {
            
                some_circle.find_points();
                //some_circle.get_points()

                some_circle.find_circle_matrix();
                some_circle.get_circle_matrix();
            }
            else
            {
                std::cout << "congruences could not be solved" << std::endl;
            }
        
        }
        else
        {
            std::cout << "d_p = 0: cannot calculate b point" << std::endl;
        }
    }
    else
    {
        std::cout << "One or more conditions do not hold" << std::endl;
    }
    */

    some_circle.find_ed();
        //some_circle.get_ed();

    some_circle.find_ebp_edp();
        //some_circle.get_ebp_edp();

    some_circle.find_dp();
        //some_circle.get_dp();
        //
    some_circle.find_d();
            //some_circle.get_d();

    some_circle.find_bp();
            //some_circle.get_bp();

    some_circle.find_points();
                //some_circle.get_points()

    some_circle.find_circle_matrix();
    some_circle.get_circle_matrix();

    //some_circle.check_circle_equivalence();



    
}

int main(int argc, char **argv)
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
                    sa_algo a_circle = Apollo.click(initpos_x, initpos_y);
                    if (a_circle.get_cr() != 0 || a_circle.get_cx() != 0 || a_circle.get_cy() != 0)
                    {
                        std::cout << a_circle.get_cr() << " " << a_circle.get_cx() << " " << a_circle.get_cy() << " " << a_circle.get_prime() << std::endl;
                        //std::cout << a_circle.get_radius() / 700.0  << " " << a_circle.get_x() / 700.0 << " " << a_circle.get_y() / 700.0 << std::endl;
                        find_pattern(a_circle);
                        find_matrix(a_circle);
                        change = true;
                    }
                    else
                    {
                        change = false; 
                    }
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
