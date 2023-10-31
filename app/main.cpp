#include <iostream>
#include <vector>

#include <players.hpp>
#include <game.hpp>

using namespace std;

int main()
{
   std::vector<Player> players;
   int numberOfPlayers;
   int game_ended = 0;
   int player_turn = 0;

   players = setup_players();
   numberOfPlayers = start_the_game(players);

   while (true)
   {

      play(&players[player_turn]);

      player_turn = (player_turn + 1) % numberOfPlayers;

      game_ended++;
   };

   return 0;
}