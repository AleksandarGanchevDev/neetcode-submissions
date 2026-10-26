#include <iostream>

using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        int l = -1, r = m[key].size();
        while (l + 1 < r)
        {
            int mid = l + (r - l) / 2;
            if (m[key][mid].first <= timestamp)
                l = mid;
            else
                r = mid;
        }

        return l == -1 ? "" : m[key][l].second;
    }
};
