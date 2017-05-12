#include <iostream>
#include <vector>
#include <math.h>
 
#ifndef TILE_H
#define TILE_H
 
class Tile
{
    private:
        // Members
        double r;               // radius
        double c1, c2;          // center (c1, c2)
 
        int curv;               // curvature
 
        double Ac[2][2];        // 2x2 matrix

        std::vector <std::vector <int> > subLat;


 
    public:
        std::vector <std::vector <int> > l_lat;
        int counter = 0;
        // Members
        //int chips;              // Will obtain this value from delta g(x)
                                  // Isn't this the same as lp? 05/03/17
 
        // Methods
        // Constructor
        Tile(double newr = 0, double newc1 = 0, double newc2 = 0, int newcurv = 0);       // Removed the scalars 05/02/17
        

        //setters
        void find_Ac();
        int find_gx(int x1, int x2);
        void find_sublat();
        void laplacian();
        void topple();


        //getters
        void get_Ac();
        void get_sublat();
        void get_l_lat();

        ~Tile();
 
};
 
#endif //TILE_H
