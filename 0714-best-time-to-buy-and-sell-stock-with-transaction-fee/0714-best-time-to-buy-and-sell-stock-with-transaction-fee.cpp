class Solution {
public:
      int f(int i,int buy,vector<int>&a, vector<vector<int>>&dp,int fee)
    {          int profit;
               int n=a.size();
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy==1)
             profit =max((-a[i]+f(i+1,0,a,dp,fee)),(0+f(i+1,1,a,dp,fee)));
        else
        {
            profit=max((a[i]-fee+f(i+1,1,a,dp,fee)),(0+f(i+1,0,a,dp,fee)));
        }
     return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
           int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
        
    }
};