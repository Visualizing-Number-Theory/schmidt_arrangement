#include <iostream>
#include "tile.hpp"
 
 
// Constructor with parameters
// Declare default values so we don't need two constructors
Tile::Tile(double newr, double newc1, double newc2, int newcurv)
{
    r = newr;
    c1 = newc1;
    c2 = newc2;
    curv = newcurv;
 
    Ac[0][0] = .5 * (r + c1);
    Ac[1][0] = .5 * c2;
    Ac[0][1] = .5 * c2;
    Ac[1][1] = .5 * (r - c1);
}
 
 
// Destructor
Tile::~Tile()
{
 
}
 
 
 
// Getters
double Tile::get_r()
{
    return r;
}
 
double Tile::get_c1()
{
    return c1;
}
 
double Tile::get_c2()
{
    return c2;
}
 
 
int Tile::get_curv()
{
    return curv;
}
 
void Tile::get_Ac()
{
    std::cout << "((" << Ac[0][0] << ", " << Ac[0][1] << ")" << std::endl;
    std::cout << "(" << Ac[1][0] << ", " << Ac[1][1] << "))" << std::endl;
}
 
void Tile::get_xT()
{
    //This is for testing -- print x-vec to compare
    std::cout << "(" << x[0][0] << ", " << x[1][0] << ")" << std::endl;
 
    std::cout << "(" << xT[0][0] << std::endl;
    std::cout << " " << xT[0][1] << ")" << std::endl;
}
 
int Tile::get_gx()
{
    return gx;
}
 
 
 
 
// Setters
// void Tile::set_r(int newr)
// {
//     r = newr;
// }
//
// void Tile::set_c1(int newc1)
// {
//     c1 = newc1;
// }
//
// void Tile::set_c2(int newc2)
// {
//     c2 = newc2;
// }
 
 
 
// Transpose x (2x1) --> xT (1x2)
void Tile::xTranspose()
{
    //This is for testing - we don't have a x-vec yet
    x[0][0] = 10;
    x[1][0] = 20;
 
    xT[0][0] = x[0][0];
    xT[0][1] = x[1][0];
}
 
void Tile::yTranspose_all()
{
    //This is for testing - we don't have a x-vec yet
 
    yT1[0][0] = y1[0][0];
    yT1[0][1] = y1[1][0];
 
    yT2[0][0] = y2[0][0];
    yT2[0][1] = y2[1][0];
 
    yT3[0][0] = y3[0][0];
    yT3[0][1] = y3[1][0];
 
    yT4[0][0] = y4[0][0];
    yT4[0][1] = y4[1][0];
 
}
 
 
 
 
// Find integer value for g(x) = floor(1/2 * x^T * Ac * x)
void Tile::gxFunc()
{
    // Multiply xT by 1/2
    xT[0][0] = .5 * xT[0][0];

    xT[0][1] = .5 * xT[0][1];
 
    // Calculate xT * Ac
    xT_Ac[0][0] = xT[0][0] * Ac[0][0] + xT[0][1] * Ac[1][0];
    xT_Ac[0][1] = xT[0][0] * Ac[0][1] + xT[0][1] * Ac[1][1];
 
    // Calculate xT_Ac * x
    xT_Ac_x = xT_Ac[0][0] * x[0][0] + xT_Ac[0][1] * x[1][0];
 
    // Take floor of result from above
    gx = floor(xT_Ac_x);
}
 
 
 
