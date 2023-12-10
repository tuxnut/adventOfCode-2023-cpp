#include "header.hpp"

void problem1(vector<string> &lines)
{
    int result = 0;

    std::cout << "Problem 1 solution:\t" << result << "\n";
}

void problem2(vector<string> &lines)
{
    int result = 0;

    std::cout << "Problem 2 solution:\t" << result << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day.txt");

    problem1(content);
    problem2(content);

    return 0;
}
