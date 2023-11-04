#include <string>
#include <vector>
#include <random>

using namespace std;

string pick_random(vector<string> list)
{
    string random_x;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, list.size() - 1);

    int randomIndex = dist(gen);
    random_x = list[randomIndex];

    return random_x;
};