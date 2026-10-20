#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<int> seen;
        int j = 0, len = 0, maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (!seen.contains(s[i]))
            {
                seen.insert(s[i]);
                len++;
            }
            else
            {
                while (seen.contains(s[i]))
                {
                    seen.erase(s[j]);
                    j++;
                    len--;
                }
                seen.insert(s[i]);
                len++;
            }
            // cout << "On position: " << i << " we have length: " << len << endl;
            maxLen = max(maxLen, len);
            // for (auto e : seen)
            //     cout << (char)e << ' ';
            // cout << endl;
        }
        return maxLen;
    }
};
