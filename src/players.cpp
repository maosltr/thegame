#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
using namespace std;

std::vector<Player> setup_players()
{
    int numberOfPlayers;
    int numberOfPlayersCounter = 0;
    std::vector<Player> players;

    system("clear");
    std::cout << "****** Setup Players ******\n";
    std::cout << "Enter the number of players: ";
    std::cin >> numberOfPlayers;

    do
    {
        std::string playerName;
        std::cout << "Name of player " << numberOfPlayersCounter + 1 << ": ";
        std::cin >> playerName;
        Player new_player(playerName);
        new_player.skipNextRound++;
        players.push_back(new_player);
        numberOfPlayersCounter++;

    } while (numberOfPlayersCounter < numberOfPlayers);

    return players;
}
