#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            if (st.empty())
                return false;
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (st.top() == '{' && s[i] == '}')
                    st.pop();
                else if (st.top() == '[' && s[i] == ']')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty() ? true : false;
    }
};
