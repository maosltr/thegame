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

    SECTION("Option 1 Ordering Fancy Food")
    {
        std::istringstream input_stream("1\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Fancy");
    }

    SECTION("Option 2 Ordering Street Food")
    {
        std::istringstream input_stream("2\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }

    SECTION("Option 3 Ordering Gourmet")
    {
        std::istringstream input_stream("3\n");
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Gourmet");
    }
}
