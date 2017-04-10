#include "../../iterRange.h"

#include <iostream>


int main()
{
    std::cout << "range(5):" << std::endl;
    for (auto i : iter::range(5))
    {
        std::cout << i << std::endl;
    }
    
    std::cout << "range(2, 12):" << std::endl;;
    for (auto i : iter::range(2, 12))
    {
        std::cout << i << std::endl;
    }
    
    std::cout << "range(1, 17, 2):" << std::endl;
    for (auto i : iter::range(1, 17, 2))
    {
        std::cout << i << std::endl;
    }
    
    std::cout << "range(21, 5, -1):" << std::endl;
    for (auto i : iter::range(21, 5, -1))
    {
        std::cout << i << std::endl;
    }
}
