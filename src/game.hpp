#pragma once
#include <vector>

int start_the_game(std::vector<Player> players);
void play(Player *player);

string showMenue1(Player *player);
string showMenue2(string option1);
int streetFood(Player *player, string option2);
void callCook(string option, int foodStyle);