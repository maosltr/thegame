#pragma once
#include <vector>

using namespace std;

void startTheGame(std::vector<Player> players);
string showMenue1(Player *player);
string showMenue2(Player *player, istream &input = cin, ostream &output = cout);
void callCook(Player *player, string kitchen, string foodStyle);