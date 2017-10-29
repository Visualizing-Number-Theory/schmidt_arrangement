#include <boost/rational.hpp>
#include <iostream>

using namespace boost;

int main()
{
    int num = 1;
    int denom = 3;

    rational<int> r(num,denom);
    //rational<double> sharon(1,1);
    std::cout << r << std::endl;


}
