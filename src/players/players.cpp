#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> setup_players()
{
    int numberOfPlayers;
    int numberOfPlayersCounter = 0;
    std::vector<std::string> players;

    system("clear");
    std::cout << "****** Setup Players ******\n";
    std::cout << "Enter the number of players: ";
    std::cin >> numberOfPlayers;

    do
    {
        std::string playerName;
        std::cout << "Name of player " << numberOfPlayersCounter + 1 << ": ";
        std::cin >> playerName;
        players.push_back(playerName);
        numberOfPlayersCounter++;

    } while (numberOfPlayersCounter < numberOfPlayers);

    return players;
}
