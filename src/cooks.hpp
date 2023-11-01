#pragma once
using namespace std;
#include <random>

class Cook
{
public:
    // Constructor
    Cook(string type, int foodStyle);

    // Functions
    string pick_random(vector<string> names);
    void cook();

    // Variables
    vector<string> names;
    vector<string> specialities;
    vector<string> effects;
    string name;
    string speciality;
    int foodStyle;
    string type;
    string effect;
};
