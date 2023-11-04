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
   Player *player;

   players = setup_players();
   numberOfPlayers = start_the_game(players);

   while (true)
   {

      player = &players[player_turn]; // pointer to the memory address of the actual player

      if (player->skipNextRound > 0)
      {

         player->skipNextRound = 0;
         cout << "****** " << player->name << " Skip your turn ******\n\n";
      }
      else
      {
         cout << "****** " << player->name << " ******\n\n";
         std::string option1 = showMenue1(player);
         std::string option2 = showMenue2(player);

         callCook(player, option1, option2);
      }

      player_turn = (player_turn + 1) % numberOfPlayers;

      game_ended++;
   }

   return 0;
}