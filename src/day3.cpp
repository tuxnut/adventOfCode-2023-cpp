#include "header.hpp"

bool compute_is_engine_part(bool is_engine_part, vector<string> &lines, int l, int i)
{
    if (is_engine_part)
        return true;

    if (l > 0)
    {
        if (i > 0 && !is_number(lines[l - 1][i - 1]) && lines[l - 1][i - 1] != '.')
            return true;
        if (!is_number(lines[l - 1][i]) && lines[l - 1][i] != '.')
            return true;
        if (i < lines[l].size() && !is_number(lines[l - 1][i + 1]) && lines[l - 1][i + 1] != '.')
            return true;
    }
    if (i > 0 && !is_number(lines[l][i - 1]) && lines[l][i - 1] != '.')
        return true;
    if (i < lines[l].size() && !is_number(lines[l][i + 1]) && lines[l][i + 1] != '.')
        return true;

    if (l < lines.size() - 1)
    {
        if (i > 0 && !is_number(lines[l + 1][i - 1]) && lines[l + 1][i - 1] != '.')
            return true;
        if (!is_number(lines[l + 1][i]) && lines[l + 1][i] != '.')
            return true;
        if (i < lines[l].size() && !is_number(lines[l + 1][i + 1]) && lines[l + 1][i + 1] != '.')
            return true;
    }

    return false;
}

void problem1(vector<string> &lines)
{
    int result = 0;
    bool is_engine_part = false;
    string curr_n = "";

    for (int l = 0; l < lines.size(); l++)
    {
        if (is_engine_part)
            result += stoi(curr_n);

        curr_n = "";
        is_engine_part = false;

        for (int i = 0; i < lines[l].size(); i++)
        {
            char c = lines[l][i];

            if (is_number(c))
            {
                curr_n += c;
                is_engine_part = compute_is_engine_part(is_engine_part, lines, l, i);
            }
            else
            {
                
                if (is_engine_part)
                    result += stoi(curr_n);

                curr_n = "";
                is_engine_part = false;
            }
        }
    }

    std::cout << "Problem 1 solution:\t" << result << "\n";
}

void problem2(vector<string> &lines)
{
    int result = 0;

    std::cout << "Problem 2 solution:\t" << result << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day3.txt");

    // 553577
    // 549292
    problem1(content);
    problem2(content);

    return 0;
}
