#include <iostream>
#include <string>
using namespace std;
#include "cooks.hpp"
#include "players.hpp"
#include "utils.hpp"

#include <map>

// Constructor implementation
Cook::Cook(string kitchen, string foodStyle) : kitchen(kitchen), foodStyle(foodStyle)
{

    if (foodStyle == "StreetFood")
    {
        cout << "You ordered " << kitchen << " street food ... ";

        effects.push_back({"Diahrea", "All players have to move away from you 3 steps. If a player is in the same place, he goes to the hospital"});
        effects.push_back({"Farty", "The players behind you have to move back 3 steps"});
        effects.push_back({"Burpy", "The players ahead of you have to move ahead 3 steps"});
        effects.push_back({"Intoxicated", "Go to hospital. If you have been offered the food, the offerer goes to jail."});
        effects.push_back({"Sick", "Go to hospital and if the cook is among the players, he goes to jail"});
        effects.push_back({"Food Coma", "stay where you are and skip the next meal", 1});
        effects.push_back({"High and lost", "Switch place with a random player who will throw the lowest dice"});
        effects.push_back({"EXPLOSIVE Diahrea ", "Skip next round, and all players step away 5 steps, You go to jail, All people in jail go to the hospital", 1});
    }

    else if (foodStyle == "Gourmet")
    {
        cout << "You ordered " << kitchen << " gourmet ... ";

        effects.push_back({"In love", "move ahead 5 steps"});
        effects.push_back({"Amazed", "move ahead slowly 6 steps"});
        effects.push_back({"Crazy full", "move ahead 7 steps"});
        effects.push_back({"Still hungry", "Get street food at the next round"});
        effects.push_back({"Overwelmed by the flavors", "move ahead 9 steps"});
    }
    else

    {
        cout << "You ordered " << kitchen << " fancy food ... ";

        effects.push_back({"Happy", "move ahead 2 steps"});
        effects.push_back({"Full", "move ahead slowly 3 steps"});
        effects.push_back({"Energetic", "move ahead 4 steps"});
        effects.push_back({"Sleepy", "stay where you are for a little power nap"});
        effects.push_back({"Food Critic", "Stop critisizing and move back 1 step"});
    };
}

void Cook::cook(Player *player, Player *guest)
{
    // Define a map to store cooks and specialties for different cuisines and food styles
    std::map<std::pair<std::string, std::string>, std::pair<std::vector<std::string>, std::vector<std::string>>> data;

    // Populate the map with data
    data[{"Austrian", "Fancy"}] = {{"Kevin", "Franzi", "Anna", "Sophia"}, {"Schnitzel", "Cordon bleu", "Käsespätzle", "Germknödel"}};
    data[{"Austrian", "Gourmet"}] = {{"Sofia"}, {"Schnitzel au vin", "Schnitzel Bourguignon", "Schnitzel Suzette"}};
    data[{"Austrian", "StreetFood"}] = {{"Gaga", "Beni", "Andy", "Stefan"}, {"Wurst", "kebab knödel", "Leberkäsesemmel", "käsekrainer"}};

    data[{"Moroccan", "Fancy"}] = {{"Taha", "Soufiane", "Hamza", "Safaa"}, {"Tajine", "Couscous", "Rfissa", "Fish tajine"}};
    data[{"Moroccan", "Gourmet"}] = {{"Yasser"}, {"Lamb Tagine", "Zaalouk", "Seafood Bastilla", "Tanjia"}};
    data[{"Moroccan", "StreetFood"}] = {{"Faycal", "Aziz", "Mao", "Simo"}, {"Escargot", "Bissara", "Harcha kiri", "Mssemen", "Sfenj", "Harira"}};

    data[{"French", "Fancy"}] = {{"Victor", "Marine", "Magaux", "Theo"}, {"Raclette", "Tartiflette", "Croissant", "canard laqué"}};
    data[{"French", "Gourmet"}] = {{"Ange"}, {"Coq au Vin", "Escargot", "Bœuf Bourguignon", "Crêpes Suzette", "Tian de légumes du soleil"}};
    data[{"French", "StreetFood"}] = {{"Raph", "Marcus", "Salomé", "Tess"}, {"sandwish merguez", "Tacos de Lyon", "Crepe au beur salé", "... Shit it burned :("}};

    data[{"German", "Fancy"}] = {{"Eli", "Lena", "Inky", "Ralph", "Selina"}, {"Vegan toast", "Avocado toast", "gluten free musli", "lactos free pumkin soup"}};
    data[{"German", "Gourmet"}] = {{"Arne"}, {"Sauerbraten", "Trout Meunière", "Veal Rouladen", "Black Forest Cake"}};
    data[{"German", "StreetFood"}] = {{"Christel", "Jürgen", "Flo", "Micky"}, {"kebab", "bred with onions", "curry wurst", "... Shit it burned :("}};

    data[{"Indian", "Fancy"}] = {{"Sanjeev", "Meenakshi", "Rahul", "Anjali"}, {"Butter Chicken", "Biryani", "Paneer Tikka", "Masala Dosa"}};
    data[{"Indian", "Gourmet"}] = {{"Priya"}, {"Lobster Malai Curry", "Tandoori Quail", "Paneer Makhani", "Kesar Pista Kulfi"}};
    data[{"Indian", "StreetFood"}] = {{"Raj", "Priya", "Amit", "Meera"}, {"Samosa", "Pani Puri", "Vada Pav", "... Shit it burned :("}};

    // Extract the cook names and specialties based on the provided cuisine and food style
    auto it = data.find({kitchen, foodStyle});
    if (it != data.end())
    {
        const std::vector<std::string> &names = it->second.first;
        const std::vector<std::string> &specialities = it->second.second;

        // Randomly select a cook and a specialty
        cookName = pick_random(names);

        if (cookName == "Marcus")
        {

            speciality = "Pasta Pesto";
        }
        else
        {
            speciality = pick_random(specialities);
        }

        // Effect of the food
        std::cout << "Allo " << cookName << " !!!\n\n";
        std::cout << cookName << " made " << speciality << " 😋\n\n";

        std::cout << "Player: " << player->name << "\n\n";
        std::cout << "Cook: " << cookName << "\n";
        std::cout << "Dish: " << speciality << "\n";

        // pick a random effect
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, effects.size() - 1);
        int randomIndex = dist(gen);
        Effect effect = effects[randomIndex]; // Assuming 'effects' is defined somewhere

        // check if the effect skips the turn

        std::cout << "Guest: " << guest->name << "\n";
        std::cout << "Effect: " << effect.name << "\n";
        std::cout << "Action: " << effect.description << "\n\n";
        if (effect.skip == 1)
        {
            guest->skipNextRound++;

            std::cout << guest->name << " skips next round !!!"
                      << "\n\n";
        }
    }
};