// Find integer values for g(y) = floor(1/2 * y^T * Ac * y)
void Tile::gyFunc_all()
{
    // Calculating g(y1)
    yT1[0][0] = .5 * yT1[0][0];
    yT1[0][1] = .5 * yT1[0][1];
 
    yT_Ac[0][0] = yT1[0][0] * Ac[0][0] + yT1[0][1] * Ac[1][0];
    yT_Ac[0][1] = yT1[0][0] * Ac[0][1] + yT1[0][1] * Ac[1][1];
 
    yT_Ac_y =  yT_Ac[0][0] * y1[0][0] + yT_Ac[0][1] * y1[1][0];
 
    gy1 = floor(yT_Ac_y);
 
 
    // Calculating g(y2)
    yT2[0][0] = .5 * yT2[0][0];
    yT2[0][1] = .5 * yT2[0][1];
 
    yT_Ac[0][0] = yT2[0][0] * Ac[0][0] + yT2[0][1] * Ac[1][0];
    yT_Ac[0][1] = yT2[0][0] * Ac[0][1] + yT2[0][1] * Ac[1][1];
 
    yT_Ac_y =  yT_Ac[0][0] * y2[0][0] + yT_Ac[0][1] * y2[1][0];
 
    gy2 = floor(yT_Ac_y);
 
 
    // Calculating g(y3)
    yT3[0][0] = .5 * yT3[0][0];
    yT3[0][1] = .5 * yT3[0][1];
 
    yT_Ac[0][0] = yT3[0][0] * Ac[0][0] + yT3[0][1] * Ac[1][0];
    yT_Ac[0][1] = yT3[0][0] * Ac[0][1] + yT3[0][1] * Ac[1][1];
 
    yT_Ac_y =  yT_Ac[0][0] * y3[0][0] + yT_Ac[0][1] * y3[1][0];
 
    gy3 = floor(yT_Ac_y);
 
 
    // Calculating g(y4)
    yT4[0][0] = .5 * yT4[0][0];
    yT4[0][1] = .5 * yT4[0][1];
 
    yT_Ac[0][0] = yT4[0][0] * Ac[0][0] + yT4[0][1] * Ac[1][0];
    yT_Ac[0][1] = yT4[0][0] * Ac[0][1] + yT4[0][1] * Ac[1][1];
 
    yT_Ac_y =  yT_Ac[0][0] * y4[0][0] + yT_Ac[0][1] * y4[1][0];
 
    gy4 = floor(yT_Ac_y);
}
 
 
 
 
// Calculate Discrete Laplacian
void Tile::Laplacian()
{
    for (int i = 0; i < curv; i++)
    {
        for (int j = 0; j < curv; j++)
        {
            // Set coordinates for x vector
            x[0][0] = i;
            x[1][0] = j;
 
            // Find transpose of x vector
            xTranspose();
 
            // Calculate g(x)
            gxFunc();
 
            // Find coordinates of all points adjacent to x --> y1, y2, y3, y4
            y1[0][0] = x[0][0];
            y1[1][0] = x[1][0] + 1;
 
            y2[0][0] = x[0][0] + 1;
            y2[1][0] = x[1][0];
 
            y3[0][0] = x[0][0];
            y3[1][0] = x[1][0] - 1;
 
            y4[0][0] = x[0][0] - 1;
            y4[1][0] = x[1][0];
 
            // Find transpose of all y vectors
            yTranspose_all();
 
            // Calculate g(y)
            gyFunc_all();
 
            // Calculate Laplacian for x vector
            lp = (gy1 - gx) + (gy2 - gx) + (gy3 - gx) + (gy4 - gx);
 
 
            // ************** FIX THIS **************
            // Need to store lp value into a 2-dim vector (? or array?)
            subLat[i][j] = lp;
        }
    }
}
 
 
 
// Topple places where chip value > 1
// ******************************* FIX THIS *******************************
// Figure out: (1) 2D vector okay?; (2) toppling chips on edge of sublattice
void Tile::topple()
{
    for (int i = 0; i < subLat.size(); i++)
    {
        for (int j = 0; j < subLat[i].size(); j++)
        {
            if (subLat[i][j] > 1)
            {
                // Decrease chip value at x by 1
                subLat[i][j]--;
 
                // Increase chip value at adjacent positions by 1
                subLat[i][j+1]++;
                subLat[i][j-1]++;
                subLat[i+1][j]++;
                subLat[i-1][j]++;
            }
        }
    }
}
