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

/**
 * @brief Starts The Game
 *
 * @param players: Vector of players objects
 * @return Number of players
 */
int startTheGame(vector<Player> players)
{

    system("clear");
    cout << "****** The Game have started ******" << endl;
    numPlayers = players.size();
    cout << "Number of players: " << numPlayers << endl;
    cin;
    system("clear");

    return numPlayers;
}

string showMenue1(Player *player)
{

    system("clear");
    cout << "****** " << player->name << " ******\n\n";
    cout << "What do you want to eat today?\n";
    cout << "Credit: " << player->money << "$ \n\n";

    cout << "********MENU*********\n";
    cout << "1. Austrian\n";
    cout << "2. Moroccan\n";
    cout << "3. French\n";
    cout << "4. German\n";
    cout << "5. Indian\n";
    cout << "*********************\n\n";
    cout << "NB: You can either order for yourself, or offer the meal\n\n";

    cin >> option1;
    system("clear");

    return option1;
};

string showMenue2(Player *player)
{

    cout << "What kind of food?\n\n";
    cout << "1. Fancy\n";
    cout << "2. Street Food\n";
    cout << "3. Gourmet\n";

    cout << "*********************\n\n";
    cin >> option2;
    system("clear");

    if ((player->money < 1 && option2 == "1") || (player->money < 2 && option2 == "3"))
    {
        cout << "BRO, you are broke, let's go for street food \n\n";
        return "StreetFood";
    }
    else if (option2 == "2")
    {
        cout << "I know the best street food in town, wallah \n\n";
        return "StreetFood";
    }
    else if (player->money > 0 && option2 == "1")
    {
        cout << "I know a cool super hiped restaurant, follow me, trust me ... \n\n";
        player->money--;
        return "Fancy";
    }
    else if (player->money > 2 && option2 == "3")
    {
        cout << "Très bon choix cher ami ... \n\n";
        player->money -= 2;
        return "Gourmet";
    }
    else
    {
        return "StreetFood";
    }
};

void callCook(Player *player, string kitchen, string foodStyle)
{
    if (kitchen == "1")
    {
        Cook cook("Austrian", foodStyle);
        cook.cook(player);
    }
    else if (kitchen == "2")
    {
        Cook cook("Moroccan", foodStyle);
        cook.cook(player);
    }
    else if (kitchen == "3")
    {
        Cook cook("French", foodStyle);
        cook.cook(player);
    }
    else if (kitchen == "4")
    {
        Cook cook("German", foodStyle);
        cook.cook(player);
    }
    else if (kitchen == "5")
    {
        Cook cook("Indian", foodStyle);
        cook.cook(player);
    }
    else
    {
        cout << " ... But you are too drunk to choose properly, maybe you need to wait for the next meal !!!" << endl;
    }

    // implement game actions
    string continue_game;
    cout << "\nPress any key to continue ";
    cin >> continue_game;
    system("clear");
};