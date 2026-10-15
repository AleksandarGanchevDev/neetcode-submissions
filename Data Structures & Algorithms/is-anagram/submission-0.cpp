class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::map<char, int> rec;
        for (auto c : s)
        {
            if (!rec.contains(c))
                rec[c] = 1;
            else
                rec[c]++;
        }
        for (auto c : t)
        {
            if (rec.contains(c))
            {
                rec[c]--;
                if (rec[c] == 0)
                    rec.erase(c);
            }
            else
                return 0;
        }
        if (!rec.empty())
            return 0;
        return 1;
    }
};