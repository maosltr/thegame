#pragma once
#include <vector>
using namespace std;

class Player
{

public:
    Player(string playerName) : name(playerName), money(10)
    {
        cout << "Nice name !" << endl;
    }

    string name;
    int money;
    int skipNextRound;
    void play();
};

std::vector<Player> setup_players();