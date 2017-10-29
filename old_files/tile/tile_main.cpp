#include <iostream>
#include "tile.hpp"
//#include "tile.cpp"


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




void find_pattern(Tile a_tile)
{
    a_tile.find_Ac();
    a_tile.get_Ac();

    a_tile.find_sublat();
    std::cout << "Prelaplacian" << std::endl;
    a_tile.get_sublat();

    

    a_tile.laplacian();
    std::cout << "Postlaplacian" << std::endl;
    a_tile.get_l_lat();

    int counter = 0;

    Tile new_tile;

    new_tile = toppling(a_tile);

    new_tile.get_l_lat();


    
}


int main()
{
    // Test
    // SWAP c1,c2 --> c2,c1 --> takes place in constructor
    //Tile new_tile(.5, 0, .5, 2);          //r, c2, c1, curv

    Tile new_tile(1, 3, 2, 3, 1, 3, 3);
    //new_tile.find_Ac();
    //new_tile.find_gx(0,1);
    
    find_pattern(new_tile);

    return 0;
}
