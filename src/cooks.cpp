#include <iostream>
#include <string>
using namespace std;
#include "cooks.hpp"

// Constructor implementation
Cook::Cook(string type, int streetFood) : type(type), streetFood(streetFood)
{

    if (streetFood == 1)
    {
        cout << "You ordered " << type << " street food ..." << endl;

        effects.push_back("Farty ... Move ahead and the players after you have to move back");
        effects.push_back("Sick ... Go to hospital and skip the next round");
        effects.push_back("Too Full ... stay where you are and skip next meal");
        effects.push_back("Feel good ... move ahead");
        effects.push_back("Intoxicated ... Go to hospital or to jail if you have offered the food");
        effects.push_back("Burpy ... move ahead and the players in front move ahead");
    }
    else
    {
        cout << "You ordered " << type << " fancy food ..." << endl;

        effects.push_back("Happy ... move ahead");
        effects.push_back("Full  ... move ahead slowly");
        effects.push_back("Energetic ... move ahead 2 steps");
        effects.push_back("Burpy  ... move ahead and the players in front move ahead");
        effects.push_back("sleepy ... stay way you are for a little power nap");
    };
}

string Cook::pick_random(vector<string> list)
{
    string random_x;
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(0, list.size() - 1);

    int randomIndex = dist(gen);
    random_x = list[randomIndex];

    return random_x;
};

void Cook::cook()
{
    if (type == "Austrian" && streetFood == 1)
    {
        // Austrian streed food cooks and specialities
        names.push_back("Gaga");
        names.push_back("Beni");
        names.push_back("Andy");
        names.push_back("Stefan");

        specialities.push_back("Wurst");
        specialities.push_back("kebab knödel");
        specialities.push_back("Leberkäsesemmel");
        specialities.push_back("käsekrainer");
    }
    if (type == "Austrian" && streetFood == 0)
    {

        // Austrian fancy cooks and specialities
        names.push_back("Kevin");
        names.push_back("Franzi");
        names.push_back("Anna");
        names.push_back("Sophia");

        specialities.push_back("Schnitzel");
        specialities.push_back("Cordon bleu");
        specialities.push_back("Käsespätzle");
        specialities.push_back("Germknödel");
    }
    if (type == "Moroccan" && streetFood == 1)
    {
        // Moroccan streed food cooks and specialities
        names.push_back("Faycal");
        names.push_back("Aziz");
        names.push_back("Mao");
        names.push_back("Simo");

        specialities.push_back("Harcha kiri");
        specialities.push_back("Mssemen");
        specialities.push_back("Sfenj");
        specialities.push_back("Harira");
    }
    if (type == "Moroccan" && streetFood == 0)
    {

        // Moroccan fancy cooks and specialities
        names.push_back("Taha");
        names.push_back("Soufiane");
        names.push_back("Hamza");
        names.push_back("Safaa");

        specialities.push_back("Tajine");
        specialities.push_back("Couscous");
        specialities.push_back("Seffa");
        specialities.push_back("Bissara");
    }
    if (type == "French" && streetFood == 1)
    {
        // French streed food cooks and specialities
        names.push_back("Raph");
        names.push_back("Marcus");
        names.push_back("Salomé");
        names.push_back("Tess");

        specialities.push_back("sandwish merguez");
        specialities.push_back("Tacos de Lyon");
        specialities.push_back("Crepe au beur safé");
        specialities.push_back("... Shit it burned :(");
    }
    if (type == "French" && streetFood == 0)
    {

        // French fancy cooks and specialities
        names.push_back("Victor");
        names.push_back("Ange");
        names.push_back("Magaux");
        names.push_back("Theo");

        specialities.push_back("Raclette");
        specialities.push_back("Tartiflette");
        specialities.push_back("Croissant");
        specialities.push_back("canard laqué");
    }
    if (type == "German" && streetFood == 1)
    {
        // German streed food cooks and specialities
        names.push_back("Eli");
        names.push_back("Arne");
        names.push_back("Flo");
        names.push_back("Micky");

        specialities.push_back("kebab");
        specialities.push_back("bred with onions");
        specialities.push_back("curry wurst");
        specialities.push_back("... Shit it burned :(");
    }
    if (type == "German" && streetFood == 0)
    {

        // German fancy cooks and specialities
        names.push_back("Lena");
        names.push_back("Inky");
        names.push_back("Ralph");
        names.push_back("Selina");

        specialities.push_back("Vegan toast");
        specialities.push_back("Avocado toast");
        specialities.push_back("gluten free musli");
        specialities.push_back("lactos free pumkin soup");
    }
    if (type == "Indian" && streetFood == 1)
    {
        // Indian street food cooks and specialties
        names.push_back("Raj");
        names.push_back("Priya");
        names.push_back("Amit");
        names.push_back("Meera");

        specialities.push_back("Samosa");
        specialities.push_back("Pani Puri");
        specialities.push_back("Vada Pav");
        specialities.push_back("... Shit it burned :(");
    }
    if (type == "Indian" && streetFood == 0)
    {
        // Indian fancy cooks and specialties
        names.push_back("Sanjeev");
        names.push_back("Meenakshi");
        names.push_back("Rahul");
        names.push_back("Anjali");

        specialities.push_back("Butter Chicken");
        specialities.push_back("Biryani");
        specialities.push_back("Paneer Tikka");
        specialities.push_back("Masala Dosa");
    }

    // Pick a random cook and speciality
    name = pick_random(names);
    if (name == "Marcus")
    {
        speciality = "Pasta pesto";
    }
    else
    {
        speciality = pick_random(specialities);
    }

    // Effect of the food
    cout << "Allo " << name << " !!!" << endl;
    cout << name << " made " << speciality << " 😋" << endl;
    effect = pick_random(effects);
    cout << "You feel " << effect << endl;
};