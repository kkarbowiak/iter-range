#include "catch/catch.hpp"

#include "iterRange.h"

#include <cstddef>


TEST_CASE("ctor", "[iter][detail][itr][ctor]")
{
    SECTION("int")
    {
        int const value = 3;
        int const step = 1;
        iter::detail::itr<int> it(value, step);
        
        REQUIRE(*it == value);
    }

    SECTION("std::size_t")
    {
        std::size_t const value = 3;
        std::size_t const step = 1;
        iter::detail::itr<std::size_t> it(value, step);

        REQUIRE(*it == value);
    }
}

TEST_CASE("neq", "[iter][detail][itr][neq]")
{
    SECTION("int")
    {
        int const value1 = 3;
        int const value2 = 7;
        int const step1 = 1;
        int const step2 = 2;
        iter::detail::itr<int> it11a(value1, step1);
        iter::detail::itr<int> it11b(value1, step1);
        iter::detail::itr<int> it12(value1, step2);
        iter::detail::itr<int> it21(value2, step1);
        iter::detail::itr<int> it22(value2, step2);

        REQUIRE(!(it11a != it11b));
        REQUIRE(!(it11a != it12));
        REQUIRE(it11a != it21);
        REQUIRE(it11a != it22);
    }

    SECTION("std::size_t")
    {
        std::size_t const value1 = 3;
        std::size_t const value2 = 7;
        std::size_t const step1 = 1;
        std::size_t const step2 = 2;
        iter::detail::itr<std::size_t> it11a(value1, step1);
        iter::detail::itr<std::size_t> it11b(value1, step1);
        iter::detail::itr<std::size_t> it12(value1, step2);
        iter::detail::itr<std::size_t> it21(value2, step1);
        iter::detail::itr<std::size_t> it22(value2, step2);

        REQUIRE(!(it11a != it11b));
        REQUIRE(!(it11a != it12));
        REQUIRE(it11a != it21);
        REQUIRE(it11a != it22);
    }
}

TEST_CASE("deref", "[iter][detail][itr][deref]")
{
    SECTION("int")
    {
        int const value = 3;
        int const step = 1;
        iter::detail::itr<int> it(value, step);

        REQUIRE(*it == value);
    }

    SECTION("std::size_t")
    {
        std::size_t const value = 3;
        std::size_t const step = 1;
        iter::detail::itr<std::size_t> it(value, step);

        REQUIRE(*it == value);
    }
}

TEST_CASE("oper++", "[iter][detail][itr][oper++]")
{
    SECTION("int")
    {
        int const value1 = 0;
        int const step1 = 0;
        int const step2 = 1;
        int const step3 = -1;
        iter::detail::itr<int> it11(value1, step1);
        iter::detail::itr<int> it12(value1, step2);
        iter::detail::itr<int> it13(value1, step3);

        REQUIRE(*++it11 == value1 + step1);
        REQUIRE(*++it12 == value1 + step2);
        REQUIRE(*++it13 == value1 + step3);
    }

    SECTION("std::size_t")
    {
        std::size_t const value1 = 0;
        std::size_t const step1 = 0;
        std::size_t const step2 = 1;
        std::size_t const step3 = -1;
        iter::detail::itr<std::size_t> it11(value1, step1);
        iter::detail::itr<std::size_t> it12(value1, step2);
        iter::detail::itr<std::size_t> it13(value1, step3);

        REQUIRE(*++it11 == value1 + step1);
        REQUIRE(*++it12 == value1 + step2);
        REQUIRE(*++it13 == value1 + step3);
    }
}
