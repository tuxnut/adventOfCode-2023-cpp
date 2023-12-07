#include "header.hpp"

void problem1(vector<string> &lines)
{
    int sum = 0;
    for (string &line : lines)
    {
        // create vector int
        vector<int> numbers;

        // iterate char of string
        for (char &c : line)
        {
            // test if char is a number
            if (is_number(c))
            {
                // parse c as int and push it to vector
                numbers.push_back(c - '0');
            }
        }

        sum += numbers.front() * 10 + numbers.back();
    }
    std::cout << "Problem 1 solution: " << sum << "\n";
}

void problem2(vector<string> &lines)
{
    int sum = 0;

    for (auto &l : lines)
    {
        auto replaced = regex_replace(l, regex("one"), "one1one");
        replaced = regex_replace(replaced, regex("two"), "two2two");
        replaced = regex_replace(replaced, regex("three"), "three3three");
        replaced = regex_replace(replaced, regex("four"), "four4four");
        replaced = regex_replace(replaced, regex("five"), "five5five");
        replaced = regex_replace(replaced, regex("six"), "six6six");
        replaced = regex_replace(replaced, regex("seven"), "seven7seven");
        replaced = regex_replace(replaced, regex("eight"), "eight8eight");
        replaced = regex_replace(replaced, regex("nine"), "nine9nine");

        vector<int> numbers;

        for (char &c : replaced)
        {
            if (is_number(c))
            {
                numbers.push_back(c - '0');
            }
        }

        sum += numbers.front() * 10 + numbers.back();
    }

    std::cout << "Problem 2 solution: " << sum << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day1.txt");

    // problem1(content);
    problem2(content);

    return 0;
}
