#include <iostream>
#include <vector>

#include <players.hpp>
#include <game.hpp>

using namespace std;

/**
 * @brief Main entry point of The Game
 *
 * @return int
 */
int main()
{
   std::vector<Player> players;
   int numberOfPlayers;
   int game_ended = 0;
   int player_turn = 0;
   Player *player;
   string InvitedPlayer;

   system("clear");
   cout << "****** Setup Players ******\n\n";
   cout << "Enter the number of players: ";
   cin >> numberOfPlayers;

   players = setup_players(numberOfPlayers);
   startTheGame(players);

   while (true)

   {

      player = &players[player_turn]; // pointer to the memory address of the actual player
      Player *guest;
      if (player->skipNextRound > 0)
      {

         player->skipNextRound--;
         cout << "****** " << player->name << " Skip your turn ******\n\n";
         string continue_game;
      }
      else
      {
         cout << "****** " << player->name << " ******\n\n";
         cout << "Credit: " << player->money << "$ \n\n";

         guest = offerFood(&players);
         char option1 = showMenue1(player);
         std::string option2 = showMenue2(player);

         callCook(player, option1, option2, guest);
      }

      player_turn = (player_turn + 1) % numberOfPlayers;

      game_ended++;
      guest = nullptr;

      // Continue
      string continue_game;
      cout << "\nPress any key to continue ";
      cin >> continue_game;
      system("clear");
   }

   return 0;
}