#include "catch/catch.hpp"

#include "iterRange.h"

#include <cstddef>


TEST_CASE("ctor", "[iter][detail][iterator][ctor]")
{
    SECTION("int")
    {
        int const start = 3;
        int const stop = 5;
        int const step = 1;
        iter::detail::ranger<int>::iterator it(start, stop, step);
        
        REQUIRE(*it == start);
    }

    SECTION("std::size_t")
    {
        std::size_t const start = 3;
        std::size_t const stop = 5;
        std::size_t const step = 1;
        iter::detail::ranger<std::size_t>::iterator it(start, stop, step);

        REQUIRE(*it == start);
    }
}

TEST_CASE("neq", "[iter][detail][iterator][neq]")
{
    SECTION("int")
    {
        int const start1 = 3;
        int const start2 = 7;
        int const stop1 = 9;
        int const step1 = 1;
        int const step2 = 2;
        iter::detail::ranger<int>::iterator it11a(start1, stop1, step1);
        iter::detail::ranger<int>::iterator it11b(start1, stop1, step1);
        iter::detail::ranger<int>::iterator it12(start1, stop1, step2);
        iter::detail::ranger<int>::iterator it21(start2, stop1, step1);
        iter::detail::ranger<int>::iterator it22(start2, stop1, step2);

        REQUIRE(!(it11a != it11b));
        REQUIRE(!(it11a != it12));
        REQUIRE(it11a != it21);
        REQUIRE(it11a != it22);
    }

    SECTION("std::size_t")
    {
        std::size_t const start1 = 3;
        std::size_t const start2 = 7;
        std::size_t const stop1 = 9;
        std::size_t const step1 = 1;
        std::size_t const step2 = 2;
        iter::detail::ranger<std::size_t>::iterator it11a(start1, stop1, step1);
        iter::detail::ranger<std::size_t>::iterator it11b(start1, stop1, step1);
        iter::detail::ranger<std::size_t>::iterator it12(start1, stop1, step2);
        iter::detail::ranger<std::size_t>::iterator it21(start2, stop1, step1);
        iter::detail::ranger<std::size_t>::iterator it22(start2, stop1, step2);

        REQUIRE(!(it11a != it11b));
        REQUIRE(!(it11a != it12));
        REQUIRE(it11a != it21);
        REQUIRE(it11a != it22);
    }
}

TEST_CASE("deref", "[iter][detail][iterator][deref]")
{
    SECTION("int")
    {
        int const start = 3;
        int const stop = 5;
        int const step = 1;
        iter::detail::ranger<int>::iterator it(start, stop, step);

        REQUIRE(*it == start);
    }

    SECTION("std::size_t")
    {
        std::size_t const start = 3;
        std::size_t const stop = 5;
        std::size_t const step = 1;
        iter::detail::ranger<std::size_t>::iterator it(start, stop, step);

        REQUIRE(*it == start);
    }
}

TEST_CASE("oper++", "[iter][detail][iterator][oper++]")
{
    SECTION("int")
    {
        int const start1 = 0;
        int const stop1 = 5;
        int const stop2 = -5;
        int const step1 = 0;
        int const step2 = 1;
        int const step3 = -1;
        iter::detail::ranger<int>::iterator it11(start1, stop1, step1);
        iter::detail::ranger<int>::iterator it12(start1, stop1, step2);
        iter::detail::ranger<int>::iterator it13(start1, stop2, step3);

        REQUIRE(*++it11 == start1 + step1);
        REQUIRE(*++it12 == start1 + step2);
        REQUIRE(*++it13 == start1 + step3);
    }

    SECTION("std::size_t")
    {
        std::size_t const start1 = 0;
        std::size_t const stop1 = 5;
        std::size_t const stop2 = -5;
        std::size_t const step1 = 0;
        std::size_t const step2 = 1;
        std::size_t const step3 = -1;
        iter::detail::ranger<std::size_t>::iterator it11(start1, stop1, step1);
        iter::detail::ranger<std::size_t>::iterator it12(start1, stop1, step2);
        iter::detail::ranger<std::size_t>::iterator it13(start1, stop2, step3);

        REQUIRE(*++it11 == start1 + step1);
        REQUIRE(*++it12 == start1 + step2);
        REQUIRE(*++it13 == start1 + step3);
    }

    SECTION("char")
    {
        char const start1 = 'j';
        char const stop1 = 'o';
        char const stop2 = -5;
        char const step1 = 0;
        char const step2 = 1;
        char const step3 = -1;
        iter::detail::ranger<char>::iterator it11(start1, stop1, step1);
        iter::detail::ranger<char>::iterator it12(start1, stop1, step2);
        iter::detail::ranger<char>::iterator it13(start1, stop2, step3);

        REQUIRE(*++it11 == start1 + step1);
        REQUIRE(*++it12 == start1 + step2);
        REQUIRE(*++it13 == start1 + step3);
    }
}
