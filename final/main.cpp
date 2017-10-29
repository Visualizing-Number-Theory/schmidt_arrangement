//  main.cpp
//  circle_class

#include "circle_group.hpp"
#include "tile.hpp"

Tile* toppling(Tile* a_tile)
{
    bool check = false;
    int i,j;

    for (i = 1; i < a_tile->l_lat.size() - 1; i++)
    {
        for (j = 1; j < a_tile->l_lat.size() - 1; j++)
        {
            if (a_tile->l_lat[i][j] > 1)
            {
                a_tile->topple();
                a_tile->counter++;


                std::cout << "Number of times toppled: " << a_tile->counter << std::endl;


                check = a_tile->check_topple();

                if (check == true)
                {
                    break;
                }

                i = 1;
                j = 1;
            }
        }
        if (check == true)
        {
            break;
        }

    }

    if (check != true)
    {
        a_tile->class_check = true;
    }
    return a_tile;
}

void* PatternDraw(void* new_tile){

    Tile *t = (Tile*) new_tile;
    t->draw_pattern();
    delete new_tile;
    pthread_exit(NULL);

}

void find_pattern(sa_algo a_circle)
{
    Tile* a_tile = new Tile(1, a_circle.get_cr(), a_circle.get_tile_x(), a_circle.get_cr(), a_circle.get_tile_y(), a_circle.get_cr(), a_circle.get_cr());


    a_tile->find_Ac();
    std::cout << "A_C matrix:" << std::endl;
    a_tile->get_Ac();

    a_tile->find_sublat();
    //std::cout << "PreLaplacian" << std::endl;
    //a_tile->get_sublat(); // Kate commented this out to more easily see other data.

    a_tile->laplacian();
    //std::cout << "PostLaplacian (not fully toppled)" << std::endl;
    //a_tile->get_l_lat();

    Tile* new_tile;

    new_tile = toppling(a_tile);

    if (new_tile->class_check == true)
    {
        //new_tile->get_l_lat();

        pthread_t *thread = new pthread_t;
        pthread_create(thread, NULL, PatternDraw, (void*)a_tile);
    }
    else
    {
        std::cout << "Does not stabilize." << std::endl;
    }
}

void find_matrix(sa_algo a_circle)
{
    //check if the first condition r | x^2 + y + y^2 holds
    //
    std::cout << "\n" << std::endl;
    a_circle.get_initial_variables();
    std::cout << "\n" << std::endl;

    if (a_circle.check_conditions() == 0)
    {
        std::cout << "Conditon failed: r | x^2 + y + y^2 --- continuing ---" << std::endl;
        a_circle.find_gaussian_matrix();
        a_circle.get_gaussian_matrix();
    }
    else
    {
        std::cout << "Condition passed: r | x^2 + y + y^2" << std::endl;

        a_circle.find_gaussian_matrix();
        a_circle.get_gaussian_matrix();
        std::cout << "\n" << std::endl;

        //check if matrix is correct
        if (a_circle.check_circle_equivalence() == 0)
        {
            a_circle.get_points();
        }
    }
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
                    if (a_circle.get_cr() != 0 || a_circle.get_tile_x() != 0 || a_circle.get_tile_y() != 0)
                    {
			std::cout << "Curvature, x*curv, y*curv, a prime divisor to use:" << std::endl; // Kate added an exlanation

                        std::cout << a_circle.get_cr() << " " << a_circle.get_tile_x() << " " << a_circle.get_tile_y() << " " << a_circle.get_prime() << std::endl;
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
