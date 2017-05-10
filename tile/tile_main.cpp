#include <iostream>
//#include "tile.hpp"
#include "tile.cpp"

using namespace std;

void print_members(Tile some_tile)
{
    //cout << some_tile.get_r() << " ";
    //cout << some_tile.get_c1() << " ";
    //cout << some_tile.get_c2() << " ";
    //cout << some_tile.get_curv() << " " << endl;

    //cout << std::endl;

    //some_tile.get_Ac();

    //cout << std::endl;

    some_tile.xTranspose();
    //some_tile.get_xT();

    //std::cout << std::endl;

    some_tile.gxFunc();

    cout << some_tile.get_gx() << endl;

}


int main()
{
    // Test
    Tile new_tile(1, 1, 1, 1);          //r, c1, c2, curv

    print_members(new_tile);

    return 0;
}
