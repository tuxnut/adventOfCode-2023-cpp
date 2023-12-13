#include <iostream>
#include <fstream>
#include <algorithm>
#include <regex>
#include <string>

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
