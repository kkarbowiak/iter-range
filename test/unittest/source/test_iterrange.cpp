#include "catch/catch.hpp"

#include "iter_range.h"

#include "numelems.h"
#include "sizetliteral.h"

#include <cstddef>


TEST_CASE("range", "[iter][range]")
{
    SECTION("forward")
    {
        SECTION("stop")
        {
            SECTION("empty")
            {
                SECTION("char")
                {
                    auto r = iter::range('\0');

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("int")
                {
                    auto r = iter::range(0);

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("std::size_t")
                {
                    auto r = iter::range(0_z);

                    REQUIRE(!(r.begin() != r.end()));
                }
            }

            SECTION("non-empty")
            {
                SECTION("char")
                {
                    char const values[] = {0, 1, 2, 3, 4};
                    std::size_t i = 0;

                    auto r = iter::range(5);

                    for (auto i0 : r)
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("int")
                {
                    int const values[] = {0, 1, 2, 3, 4};
                    std::size_t i = 0;

                    auto r = iter::range(5);

                    for (auto i0 : r)
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("std::size_t")
                {
                    std::size_t const values[] = {0_z, 1_z, 2_z, 3_z, 4_z};
                    std::size_t i = 0;

                    auto r = iter::range(5_z);

                    for (auto i0 : r)
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }
            }
        }

        SECTION("start, stop")
        {
            SECTION("empty")
            {
                SECTION("char")
                {
                    auto r = iter::range('\0', '\0');

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("int")
                {
                    auto r = iter::range(0, 0);

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("std::size_t")
                {
                    auto r = iter::range(0_z, 0_z);

                    REQUIRE(!(r.begin() != r.end()));
                }
            }

            SECTION("non-empty")
            {
                SECTION("char")
                {
                    char const values[] = {'a', 'b', 'c', 'd', 'e'};
                    std::size_t i = 0;

                    for (auto i0 : iter::range('a', 'f'))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("int")
                {
                    int const values[] = {3, 4, 5, 6, 7};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(3, 8))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("std::size_t")
                {
                    std::size_t const values[] = {3_z, 4_z, 5_z, 6_z, 7_z};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(3_z, 8_z))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }
            }
        }

        SECTION("start, stop, step")
        {
            SECTION("empty")
            {
                SECTION("char")
                {
                    auto r = iter::range('\0', '\0', char(3));

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("int")
                {
                    auto r = iter::range(0, 0, 3);

                    REQUIRE(!(r.begin() != r.end()));
                }

                SECTION("std::size_t")
                {
                    auto r = iter::range(0_z, 0_z, 3_z);

                    REQUIRE(!(r.begin() != r.end()));
                }
            }

            SECTION("forward")
            {
                SECTION("char")
                {
                    char const values[] = {'a', 'd', 'g', 'j'};
                    std::size_t i = 0;

                    for (auto i0 : iter::range('a', 'm', char(3)))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("int")
                {
                    int const values[] = {2, 5, 8, 11};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(2, 12, 3))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }

                SECTION("std::size_t")
                {
                    std::size_t const values[] = {2_z, 5_z, 8_z, 11_z};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(2_z, 12_z, 3_z))
                    {
                        REQUIRE(i0 == values[i++]);
                    }

                    REQUIRE(i == num_elems(values));
                }
            }

            SECTION("backward")
            {
                SECTION("char")
                {
                    char const values[] = {'x', 'v', 't', 'r', 'p', 'n', 'l', 'j', 'h'};
                    std::size_t i = 0;

                    for (auto i0 : iter::range('x', 'f', char(-2)))
                    {
                        REQUIRE(i0 == values[i++]);
                    }
                    
                    REQUIRE(i == num_elems(values));
                }

                SECTION("int")
                {
                    int const values[] = {-7, -9, -11, -13, -15, -17, -19, -21};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(-7, -23, -2))
                    {
                        REQUIRE(i0 == values[i++]);
                    }
                    
                    REQUIRE(i == num_elems(values));
                }

                SECTION("std::size_t")
                {
                    std::size_t const values[] = {-7_z, -9_z, -11_z, -13_z, -15_z, -17_z, -19_z, -21_z};
                    std::size_t i = 0;

                    for (auto i0 : iter::range(-7_z, -23_z, -2_z))
                    {
                        REQUIRE(i0 == values[i++]);
                    }
                    
                    REQUIRE(i == num_elems(values));
                }
            }
        }
    }
}
