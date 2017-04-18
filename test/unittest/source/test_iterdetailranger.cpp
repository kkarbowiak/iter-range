#include "catch/catch.hpp"

#include "iterRange.h"

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
        int i1 = 0;

        for (auto i0 : ran)
        {
            REQUIRE(i0 == i1++);
        }

        REQUIRE(i1 == stop);
    }

    SECTION("std::size_t")
    {
        std::size_t const stop = 5;
        iter::detail::ranger<std::size_t> ran(stop);
        std::size_t i1 = 0;

        for (auto i0 : ran)
        {
            REQUIRE(i0 == i1++);
        }
        REQUIRE(i1 == stop);
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
            int i1 = start;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == i1);
                i1 += step;
            }
            REQUIRE(i1 == stop);
        }

        SECTION("backward")
        {
            int const start = -7;
            int const stop = -23;
            int const step = -2;
            iter::detail::ranger<int> ran(start, stop, step);
            int i1 = start;

            for (auto i0 : ran)
            {
                REQUIRE(i0 == i1);
                i1 += step;
            }
            REQUIRE(i1 == stop);
        }
    }
}