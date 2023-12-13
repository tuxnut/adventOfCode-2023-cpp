#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <string>
#include <set>
#include <cmath>

using namespace std;

struct Coo2
{
    size_t x;
    size_t y;

    void setCoo(size_t ix, size_t iy)
    {
        x = ix;
        y = iy;
    }
};

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

vector<string> find_all(const string &source, const regex &matcher)
{
    vector<string> matches;
    smatch match;

    string copy = source;

    while (regex_search(copy, match, matcher))
    {
        matches.push_back(match.str(1));
        copy = match.suffix().str();
    }

    return matches;
}
