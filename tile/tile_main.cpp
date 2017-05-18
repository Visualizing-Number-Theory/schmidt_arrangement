#include <iostream>
#include "tile.hpp"
//#include "tile.cpp"


void toppling(Tile a_tile)
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

                //a_tile.get_l_lat();

                i = 1;
                j = 1;
            }
        }
    }
}

void find_pattern(Tile a_tile)
{
    a_tile.find_Ac();
    a_tile.get_Ac();

    a_tile.find_sublat();
    std::cout << "Prelaplacian" << std::endl;
    a_tile.get_sublat();

    a_tile.laplacian();
    std::cout << "lap" << std::endl;
    a_tile.get_l_lat();

    int counter = 0;

    toppling(a_tile);


    a_tile.get_l_lat();
}
    


int main()
{
    // Test
    // SWAP c1,c2 --> c2,c1 --> takes place in constructor
    //Tile new_tile(.5, 0, .5, 2);          //r, c2, c1, curv

    Tile new_tile(1.0/3.0, 1.0/3.0, 2.0/3.0, 3);
    
    find_pattern(new_tile);

    return 0;
}
