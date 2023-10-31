#include <iostream>
#include <string>
using namespace std;
#include "cooks.hpp"

void Cook::cook()
{
    if (Cook::type == "Austrian" && Cook::streetFood == 1)
    {
        static const vector<string> names{"Gaga", "Beni", "Andy"};
        static const vector<string> specialities{"Wurst", "kebab knudle", "Leberkäsesemmel"};
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<int> dist1(0, names.size() - 1);

        int randomIndex1 = dist1(gen);
        name = names[randomIndex1];

        static uniform_int_distribution<int> dist2(0, specialities.size() - 1);
        int randomIndex2 = dist2(gen);

        speciality = specialities[randomIndex2];
    }
    else if (Cook::type == "Austrian" && Cook::streetFood == 0)
    {
        static const vector<string> names{"Kevin", "Franzi", "Anna"};
        static const vector<string> specialities{"Schnitzel", "Cordon bleu", "Käsespätzle"};

        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<int> dist1(0, names.size() - 1);

        int randomIndex1 = dist1(gen);
        name = names[randomIndex1];

        static uniform_int_distribution<int> dist2(0, specialities.size() - 1);
        int randomIndex2 = dist2(gen);

        speciality = specialities[randomIndex2];
    }

    cout << "Allo " << name << " !!!" << endl;
    cout << Cook::name << " made " << Cook::speciality << " O_o" << endl;
};