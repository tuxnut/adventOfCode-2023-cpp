#include "header.hpp"

bool compute_is_engine_part(bool is_engine_part, const vector<string> &lines, size_t l, size_t i)
{
    if (is_engine_part)
        return true;

    if (l > 0)
    {
        if (i > 0 && !is_number(lines[l - 1][i - 1]) && lines[l - 1][i - 1] != '.')
            return true;
        if (!is_number(lines[l - 1][i]) && lines[l - 1][i] != '.')
            return true;
        if (i < lines[l].size() - 1 && !is_number(lines[l - 1][i + 1]) && lines[l - 1][i + 1] != '.')
            return true;
    }
    if (i > 0 && !is_number(lines[l][i - 1]) && lines[l][i - 1] != '.')
        return true;
    if (i < lines[l].size() - 1 && !is_number(lines[l][i + 1]) && lines[l][i + 1] != '.')
        return true;

    if (l < lines.size() - 1)
    {
        if (i > 0 && !is_number(lines[l + 1][i - 1]) && lines[l + 1][i - 1] != '.')
            return true;
        if (!is_number(lines[l + 1][i]) && lines[l + 1][i] != '.')
            return true;
        if (i < lines[l].size() - 1 && !is_number(lines[l + 1][i + 1]) && lines[l + 1][i + 1] != '.')
            return true;
    }

    return false;
}

void add_to_result(int &result, const string &curr_n)
{
    result += stoi(curr_n);
}

void problem1(const vector<string> &lines)
{
    int result = 0;
    bool is_engine_part = false;
    string curr_n = "";

    for (size_t l = 0; l < lines.size(); l++)
    {
        for (size_t i = 0; i < lines[l].size(); i++)
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
                {
                    add_to_result(result, curr_n);
                }

                curr_n = "";
                is_engine_part = false;
            }
        }
    }
}

bool has_two_numbers_adjacent(const vector<string> &lines, size_t l, size_t i, pair<Coo2, Coo2> &n)
{
    bool f_is_found = false;
    for (size_t ll = l - 1; ll <= l + 1; ll++)
    {
        for (size_t ii = i - 1; ii <= i + 1; ii++)
        {
            if (ll >= 0 && ii >= 0 && ll < lines.size() && ii < lines[l].size())
            {
                if (is_number(lines[ll][ii]))
                {
                    if (f_is_found)
                    {
                        n.second.setCoo(ll, ii);
                        return true;
                    }

                    n.first.setCoo(ll, ii);
                    f_is_found = true;

                    ii++;
                    if (is_number(lines[ll][ii]))
                    {
                        ii++;
                    }
                }
            }
        }
    }

    return false;
}

int find_number(const vector<string> &lines, Coo2 &coo)
{
    int y = coo.y;
    int offset = 1;
    bool b_found = false, e_found = false;
    string num = "";
    num += lines[coo.x][coo.y];

    while (!(b_found && e_found))
    {
        if (y - offset >= 0 && is_number(lines[coo.x][y - offset]) && !b_found)
        {
            num = lines[coo.x][y - offset] + num;
        }
        else
        {
            b_found = true;
        }

        if (y + offset <= lines[coo.x].size() - 1 && is_number(lines[coo.x][y + offset]) && !e_found)
        {
            num += lines[coo.x][y + offset];
        }
        else
        {
            e_found = true;
        }

        offset++;
    }

    return stoi(num);
}

void problem2(vector<string> &lines)
{
    size_t result = 0;

    for (size_t l = 0; l < lines.size(); l++)
    {
        for (size_t i = 0; i < lines[l].size(); i++)
        {
            if (lines[l][i] == '*')
            {
                pair<Coo2, Coo2> p;
                bool is_gear = has_two_numbers_adjacent(lines, l, i, p);

                if (is_gear)
                {
                    int first = find_number(lines, p.first);
                    int second = find_number(lines, p.second);

                    result += first * second;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day3.txt");

    problem1(content);
    problem2(content);

    return 0;
}
