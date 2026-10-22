#include <iostream>

using namespace std;

class MinStack
{
private:
    stack<int> st, minStack;

public:
    MinStack() {}

    void push(int val)
    {
        if (!st.empty())
            minStack.push(min(minStack.top(), val));
        else
            minStack.push(val);
        st.push(val);
    }

    void pop()
    {
        st.pop();
        minStack.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};
