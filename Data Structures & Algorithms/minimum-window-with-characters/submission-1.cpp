#include <iostream>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int need[128] = {}, bestLen = INT_MAX, bestStart = 0, j = 0, missing = t.size();
        for (auto c : t)
            need[c]++;

        for (int i = 0; i < s.size(); i++)
        {
            if (need[s[i]] > 0)
                missing--;
            need[s[i]]--;

            while (missing == 0)
            {
                if (i - j + 1 < bestLen)
                {
                    bestLen = i - j + 1;
                    bestStart = j;
                }
                need[s[j]]++;
                if (need[s[j]] > 0)
                    missing++;
                j++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
