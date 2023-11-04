#pragma once
#include <vector>

int start_the_game(std::vector<Player> players);
void play(Player *player);

string showMenue1(Player *player);
string showMenue2(Player *player);
void callCook(Player *player, string option, string foodStyle);