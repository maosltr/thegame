#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "players.hpp"

TEST_CASE("Setup Players is working as expected", ["Setup Players"])
{
    REQUIRE(setup_players(0).size() == 0);
    REQUIRE(setup_players(1).size() == 1);
    REQUIRE(setup_players(2).size() == 2);
}