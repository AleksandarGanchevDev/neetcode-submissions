#include <iostream>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int top = heights[st.top()];
                st.pop();
                int leftIndex = st.empty() ? -1 : st.top();
                int width = i - leftIndex - 1;
                maxArea = max(maxArea, width * top);
            }
            st.push(i);
        }
        return maxArea;
    }
};
