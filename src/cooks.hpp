#pragma once
using namespace std;
#include <random>

class Cook
{
public:
    string name;
    int streetFood;
    string type;
    string speciality;

public:
    Cook(string type, int streetFood) : type(type), streetFood(streetFood) {}
    string pick_random(vector<string> names);
    void cook();
};
