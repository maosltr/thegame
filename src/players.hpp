#pragma once
#include <vector>
using namespace std;

class Player
{

public:
    Player(string playerName) : name(playerName), money(3) // Initialize name and money
    {
        cout << "Constructor" << endl;
    }

    string name; // Declare name and money here
    int money;

    void play();
};

std::vector<Player> setup_players();