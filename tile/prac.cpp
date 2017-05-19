#include <boost/rational.hpp>
#include <iostream>

using namespace boost;

int main()
{
    rational<int> r(1,2);
    rational<int> sharon(1,1);
    std::cout << r + sharon  << std::endl;


}
