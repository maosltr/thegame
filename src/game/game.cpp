#include <iostream>
#include <limits> // For numeric_limits

#include <string>
#include <vector>
#include "players.hpp"
#include "cooks.hpp"

using namespace std;

int numPlayers;
int foodStyle;

/**
 * @brief Starts The Game
 *
 * @param players: Vector of players objects
 * @return Number of players
 */
void startTheGame(vector<Player> players)
{

    system("clear");
    cout << "****** The Game have started ******" << endl;
    numPlayers = players.size();
    cout << "Number of players: " << numPlayers << endl;
    cin;
    system("clear");
}

Player *offerFood(vector<Player> *players)
{

    cout << "Who do you want to invite for dinner? \n\n";

    for (int i = 0; i < players->size(); i++)
    {
        cout << i + 1 << " - " << (*players)[i].name << "\n";
    }
    int index;

    while (true)
    {
        cout << "\nEnter the number corresponding to the player: ";
        if (cin >> index)
        {
            if (index >= 1 && index <= players->size())
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the input buffer
                return &((*players)[index - 1]);
            }
            else
            {
                cout << "Invalid index. Please enter a number within range." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();                                         // Clearing error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clearing the input buffer
        }
    }
}

char showMenue1(Player *player)
{

    system("clear");
    cout << "****** " << player->name << " ******\n\n";
    cout << "What do you want to order today?\n";
    cout << "Credit: " << player->money << "$ \n\n";

    cout << "****** MENU ******\n";
    cout << "1. Austrian\n";
    cout << "2. Moroccan\n";
    cout << "3. French\n";
    cout << "4. German\n";
    cout << "5. Indian\n";
    cout << "******************\n\n";

    char option;
    cin >> option;
    system("clear");

    return option;
};

string showMenue2(Player *player, istream &input, ostream &output)
{

    cout << "What kind of food?\n\n";
    cout << "****** MENU ******\n";
    cout << "1. Fancy (" << fancy_price << " $)\n";
    cout << "2. Street Food (0 $)\n";
    cout << "3. Gourmet (" << gourmet_price << " $)\n";
    cout << "******************\n\n";
    char option;
    input >> option;
    system("clear");

    if ((player->money < fancy_price && option == '1') || (player->money < gourmet_price && option == '3'))
    {
        cout << "BRO, you are broke, let's go for street food \n\n";
        return "StreetFood";
    }
    else if (option == '2')
    {
        cout << "I know the best street food in town, wallah \n\n";
        return "StreetFood";
    }
    else if (player->money >= fancy_price && option == '1')
    {
        cout << "I know a cool super hiped restaurant, follow me, trust me ... \n\n";
        player->money -= fancy_price;
        return "Fancy";
    }
    else if (player->money >= gourmet_price && option == '3')
    {
        cout << "Très bon choix cher ami ... \n\n";
        player->money -= gourmet_price;
        return "Gourmet";
    }
    else
    {
        return "StreetFood";
    }
};

void callCook(Player *player, char kitchen, string foodStyle, Player *guest)
{
    if (kitchen == '1')
    {
        Cook cook("Austrian", foodStyle);
        cook.cook(player, guest);
    }
    else if (kitchen == '2')
    {
        Cook cook("Moroccan", foodStyle);
        cook.cook(player, guest);
    }
    else if (kitchen == '3')
    {
        Cook cook("French", foodStyle);
        cook.cook(player, guest);
    }
    else if (kitchen == '4')
    {
        Cook cook("German", foodStyle);
        cook.cook(player, guest);
    }
    else if (kitchen == '5')
    {
        Cook cook("Indian", foodStyle);
        cook.cook(player, guest);
    }
    else
    {
        cout << " ... But you are too drunk to choose properly, maybe you need to wait for the next meal !!!" << endl;
    }
};