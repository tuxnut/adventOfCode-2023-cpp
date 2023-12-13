#include "header.hpp"

vector<int> capture_winings(const string &line)
{
    vector<int> winings;
    for (auto &m : find_all(line.substr(10, 29), regex("(\\d+)")))
    {
        winings.push_back(stoi(m));
    }
    return winings;
}

vector<int> capture_owned(const string &line)
{
    vector<int> owned;
    for (auto &m : find_all(line.substr(42, 74), regex("(\\d+)")))
    {
        owned.push_back(stoi(m));
    }
    return owned;
}

void problem1(vector<string> &lines)
{
    size_t result = 0;

    for (auto &l : lines)
    {
        vector<int> &&winings = capture_winings(l);
        vector<int> &&owned = capture_owned(l);
        set<int> uniq_owned(owned.begin(), owned.end());

        int nb_wining_card = 0;
        for (auto &&w : winings)
            if (uniq_owned.find(w) != uniq_owned.end())
                nb_wining_card++;

        result += nb_wining_card == 0 ? 0 : pow(2, nb_wining_card - 1);
    }

    std::cout << "Problem 1 solution:\t" << result << "\n";
}

void problem2(vector<string> &lines)
{
    size_t result = 0;

    map<size_t, int> nb_card_per_id;
    for (size_t i = 0; i < lines.size(); i++)
    {
        auto l = lines[i];
        vector<int> &&winings = capture_winings(l);
        vector<int> &&owned = capture_owned(l);
        set<int> uniq_owned(owned.begin(), owned.end());

        int nb_wining_card = 0;
        for (auto &&w : winings)
            if (uniq_owned.find(w) != uniq_owned.end())
                nb_wining_card++;
    }

    std::cout << "Problem 2 solution:\t" << result << "\n";
}

int main(int argc, char const *argv[])
{
    vector<string> content = read_file("res/day4.txt");

    // problem1(content);
    problem2(content);

    return 0;
}
