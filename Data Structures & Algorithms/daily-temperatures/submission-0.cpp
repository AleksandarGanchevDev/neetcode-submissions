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
                // cout << "Current element: " << temperatures[i] << " with position: " << i << endl;
                // cout << "The current top element is " << temperatures[stack.top()] << " with its position: " << stack.top() << endl;
                // cout << "We record on position: " << stack.top() << " the value: " << i - stack.top() << endl;
                // cout << endl;

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
