#pragma once
using namespace std;
#include <random>

class Cook
{
public:
    string name;
    int streetFood;
    string type;
    string speciality;

public:
    Cook(string type, int streetFood) : type(type), streetFood(streetFood)
    {
        if (type == "Austrian" && streetFood == 1)
        {
            static const std::vector<std::string> names{"Gaga", "Beni", "Andy"};
            static const std::vector<std::string> specialities{"Wurst", "kebab knudle", "Leberkäsesemmel"};
            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_int_distribution<int> dist1(0, names.size() - 1);

            int randomIndex1 = dist1(gen);
            name = names[randomIndex1];

            static std::uniform_int_distribution<int> dist2(0, specialities.size() - 1);
            int randomIndex2 = dist2(gen);

            speciality = specialities[randomIndex2];
        }
        else if (type == "Austrian" && streetFood == 0)
        {
            static const std::vector<std::string> names{"Kevin", "Franzi", "Anna"};
            static const std::vector<std::string> specialities{"Schnitzel", "Cordon bleu", "Käsespätzle"};

            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_int_distribution<int> dist1(0, names.size() - 1);

            int randomIndex1 = dist1(gen);
            name = names[randomIndex1];

            static std::uniform_int_distribution<int> dist2(0, specialities.size() - 1);
            int randomIndex2 = dist2(gen);

            speciality = specialities[randomIndex2];
        }
        cout << "Allo " << name << " !!!" << endl;
    }

    void cook();
};
