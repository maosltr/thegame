#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
using namespace std;

std::vector<Player> setup_players()
{
    const int INITIAL_SKIP_COUNT = 0;

    int numberOfPlayers;
    int numberOfPlayersCounter = 0;

    std::vector<Player> players;

    system("clear");
    cout << "****** Setup Players ******\n";
    cout << "Enter the number of players: ";
    cin >> numberOfPlayers;

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
