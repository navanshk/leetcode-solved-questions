class Solution {
public:
    
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
          for(int pre=0;pre<i;pre++)
          {
              if(arr[pre]<arr[i])
                  dp[i]=max(dp[i],1+dp[pre]);
          }
            maxi=max(maxi,dp[i]);
              
        }
        return maxi;
    }
    
};