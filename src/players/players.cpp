#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
using namespace std;

std::vector<Player> setup_players(int numberOfPlayers, istream &input, ostream &output)
{
    const int INITIAL_SKIP_COUNT = 0;

    int numberOfPlayersCounter = 0;

    std::vector<Player> players;

    while (numberOfPlayersCounter < numberOfPlayers)
    {

        cout << "\nName of player " << numberOfPlayersCounter + 1 << ": ";
        string playerName;
        input >> playerName;

        Player newPlayer(playerName);
        newPlayer.skipNextRound = INITIAL_SKIP_COUNT;
        players.push_back(newPlayer);
        numberOfPlayersCounter++;
    };

    return players;
}