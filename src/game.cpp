#include <iostream>
#include <string>
#include <vector>
#include "players.hpp"
#include "cooks.hpp"
using namespace std;

int numPlayers;
string option1;
string option2;
int foodStyle;

int start_the_game(std::vector<Player> players)
{

    system("clear");
    std::cout << "****** The Game have started ******" << endl;

    numPlayers = players.size();
    cout << "Number of players: " << numPlayers << endl;
    std::cin;

    return numPlayers;
}

string showMenue1(Player *player)
{

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

    std::cin >> option1;
    return option1;
};

string showMenue2(string option1)
{

    system("clear");

    cout << "What kind of food?\n\n";
    std::cout << "1. Fancy\n";
    std::cout << "2. Street Food\n";
    if (option1 == "3")
    {
        std::cout << "3. Gourmet\n";
    };
    std::cout << "*********************\n\n";
    std::cin >> option2;
    return option2;
};

int streetFood(Player *player, string option2)
{

    system("clear");

    if ((player->money < 1 && option2 == "1") || (player->money < 2 && option2 == "3"))
    {
        std::cout << "BRO, you are broke, let's go for street food \n\n";
        foodStyle = 1;
    }

    else if (option2 == "2")
    {
        std::cout << "I know the best street food in town, wallah \n\n";
        foodStyle = 1;
    }

    else if (player->money > 0 && option2 == "1")
    {
        std::cout << "I know a cool super hiped restaurant, follow me, trust me ... \n\n";
        player->money--;
        foodStyle = 0;
    }
    else if (player->money > 2 && option2 == "3")
    {
        std::cout << "Très bon choix cher ami ... \n\n";
        player->money--;
        player->money--;
        foodStyle = 2;
    }
    else
    {
        foodStyle = 1;
    }

    return foodStyle;
};

void callCook(string option, int foodStyle)
{
    if (option == "1")
    {
        Cook cook("Austrian", foodStyle);
        cook.cook();
    }
    else if (option == "2")
    {
        Cook cook("Moroccan", foodStyle);
        cook.cook();
    }
    else if (option == "3")
    {
        Cook cook("French", foodStyle);
        cook.cook();
    }
    else if (option == "4")
    {
        Cook cook("German", foodStyle);
        cook.cook();
    }
    else if (option == "5")
    {
        Cook cook("Indian", foodStyle);
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

void play(Player *player)
{

    string option1;
    string option2;
    int foodStyle;

    option1 = showMenue1(player);
    option2 = showMenue2(option1);
    foodStyle = streetFood(player, option2);
    callCook(option1, foodStyle);
};
