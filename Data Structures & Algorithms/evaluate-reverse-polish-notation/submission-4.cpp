#include <iostream>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++)
        {
            string &t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int n2 = st.top();
                st.pop();
                int n1 = st.top();
                st.pop();
                if (tokens[i][0] == '+')
                    st.push(n1 + n2);
                if (tokens[i][0] == '-')
                    st.push(n1 - n2);
                if (tokens[i][0] == '*')
                    st.push(n1 * n2);
                if (tokens[i][0] == '/')
                    st.push(n1 / n2);
            }
            else
            {
                int n = stoi(tokens[i]);
                st.push(n);
            }
        }

        return st.top();
    }
};
