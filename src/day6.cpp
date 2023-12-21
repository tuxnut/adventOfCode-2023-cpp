#include "header.hpp"

void problem1(vector<string> &lines)
{
    size_t result = 0;

    vector<size_t> times;
    auto t = find_all(lines[0], regex("(\\d+)"));
    for (auto &&i : t)
    {
        times.push_back(stoi(i));
    }

    vector<size_t> distances;
    auto d = find_all(lines[1], regex("(\\d+)"));
    for (auto &&i : d)
    {
        distances.push_back(stoi(i));
    }

    vector<size_t> records(distances.size(), 0);
    for (size_t i = 0; i < times.size(); i++)
    {
        auto time = times[i];
        auto distance = distances[i];

        for (size_t h = 1; h < time; h++)
        {
            auto speed = h;
            auto time_remaining = time - h;

            auto d = speed * time_remaining;

            if (d > distance)
            {
                records[i]++;
            }
        }
    }

    result = 1;
    for (auto &&i : records)
    {
        result *= i;
    }

    std::cout
        << "Problem 1 solution:\t" << result << "\n";
}

void problem2(vector<string> &lines)
{
    size_t result = 0;

    std::cout << "Problem 2 solution:\t" << result << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day6.txt");

    problem1(content);
    problem2(content);

    return 0;
}
