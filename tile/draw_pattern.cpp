#include <iostream>
#include <vector>
#include "allegro5/allegro.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_primitives.h"
 
using namespace std;
 
int main(){
 
    vector<vector<int>> piles;
    vector<int> column;
 
    column.push_back(-2);
    column.push_back(1);
    column.push_back(0);
 
    piles.push_back(column);
 
    column.clear();
    column.push_back(-1);
    column.push_back(0);
    column.push_back(-2);
 
    piles.push_back(column);
 
    column.clear();
    column.push_back(1);
    column.push_back(1);
    column.push_back(-1);
 
    piles.push_back(column);
 
    int window_size = piles.size() * 20 + 20;
 
    ALLEGRO_DISPLAY *display = NULL;
    if(!al_init()){
        return -1;
    }
 
    display = al_create_display(window_size, window_size);
    if(!display){
        return -1;
    }
 
    al_init_primitives_addon();
 
    for(int i = 0; i < piles.size(); i++){
        for(int j = 0; j < piles[i].size(); j++){
            if(piles[i][j] == -2){
                al_draw_filled_rectangle(10+20*i, 10+20*j, 30+20*i, 30+20*j, al_map_rgb(229, 240, 255));
            }else if(piles[i][j] == -1){
                al_draw_filled_rectangle(10+20*i, 10+20*j, 30+20*i, 30+20*j, al_map_rgb(170, 207, 255));
            }else if(piles[i][j] == 0){
                al_draw_filled_rectangle(10+20*i, 10+20*j, 30+20*i, 30+20*j, al_map_rgb(102, 168, 255));
            }else if(piles[i][j] == 1){
                al_draw_filled_rectangle(10+20*i, 10+20*j, 30+20*i, 30+20*j, al_map_rgb(40, 133, 255));
            }
        }
    }
 
    al_flip_display();
 
    al_rest(10);
 
}
