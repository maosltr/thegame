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

        effects.push_back("Diahrea ... All players have to move away from you 5 steps. If a player is in the same place, he goes to the hospital");
        effects.push_back("Farty ... The players after you have to move back 3 steps");
        effects.push_back("Burpy ... The players ahead have to move ahead 3 steps");
        effects.push_back("Intoxicated ... Go to hospital or to jail if you have offered the food");
        effects.push_back("Sick ... Go to hospital and if the cook is among the players, he goes to jail");
        effects.push_back("Food Coma ... stay where you are and skip the next meal");
        effects.push_back("High and lost ... Switch place with a random player who will throw the lowest dice");
        effects.push_back("Super farty ... You go to jail, skip next round, and all players step back 2 steps");
    }
    else if (foodStyle == "Gourmet")
    {
        cout << "You ordered " << kitchen << " gourmet ... ";

        effects.push_back("In love ... move ahead 5 steps");
        effects.push_back("Amazed ... move ahead slowly 6 steps");
        effects.push_back("Crazy full ... move ahead 7 steps");
        effects.push_back("Still hungry ... Get street food at the next round");
        effects.push_back("Overwelmed by the flavors ... move ahead 9 steps");
    }
    else

    {
        cout << "You ordered " << kitchen << " fancy food ... ";

        effects.push_back("Happy ... move ahead 2 steps");
        effects.push_back("Full ... move ahead slowly 3 steps");
        effects.push_back("Energetic ... move ahead 4 steps");
        effects.push_back("Sleepy ... stay where you are for a little power nap");
        effects.push_back("Food Critic ... Stop critisizing and move back 1 step");
    };
}

void Cook::cook(Player *player)
{
    // Define a map to store cooks and specialties for different cuisines and food styles
    std::map<std::pair<std::string, std::string>, std::pair<std::vector<std::string>, std::vector<std::string>>> data;

    // Populate the map with data
    data[{"Austrian", "Fancy"}] = {{"Kevin", "Franzi", "Anna", "Sophia"}, {"Schnitzel", "Cordon bleu", "Käsespätzle", "Germknödel"}};
    data[{"Austrian", "Gourmet"}] = {{"Sofia"}, {"Schnitzel au vin", "Schnitzel Bourguignon", "Schnitzel Suzette"}};
    data[{"Austrian", "StreetFood"}] = {{"Gaga", "Beni", "Andy", "Stefan"}, {"Wurst", "kebab knödel", "Leberkäsesemmel", "käsekrainer"}};

    data[{"Moroccan", "Fancy"}] = {{"Taha", "Soufiane", "Hamza", "Safaa"}, {"Tajine", "Couscous", "Seffa", "Bissara"}};
    data[{"Moroccan", "Gourmet"}] = {{"Yasser"}, {"Lamb Tagine", "B'stilla", "Seafood Bastilla", "Tanjia"}};
    data[{"Moroccan", "StreetFood"}] = {{"Faycal", "Aziz", "Mao", "Simo"}, {"Harcha kiri", "Mssemen", "Sfenj", "Harira"}};

    data[{"French", "Fancy"}] = {{"Victor", "Marine", "Magaux", "Theo"}, {"Raclette", "Tartiflette", "Croissant", "canard laqué"}};
    data[{"French", "Gourmet"}] = {{"Ange"}, {"Coq au Vin", "Bœuf Bourguignon", "Crêpes Suzette", "Tian de légumes du soleil"}};
    data[{"French", "StreetFood"}] = {{"Raph", "Marcus", "Salomé", "Tess"}, {"sandwish merguez", "Tacos de Lyon", "Crepe au beur salé", "... Shit it burned :("}};

    data[{"German", "Fancy"}] = {{"Lena", "Inky", "Ralph", "Selina"}, {"Vegan toast", "Avocado toast", "gluten free musli", "lactos free pumkin soup"}};
    data[{"German", "Gourmet"}] = {{"Arne"}, {"Sauerbraten", "Trout Meunière", "Veal Rouladen", "Black Forest Cake"}};
    data[{"German", "StreetFood"}] = {{"Eli", "Flo", "Micky"}, {"kebab", "bred with onions", "curry wurst", "... Shit it burned :("}};

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
        std::cout << cookName << " made " << speciality << " 😋\n";
        std::string effect = pick_random(effects); // Assuming 'effects' is defined somewhere
        size_t found = effect.find("skip");
        if (found != std::string::npos)
        {
            player->skipNextRound++;
        }

        std::cout << "You feel " << effect << std::endl;
    }
};