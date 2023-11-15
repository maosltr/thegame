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
   Player *guest = nullptr;

   system("clear");
   cout << "****** Setup Players ******\n";
   cout << "Enter the number of players: ";
   cin >> numberOfPlayers;

   players = setup_players(numberOfPlayers);
   startTheGame(players);

   while (true)

   {

      player = &players[player_turn]; // pointer to the memory address of the actual player

      if (player->skipNextRound > 0)
      {

         player->skipNextRound = 0;
         cout << "****** " << player->name << " Skip your turn ******\n\n";
         string continue_game;
         std::cout << "\nPress any key to continue ";
         std::cin >> continue_game;
         system("clear");
      }
      else
      {
         cout << "****** " << player->name << " ******\n\n";
         cout << "Credit: " << player->money << "$ \n\n";

         InvitedPlayer = offerFood();
         char option1 = showMenue1(player);
         std::string option2 = showMenue2(player);

         // Find who is the invited player
         for (int i = 0; i < numberOfPlayers; i++)
         {
            if (players[i].name == InvitedPlayer)
            {
               guest = &players[i];
            }
         }
         callCook(player, option1, option2, guest);
      }

      player_turn = (player_turn + 1) % numberOfPlayers;

      game_ended++;

      // Continue
      string continue_game;
      cout << "\nPress any key to continue ";
      cin >> continue_game;
      system("clear");
   }

   return 0;
}