#pragma once
using namespace std;

#include "players.hpp"

class Cook
{
public:
    // Constructor
    Cook(string kitchen, string foodStyle);

    // Functions
    void cook(Player *player, Player *guest);

    // Variables
    vector<string> names;
    vector<string> specialities;
    string cookName;
    string speciality;
    string foodStyle;
    string kitchen;

    struct Effect
    {
        std::string name;
        std::string description;
        bool skip;
    };

    std::vector<Effect> effects;
};
