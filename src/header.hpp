#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> read_file(string filename)
{
    vector<string> lines;
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

bool is_number(char c)
{
    return c >= '0' && c <= '9';
}
