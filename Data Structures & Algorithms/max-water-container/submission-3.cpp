#include <iostream>

using namespace std;

class Solution
{
public:
    int calArea(int i, int j, vector<int> &optimal)
    {
        return (min(optimal[i], optimal[j])) * (j - i);
    }

    int maxArea(vector<int> &heights)
    {

        vector<int> left;
        int maxn = 0;

        for (int i = 0; i < heights.size(); i++)
        {
            left.push_back(max(maxn, heights[i]));
            maxn = max(maxn, heights[i]);
        }

        vector<int> right = left;
        maxn = 0;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            right[i] = max(maxn, heights[i]);
            maxn = max(maxn, heights[i]);
        }

        vector<int> optimal;
        for (int i = 0; i < left.size(); i++)
            optimal.push_back(min(left[i], right[i]));

        int i = 0, j = optimal.size() - 1;
        int maxArea = 0;
        while (i < j)
        {
            // cout << "I: " << i << " with value: " << optimal[i] << ' ' << "J: " << j << " with value " << optimal[j] << endl;
            maxArea = max(maxArea, calArea(i, j, optimal));
            // cout << "Max area value: " << maxArea << endl;

            if (i + 1 < j && calArea(i + 1, j, optimal) > calArea(i, j, optimal))
                i++;
            else if (i < j - 1 && calArea(i, j - 1, optimal) > calArea(i, j, optimal))
                j--;
            else
            {
                if (optimal[i] > optimal[j])
                    j--;
                else
                    i++;
            }
        }

        return maxArea;
    }
};
