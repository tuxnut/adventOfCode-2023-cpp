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
    std::cout << "Problem 2 solution\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day2.txt");

    problem1(content);
    // problem2(content);

    return 0;
}
