#include "header.hpp"

void problem1(vector<string> & lines)
{
    std::cout << "Problem 1 solution\n";
}

void problem2(vector<string> & lines)
{
    std::cout << "Problem 2 solution\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day.txt");

    problem1(content);
    problem2(content);

    return 0;
}
