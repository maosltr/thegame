#pragma once
#include <vector>
#include "config.hpp"
using namespace std;

class Player
{

public:
    Player(string playerName) : name(playerName), money(initial_money)
    {
        cout << "Nice name !" << endl;
    }

    string name;
    int money;
    int skipNextRound;
    void play();
};

std::vector<Player> setup_players(int numberOfPlayers, istream &input = cin, ostream &output = cout);
