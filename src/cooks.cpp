#include <iostream>
#include <string>
using namespace std;
#include "cooks.hpp"

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
    if (Cook::type == "Austrian" && Cook::streetFood == 1)
    {
        static const vector<string> names{"Gaga", "Beni", "Andy"};
        static const vector<string> specialities{"Wurst", "kebab knudle", "Leberkäsesemmel"};
        name = pick_random(names);
        speciality = pick_random(specialities);
       }
    else if (Cook::type == "Austrian" && Cook::streetFood == 0)
    {
        static const vector<string> names{"Kevin", "Franzi", "Anna"};
        static const vector<string> specialities{"Schnitzel", "Cordon bleu", "Käsespätzle"};

        name = pick_random(names);
        speciality = pick_random(specialities);
    }

    cout << "Allo " << name << " !!!" << endl;
    cout << name << " made " << speciality << " O_o" << endl;
};