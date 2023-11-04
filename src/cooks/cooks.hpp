#pragma once
using namespace std;
#include <random>
#include "players.hpp"

class Cook
{
public:
    // Constructor
    Cook(string kitchen, string foodStyle);

    // Functions
    string pick_random(vector<string> names);
    void cook(Player *player);

    // Variables
    vector<string> names;
    vector<string> specialities;
    vector<string> effects;
    string cookName;
    string speciality;
    string foodStyle;
    string kitchen;
    string effect;
};
