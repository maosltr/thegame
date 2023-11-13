#pragma once
#include <vector>
#include "config.hpp"

using namespace std;

void startTheGame(std::vector<Player> players);
string offerFood();
char showMenue1(Player *player);
string showMenue2(Player *player, istream &input = cin, ostream &output = cout);
void callCook(Player *player, char kitchen, string foodStyle, Player *guest);