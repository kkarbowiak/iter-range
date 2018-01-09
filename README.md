# C++11 Range #

C++11 standard brings the so called range-based for loop. It extends the syntax of `for` statement to allow iteration over a range of items:

```
int array = {1, 2, 3, 5, 7};
for (int i : array)
{
    // do something
}
```

This implementation adds `range` function that mimics the usage of Python's counterpart in for loops. It allows to use the new syntax to conveniently iterate over a range:

```
for (int i : iter::range(10))
{
    std::cout << i << '\n';
}
```

## Usage ##

There are two overloads. First takes single `stop` parameter and allows iteration in range [0, stop). The second overload takes three parameters: `start`, `stop`, and `step`. The default value for `step` is 1.

```
#include "iter_range.h"
#include <iostream>

int main()
{
    for (int i : iter::range(10))
    {
        std::cout << i << ' ';
    }
    // this outputs '0 1 2 3 4 5 6 7 8 9 '

    for (int i : iter::range(2, 5))
    {
        std::cout << i << ' ';
    }
    // this outputs '2 3 4 '

    for (int i : iter::range(1, 17, 2))
    {
        std::cout << i << ' ';
    }
    // this outputs '1 3 5 7 9 11 13 15 '

    for (int i : iter::range(10, 3, -2))
    {
        std::cout << i << ' ';
    }
    // this outputs '10 8 6 4 '

    for (int i : iter::range(0, -10, -1))
    {
        std::cout << i << ' ';
    }
    // this outputs '0 -1 -2 -3 -4 -5 -6 -7 -8 -9 '

    for (int i : iter::range(0))
    {
        std::cout << i << ' ';
    }
    // this outputs ''
}
```

## License ##

This project is released under **MIT/X11** license, so feel free to do anything you like with it.


