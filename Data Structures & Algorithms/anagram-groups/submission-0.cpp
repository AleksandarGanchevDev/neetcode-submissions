class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> seen;
        for (auto &w : strs)
        {
            string key = w;
            sort(key.begin(), key.end());
            seen[key].push_back(w);
        }

        vector<vector<string>> ans;
        ans.reserve(seen.size());
        for(auto &[key, values] : seen) ans.push_back(move(values));

        return ans;
    }
};
