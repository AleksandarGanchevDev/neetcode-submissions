class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;

        for (string &w : strs)
        {
            res += to_string(w.size());
            res += '#';
            res += w;
        }

        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;

        while (i < s.size())
        {
            int j = i;
            int len = 0;
            while (s[j] != '#')
            {
                j++;
            }
            len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return res;
    }
};
