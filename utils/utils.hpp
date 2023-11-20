#ifndef YOUR_HEADER_FILE_H
#define YOUR_HEADER_FILE_H

#include <vector>
#include <random>

template <typename T>
T pick_random(const std::vector<T> &list)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, list.size() - 1);

    int randomIndex = dist(gen);
    return list[randomIndex];
}

#endif // YOUR_HEADER_FILE_H
