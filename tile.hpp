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
 
 
        int x[2][1];            // 2x1 vector
        int xT[1][2];           // 1x2 vector; transpose of x
        double xT_Ac[1][2];     // 1x2 vector; for g(x)
        double xT_Ac_x;         // "1x1" vector -- i.e. a single value; for g(x)
 
        int gx;                 // g(x) value; calculated: floor(1/2 * x^T * Ac * x)
 
 
        int y1[2][1];           // 2x1 vector
        int y2[2][1];           // 2x1 vector
        int y3[2][1];           // 2x1 vector
        int y4[2][1];           // 2x1 vector
 
        int yT1[1][2];          // 1x2 vector; transpose y1
        int yT2[1][2];          // 1x2 vector; transpose y2
        int yT3[1][2];          // 1x2 vector; transpose y3
        int yT4[1][2];          // 1x2 vector; transpose y4
 
        double yT_Ac[1][2];     // 1z2 vector; for g(y)
        double yT_Ac_y;         // "1x1" vector -- i.e. single value; for g(y)
 
        int gy1, gy2, gy3, gy4;
 
 
        // ***************************** FIX THIS *****************************
        //int subLat[100][100];       // Figure out how to set size
        std::vector <std::vector <int> > subLat;
 
        int lp;                 // Result from Laplacian function --> chip value
 
 
 
    public:
        // Members
        //int chips;              // Will obtain this value from delta g(x)
                                  // Isn't this the same as lp? 05/03/17
 
        // Methods
        // Constructor
        Tile(double newr = 0, double newc1 = 0, double newc2 = 0, int newcurv = 0);       // Removed the scalars 05/02/17
 
        // Destructor
        ~Tile();
 
        // Getters
        double get_r();
        double get_c1();
        double get_c2();
        int get_curv();
        void get_Ac();
        void get_xT();
        int get_gx();
        int get_gy_all();
 
 
        // Setters
        // void set_r(int newr);
        // void set_c1(int newc1);
        // void set_c2(int newc2);
 
 
        // Transpose vectors
        void xTranspose();
        void yTranspose_all();
 
 
        // Method for calculating g(x) = floor(1/2 * x^T * Ac * x)
        void gxFunc();
        void gyFunc_all();
 
 
        // Discrete Laplacian function
        void Laplacian();
 
 
        // Function to topple chips/stabilize
        void topple();
 
 
};
 
#endif //TILE_H
