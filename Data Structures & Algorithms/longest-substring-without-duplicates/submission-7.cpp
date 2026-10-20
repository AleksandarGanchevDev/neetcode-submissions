#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int last[256];
        fill(last, last + 256, -1);
        int j = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (last[c] >= j)
                j = last[c] + 1;
            last[c] = i;
            maxLen = max(maxLen, i - j + 1);
        }

        return maxLen;
    }
};
