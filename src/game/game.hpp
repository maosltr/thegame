#pragma once
#include <vector>

using namespace std;

int startTheGame(std::vector<Player> players);
string showMenue1(Player *player);
string showMenue2(Player *player);
void callCook(Player *player, string kitchen, string foodStyle);