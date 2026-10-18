#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> v;

    int calArea(int i, int j)
    {
        return (min(v[i], v[j]) * (j - i - 2));
    }

    int trap(vector<int> &height)
    {

        int maxn = 0;
        for (int i = 0; i < height.size(); i++)
        {
            maxn = max(maxn, height[i]);
            v.push_back(maxn);
        }

        maxn = 0;
        for (int i = height.size() - 1; i >= 0; i--)
        {
            maxn = max(height[i], maxn);
            v[i] = min(maxn, v[i]);
        }

        int total = 0;
        for (int i = 0; i < v.size(); i++)
        {
            total += v[i] - height[i];
        }

        return total;
    }
};
