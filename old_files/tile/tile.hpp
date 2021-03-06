#include <iostream>
#include <vector>
#include <cmath>
#include <boost/rational.hpp>
 
#ifndef TILE_H
#define TILE_H
 
class Tile
{
    private:
        // Members
        int num_r;
        int den_r;

        int num_c1;
        int den_c1;

        int num_c2;
        int den_c2;
 
        int curv;               // curvature
 
        boost::rational<int> Ac[2][2];        // 2x2 matrix

        std::vector <std::vector <int> > subLat;


 
    public:
        std::vector <std::vector <int> > l_lat;
        int counter = 0;
        // Members
        //int chips;              // Will obtain this value from delta g(x)
                                  // Isn't this the same as lp? 05/03/17
 
        // Methods
        // Constructor
        Tile(int nr=0, int dr=0, int nc1=0, int dc1=0, int nc2=0, int dc2=0, int newcurv=0);
        

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
