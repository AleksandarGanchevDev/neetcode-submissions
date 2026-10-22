#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> stack;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i])
            {
                ans[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        while (!stack.empty())
        {
            ans[stack.top()] = 0;
            stack.pop();
        }

        return ans;
    }
};
