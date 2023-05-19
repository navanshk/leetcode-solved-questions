class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a=nums[i];
            int more=target-a;
            
                if(mp.find(more)!=mp.end())
                {
                    ans.push_back(mp[more]);
                    ans.push_back(i);
                }
                    
            mp[a]=i;
            
        }
        return ans;
    }
};