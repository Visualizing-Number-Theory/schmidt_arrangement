#include <iostream>
#include "tile.hpp"
 
 
// Constructor with parameters
// Declare default values so we don't need two constructors
Tile::Tile(double newr, double newc1, double newc2, int newcurv)
{
    r = newr;
    c1 = newc2;
    c2 = newc1;
    curv = 4 * newcurv;

    std::vector <std::vector <int> > vec(curv+2, std::vector<int>(curv+2));

    subLat = vec;
}

Tile::~Tile() {}

//setters
void Tile::find_Ac()
{
    Ac[0][0] = .5 * (r + c1);
    Ac[1][0] = .5 * c2;
    Ac[0][1] = .5 * c2;
    Ac[1][1] = .5 * (r - c1);
}

int Tile::find_gx(int x1, int x2)
{
    double tmp_arr0[1][2];

    std::cout << x1 << " " << x2 << std::endl;

    tmp_arr0[0][0] = .5 * x1 * Ac[0][0] + .5 * x2 * Ac[1][0];
    tmp_arr0[0][1] = .5 * x1 * Ac[0][1] + .5 * x2 * Ac[1][1];

    double tmp_int = x1 * tmp_arr0[0][0] + x2 * tmp_arr0[0][1];

    return floor(tmp_int);
}

void Tile::find_sublat()
{

    int start_x1 = -1;

    int start_x2 = -1;

    for (int i=0; i < subLat.size(); i++)
    {
        for (int j=0; j < subLat[i].size(); j++)
        {
            subLat[i][j] = find_gx(start_x1, start_x2);
            //std::cout << start_x2 << std::endl;
            start_x2++;
        }
        start_x1++;
        start_x2 = -1;
    }
}

void Tile::laplacian()
{
    l_lat = subLat;

    for (int i = 0; i < l_lat.size(); i++)
    {
        for (int j = 0; j < l_lat[i].size(); j++)
        {

            l_lat[i][j] = 0;
        }
    }

    for (int i = 0; i < l_lat.size(); i++)
    {
        for (int j = 0; j < l_lat[i].size(); j++)
        {

            std::cout << l_lat[i][j] << std::endl;
        }
    }


    for (int i = 1; i < l_lat.size() - 1; i++)
    {
        for (int j = 1; j < l_lat[i].size() - 1; j++)
        {

            l_lat[i][j] = (subLat[i][j-1] - subLat[i][j]) + (subLat[i-1][j] - subLat[i][j])
            + (subLat[i][j+1] - subLat[i][j]) + (subLat[i+1][j] - subLat[i][j]);

        }
    }
}

// Topple places where chip value > 1
void Tile::topple()
{
    for (int i = 1; i < l_lat.size() - 1; i++)
    {
        for (int j = 1; j < l_lat[i].size() - 1; j++)
        {
            if (l_lat[i][j] > 1) //CHANGED FROM l_lat[i][j] > 1
            {
                // Decrease chip value at x by 1
                l_lat[i][j] = l_lat[i][j] - 4; //CHANGED FROM l_lat[i][j]--
 
                // Increase chip value at adjacent positions by 1
                // Right boundary
                if (j + 1 == l_lat.size())
                {
                    l_lat[i][1]++;
                }
                else
                {
                    l_lat[i][j+1]++;
                }

                // Left boundary
                if (j - 1 == 0)
                {
                    l_lat[i][l_lat.size()-1]++;
                }
                else
                {
                    l_lat[i][j-1]++;
                }

                // Top boundary
                if (i + 1 == l_lat.size())
                {
                    l_lat[1][j]++;
                }
                else
                {
                    l_lat[i+1][j]++;
                }

                // Bottom boundary
                if (i - 1 == 0)
                {
                    l_lat[l_lat.size() - 1][j]++;
                }
                else
                {
                    l_lat[i-1][j]++;
                }
            }
        }
    }
}

//getters
void Tile::get_Ac()
{
    std::cout << "(";

    for (int i=0; i < 2; i++)
    {
        for (int j=0; j<2; j++)
        {
            if (j+1 != 2)
            {
                std::cout << Ac[i][j] << ",";
            }
            else
            {
                std::cout << Ac[i][j];
            }
        }
        
        if (i+1 != 2)
        {
            std::cout << ")" << std::endl;
        }
        else
        {
            std::cout << ")";
        }
    }

    std::cout << ")" << std::endl;
}

void Tile::get_sublat()
{
    
    std::cout << "(" << std::endl;

    for (int i=0; i < subLat.size(); i++)
    {
        std::cout << "(";

        for (int j=0; j < subLat[i].size(); j++)
        {
            if (j+1 != subLat[i].size())
            {
                std::cout << subLat[i][j] << ",";
            }
            else
            {
                std::cout << subLat[i][j];
            }
        }

        std::cout << ")" << std::endl;
    }

    std::cout << ")" << std::endl;
}

void Tile::get_l_lat()
{
    std::cout << "(" << std::endl;

    for (int i=1; i < l_lat.size() - 1; i++)
    {
        std::cout << "(";

        for (int j=1; j < l_lat[i].size() - 1; j++)
        {
            if (j+1 != l_lat[i].size() - 1)
            {
                std::cout << l_lat[i][j] << ",";
            }
            else
            {
                std::cout << l_lat[i][j];
            }
        }

        std::cout << ")" << std::endl;
    }

    std::cout << ")" << std::endl;
}
