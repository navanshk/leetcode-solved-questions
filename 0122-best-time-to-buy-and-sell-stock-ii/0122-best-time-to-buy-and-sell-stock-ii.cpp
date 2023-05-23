class Solution {
public:
    int f(int i,int buy,vector<int>&a, vector<vector<int>>&dp)
    {          int profit;
               int n=a.size();
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy==1)
             profit =max((-a[i]+f(i+1,0,a,dp)),(0+f(i+1,1,a,dp)));
        else
        {
            profit=max((a[i]+f(i+1,1,a,dp)),(0+f(i+1,0,a,dp)));
        }
     return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
        
        
        // if buy==1
            // we can buy
    }
};