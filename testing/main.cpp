#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <sstream>
#include "players.hpp"
#include "game.hpp"
#include "cooks.hpp"
#include "config.hpp"

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

    SECTION("Ordering Fancy Food with more than enough money")
    {
        newPlayer.money = fancy_price + 1;
        char foodStyle = '1';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Fancy");
    }

    SECTION("Ordering Fancy Food with not enough money")
    {
        newPlayer.money = fancy_price - 1;
        char foodStyle = '1';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }

    SECTION("Ordering Fancy Food with just enough money")
    {
        newPlayer.money = fancy_price;
        char foodStyle = '1';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Fancy");
    }

    SECTION("Ordering Street Food")
    {
        char foodStyle = '2';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }

    SECTION("Ordering Gourmet with more than enough money")
    {
        newPlayer.money = gourmet_price + 1;
        char foodStyle = '3';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Gourmet");
    }

    SECTION("Ordering Gourmet with just enough money")
    {
        newPlayer.money = gourmet_price;
        char foodStyle = '3';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "Gourmet");
    }

    SECTION("Ordering Gourmet with not enough money")
    {
        newPlayer.money = gourmet_price - 1 ;
        char foodStyle = '3';
        std::istringstream input_stream(std::string(1, foodStyle));
        std::string result = showMenue2(&newPlayer, input_stream, output_stream);
        REQUIRE(result == "StreetFood");
    }
}
