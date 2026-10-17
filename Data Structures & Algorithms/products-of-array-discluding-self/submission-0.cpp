class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left, right;

        int mul = 1;
        for (int n : nums)
        {
            mul *= n;
            left.push_back(mul);
        }

        mul = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mul *= nums[i];
            right.push_back(mul);
        }

        vector<int> res;
        for (int i = 0; i < left.size(); i++)
        {
            mul = 1;
            if (i != 0)
            {
                mul *= left[i - 1];
            }
            if (i != left.size() - 1)
            {
                mul *= right[left.size() - 2 - i];
            }
            res.push_back(mul);
        }

        return res;
    }
};
