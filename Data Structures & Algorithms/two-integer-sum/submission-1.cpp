class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            auto it = seen.find(need);
            if(it != seen.end()) return {seen[need], i};

            seen[nums[i]] = i;
        }
        return {};
    }
};