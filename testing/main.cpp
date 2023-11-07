#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sstream>
#include "players.hpp"
#include "game.hpp"
#include "cooks.hpp"

TEST_CASE("Test that Setup Players is working as expected")
{
    SECTION("Creating 1 player")
    {
        std::istringstream input_stream("Marouane\n");
        std::ostringstream output_stream;
        std::vector<Player> players = setup_players(1, input_stream, output_stream);
        REQUIRE(players.size() == 1);
        REQUIRE(players[0].name == "Marouane");
    }

    SECTION("Creating 2 players")
    {
        std::istringstream input_stream("Marouane\nElisa\n");
        std::ostringstream output_stream;
        std::vector<Player> players = setup_players(2, input_stream, output_stream);
        REQUIRE(players.size() == 2);
        REQUIRE(players[0].name == "Marouane");
        REQUIRE(players[1].name == "Elisa");
    }
}

TEST_CASE("Test foodStyle")
{
    Player newPlayer("Marouane");
    newPlayer.skipNextRound = 0;
    std::ostringstream output_stream;

    SECTION("Test 1 Ordering Fancy Food")
    {
        newPlayer.money = 1;
        std::istringstream input_stream("1\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Fancy");
    }

    SECTION("Test 2 Ordering Fancy Food")
    {
        newPlayer.money = 0;
        std::istringstream input_stream("1\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }

    SECTION("Test 3 Ordering Street Food")
    {
        std::istringstream input_stream("2\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }

    SECTION("Test 4 Ordering Gourmet")
    {
        newPlayer.money = 2;
        std::istringstream input_stream("3\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Gourmet");
    }

    SECTION("Test 5 Ordering Gourmet with not enough money")
    {
        newPlayer.money = 1;
        std::istringstream input_stream("3\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }
}
