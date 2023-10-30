#include <iostream>
#include <string>
#include <vector>

using namespace std;

int start_the_game(std::vector<std::string> players)
{
    int numPlayers;

    system("clear");
    std::cout << "****** The Game have started ******" << endl;

    numPlayers = players.size();
    cout << "Number of players: " << numPlayers << endl;
    std::cin;

    return numPlayers;
}

void play(std::string player)
{

    int option;
    system("clear");
    cout << "****** " << player << " ******\n\n";

    cout << "What do you want to eat today? \n\n";

    std::cout << "********MENU*********\n";
    std::cout << "1. Austrian\n";
    std::cout << "2. Moroccan\n";
    std::cout << "3. French\n";
    std::cout << "4. German\n";
    std::cout << "5. Indian\n";
    std::cout << "*********************\n\n";

    std::cin >> option;
};
