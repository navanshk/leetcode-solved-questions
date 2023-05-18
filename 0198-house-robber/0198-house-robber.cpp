class Solution {
public:
      int maxi(vector<int>& nums,int i,vector<int>&dp)
      {
          if(i==0)
              return nums[i];
          if(i<0)
              return 0;
          if(dp[i]!=-1)
              return dp[i];
          int take,nontake;
           take = nums[i] + maxi(nums,i-2,dp);
           nontake = 0 + maxi(nums,i-1,dp);
          return dp[i] = max(take,nontake);
      }
      int rob(vector<int>& nums) {
          int n=nums.size();
       vector<int>dp(n,-1);
          return maxi(nums ,n-1,dp);
    }
};