#pragma once
#include <vector>
#include "config.hpp"

using namespace std;

void startTheGame(std::vector<Player> players);
Player *offerFood(vector<Player> *);
char showMenue1(Player *player);
string showMenue2(Player *player, istream &input = cin, ostream &output = cout);
void callCook(Player *player, char kitchen, string foodStyle, Player *guest);