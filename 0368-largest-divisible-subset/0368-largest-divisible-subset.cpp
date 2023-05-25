class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n=nums.size();
        vector<int>dp(n, 1), track(n, 1), ans;
        int maxi=1, pos=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            track[i]=i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    track[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                pos=i;
            }
        }
        ans.push_back(nums[pos]);
        while(pos!=track[pos]){
            pos=track[pos];
            ans.push_back(nums[pos]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
      
    }
};