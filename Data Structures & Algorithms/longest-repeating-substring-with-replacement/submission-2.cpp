#include <iostream>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int cnt[26] = {}, j = 0, best = 0, maxFreq = 0;
        for (int i = 0; i < s.size(); i++)
        {
            cnt[s[i] - 'A']++;
            maxFreq = max(maxFreq, cnt[s[i] - 'A']);
            while ((i - j + 1) > k + maxFreq)
            {
                cnt[s[j] - 'A']--;
                j++;
            }

            best = max(best, (i - j + 1));
        }
        return best;
    }
};
