#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
using namespace std;

std::vector<Player> setup_players(int numberOfPlayers)
{
    const int INITIAL_SKIP_COUNT = 0;

    int numberOfPlayersCounter = 0;

    std::vector<Player> players;

    while (numberOfPlayersCounter < numberOfPlayers)
    {
        string playerName;
        cout << "Name of player " << numberOfPlayersCounter + 1 << ": ";
        cin >> playerName;

        Player newPlayer(playerName);
        newPlayer.skipNextRound = INITIAL_SKIP_COUNT;
        players.push_back(newPlayer);
        numberOfPlayersCounter++;
    };

    return players;
}