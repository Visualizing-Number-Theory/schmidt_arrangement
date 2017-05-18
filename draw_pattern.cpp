#include "circle_class.hpp"

void showTile(vector<vector<int>> matrix, int dim){

    int tile_size = 20;
    if(dim > 250){
        cout<<"Not showing whole matrix"<<endl;
        dim = 250;
    }

    int window_size = dim * tile_size + 20;
    if(window_size > 1020){
        tile_size = 1000/dim;
        window_size = tile_size*dim + 20;
    }

    ALLEGRO_DISPLAY *display = NULL;
	if(!al_init()){
        cout<<"Allegro didn't initialize!"<<endl;
		return;
	}

	display = al_create_display(window_size, window_size);
    if(!display){
        cout<<"Allegro couldn't create display!"<<endl;
        return;
	}

    al_init_primitives_addon();

    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(matrix[i][j] == -2){
                al_draw_filled_rectangle(10+tile_size*i, 10+tile_size*j, 10+tile_size*(i+1), 10+tile_size*(j+1), al_map_rgb(229, 240, 255));
            }else if(matrix[i][j] == -1){
                al_draw_filled_rectangle(10+tile_size*i, 10+tile_size*j, 10+tile_size*(i+1), 10+tile_size*(j+1), al_map_rgb(170, 207, 255));
            }else if(matrix[i][j] == 0){
                al_draw_filled_rectangle(10+tile_size*i, 10+tile_size*j, 10+tile_size*(i+1), 10+tile_size*(j+1), al_map_rgb(102, 168, 255));
            }else if(matrix[i][j] == 1){
                al_draw_filled_rectangle(10+tile_size*i, 10+tile_size*j, 10+tile_size*(i+1), 10+tile_size*(j+1), al_map_rgb(40, 133, 255));
            }
        }
    }

    al_flip_display();

    al_rest(10);

}
