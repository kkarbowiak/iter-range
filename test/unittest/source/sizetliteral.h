#ifndef SIZE_T_LITERAL_H
#define SIZE_T_LITERAL_H

#include <cstddef>


constexpr std::size_t operator "" _z (unsigned long long int n)
{
    return n;
}

#endif /* SIZE_T_LITERAL_H */
