class Solution
{
public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::map<int, int> m;
        for (auto n : nums)
        {
            if (!m.contains(n))
            {
                m[n] = 1;
            }
            else
            {
                return 1;
            }
        }
        return 0;
    }
};