class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (auto n : nums)
            freq[n]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &[key, value] : freq)
            buckets[value].push_back(key);

        vector<int> ans;
        for(int i=nums.size(); i>0;i--){
            for(auto n : buckets[i]){
                ans.push_back(n);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};