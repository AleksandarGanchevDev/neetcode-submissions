#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int j = 0, need[26] = {}, window[26] = {};
        for (auto c : s1)
            need[c - 'a']++;

        for (int i = 0; i < s2.size(); i++)
        {
            window[s2[i] - 'a']++;
            if (i >= s1.size())
            {
                window[s2[j] - 'a']--;
                j++;
            }

            if (equal(need, need + 26, window))
                return true;
        }

        return false;
    }
};
