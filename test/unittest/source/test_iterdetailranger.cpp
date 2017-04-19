#include "catch/catch.hpp"

#include "iterRange.h"

#include "numelems.h"

#include <cstddef>


TEST_CASE("ctor defa", "[iter][detail][ranger][ctor][default]")
{
    SECTION("int")
    {
        iter::detail::ranger<int> ran;

        REQUIRE(!(ran.begin() != ran.end()));
    }

    SECTION("std::size_t")
    {
        iter::detail::ranger<std::size_t> ran;

        REQUIRE(!(ran.begin() != ran.end()));
    }
}

TEST_CASE("ctor stop", "[iter][detail][ranger][ctor][stop]")
{
    SECTION("int")
    {
        int const stop = 5;
        iter::detail::ranger<int> ran(stop);
        int const values[] = {0, 1, 2, 3, 4};
        std::size_t i = 0;

        for (auto i0 : ran)
        {
            REQUIRE(i0 == values[i++]);
        }

        REQUIRE(i == num_elems(values));
    }

    SECTION("std::size_t")
    {
        std::size_t const stop = 5;
        iter::detail::ranger<std::size_t> ran(stop);
        std::size_t values[] = {0, 1, 2, 3, 4};
        std::size_t i = 0;

        for (auto i0 : ran)
        {
            REQUIRE(i0 == values[i++]);
        }
        REQUIRE(i == num_elems(values));
    }
}

TEST_CASE("ctor start stop step", "[iter][detail][ranger][ctor][start][stop][step]")
{
    SECTION("int")
    {
        SECTION("forward")
        {
            int const start = 2;
            int const stop = 12;
            int const step = 3;
            iter::detail::ranger<int> ran(start, stop, step);
            int const values[] = {2, 5, 8, 11};
            std::size_t i = 0;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == values[i++]);
            }
            REQUIRE(i == num_elems(values));
        }

        SECTION("backward")
        {
            int const start = -7;
            int const stop = -23;
            int const step = -2;
            iter::detail::ranger<int> ran(start, stop, step);
            int const values[] = {-7, -9, -11, -13, -15, -17, -19, -21};
            std::size_t i = 0;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == values[i++]);
            }
            REQUIRE(i == num_elems(values));
        }
    }

    SECTION("std::size_t")
    {
        SECTION("forward")
        {
            std::size_t const start = 2;
            std::size_t const stop = 12;
            std::size_t const step = 3;
            iter::detail::ranger<std::size_t> ran(start, stop, step);
            std::size_t const values[] = {2, 5, 8, 11};
            std::size_t i = 0;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == values[i++]);
            }
            REQUIRE(i == num_elems(values));
        }

        SECTION("backward")
        {
            std::size_t const start = -7;
            std::size_t const stop = -23;
            std::size_t const step = -2;
            iter::detail::ranger<std::size_t> ran(start, stop, step);
            std::size_t const values[] = {-7, -9, -11, -13, -15, -17, -19, -21};
            std::size_t i = 0;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == values[i++]);
            }
            REQUIRE(i == num_elems(values));
        }
    }
}