#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            while (i > 0 && i < nums.size() && nums[i] == nums[i - 1])
                i++;

            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                    k--;
                else if (sum < 0)
                    j++;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
            }
        }

        return ans;
    }
};
