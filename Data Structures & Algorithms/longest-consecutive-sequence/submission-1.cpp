#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        set<int> seq;
        for (int n : nums)
        {
            seq.insert(n);
        }

        int cnt = 1, ans = 1, prev = INT_MAX;
        for (int n : seq)
        {
            if (n == prev + 1)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
            prev = n;
        }
        ans = max(ans, cnt);
        return ans;
    }
};
