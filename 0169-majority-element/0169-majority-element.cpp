class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n=nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int ans = -1;
    for (auto x : mp)
    {
        if (x.second > n / 2)
            ans = x.first;
    }
    return ans;
    }
};