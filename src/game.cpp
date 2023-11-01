#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
#include "cooks.hpp"
using namespace std;

int start_the_game(std::vector<Player> players)
{
    int numPlayers;

    system("clear");
    std::cout << "****** The Game have started ******" << endl;

    numPlayers = players.size();
    cout << "Number of players: " << numPlayers << endl;
    std::cin;

    return numPlayers;
}

void play(Player *player)
{

    string option;
    string option2;
    int streetFood = 1;
    system("clear");
    cout << "****** " << player->name << " ******\n\n";

    cout << "What do you want to eat today?\n";
    cout << "Credit: " << player->money << "$ \n\n";

    std::cout << "********MENU*********\n";
    std::cout << "1. Austrian\n";
    std::cout << "2. Moroccan\n";
    std::cout << "3. French\n";
    std::cout << "4. German\n";
    std::cout << "5. Indian\n";
    std::cout << "*********************\n\n";

    std::cin >> option;

    system("clear");

    cout << "What kind of food?\n\n";
    std::cout << "1. Fancy\n";
    std::cout << "2. Street Food\n";
    std::cout << "*********************\n\n";
    std::cin >> option2;
    system("clear");

    if (player->money < 1 && option2 == "1")
    {
        std::cout << "BRO, you are broke, let's go for street food \n\n";
        streetFood = 1;
    }

    if (option2 == "2")
    {
        std::cout << "I know the best street food in town, wallah \n\n";
        streetFood = 1;
    }

    if (player->money > 0 && option2 == "1")
    {
        std::cout << "I know a cool super hiped restaurant, follow me, trust me ... \n\n";
        player->money--;
        streetFood = 0;
    }

    if (option == "1")
    {
        Cook cook("Austrian", streetFood);
        cook.cook();
    }
    else if (option == "2")
    {
        Cook cook("Moroccan", streetFood);
        cook.cook();
    }
    else if (option == "3")
    {
        Cook cook("French", streetFood);
        cook.cook();
    }
    else if (option == "4")
    {
        Cook cook("German", streetFood);
        cook.cook();
    }
    else if (option == "5")
    {
        Cook cook("Indian", streetFood);
        cook.cook();
    }
    else
    {
        std::cout << " ... But you are too drunk to choose properly, maybe you need to wait for the next meal !!!" << std::endl;
    }

    // implement game actions
    string continue_game;
    std::cout << "\nPress any key to continue ";
    std::cin >> continue_game;
};
