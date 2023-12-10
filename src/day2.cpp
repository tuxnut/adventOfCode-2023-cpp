#include "header.hpp"

void problem1(vector<string> &lines)
{
    int result = 0;
    regex game_id("^(\\d+)");
    regex re("((\\d+) (blue|red|green))");
    smatch match;

    for (auto &l : lines)
    {
        bool is_game_possible = true;

        int id = 0;
        if (regex_search(l, match, game_id))
        {
            id = stoi(match.str(1));
        }

        while (regex_search(l, match, re))
        {
            auto qtt = match.str(2);
            auto color = match.str(3);

            if (color == "blue" && stoi(qtt) > 14)
            {
                is_game_possible = false;
            }
            else if (color == "red" && stoi(qtt) > 12)
            {
                is_game_possible = false;
            }
            else if (color == "green" && stoi(qtt) > 13)
            {
                is_game_possible = false;
            }

            l = match.suffix().str();
        }

        if (is_game_possible)
            result += id;
    }

    std::cout << "Problem 1 solution:\t" << result << "\n";
}

void problem2(vector<string> &lines)
{
    int result = 0;
    regex re("((\\d+) (blue|red|green))");
    smatch match;

    for (auto &l : lines)
    {
        array<int, 3> cubes = {1, 1, 1};

        while (regex_search(l, match, re))
        {
            auto qtt = match.str(2);
            auto color = match.str(3);

            if (color == "blue")
            {
                cubes[0] = (stoi(qtt) > cubes[0]) ? stoi(qtt) : cubes[0];
            }
            else if (color == "red")
            {
                cubes[1] = (stoi(qtt) > cubes[1]) ? stoi(qtt) : cubes[1];
            }
            else if (color == "green")
            {
                cubes[2] = (stoi(qtt) > cubes[2]) ? stoi(qtt) : cubes[2];
            }

            l = match.suffix().str();
        }

        result += cubes[0] * cubes[1] * cubes[2];
    }

    std::cout << "Problem 2 solution:\t" << result << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day2.txt");

    // problem1(content);
    problem2(content);

    return 0;
}
