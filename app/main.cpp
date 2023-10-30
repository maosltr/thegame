#include <iostream>
#include <vector>

#include <players.hpp>
#include <game.hpp>

using namespace std;

int main()
{
   std::vector<std::string> players;
   int numberOfPlayers;
   int game_ended = 0;
   int player_turn = 0;
   string player;

   players = setup_players();
   numberOfPlayers = start_the_game(players);

   while (true)
   {

      player = players[player_turn];
      play(player);

      player_turn = (player_turn + 1) % numberOfPlayers;

      game_ended++;
   };

   return 0;
}