class Solution {
public:
      int f(int i,int buy,vector<int>&a, vector<vector<vector<int>>>&dp,int cap)
    {          int profit;
               int n=a.size();
        if(i==n||cap==0)
            return 0; 
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        if(buy==1)
             profit =max((-a[i]+f(i+1,0,a,dp,cap)),(0+f(i+1,1,a,dp,cap)));
        else
        {
            profit=max((a[i]+f(i+1,1,a,dp,cap-1)),(0+f(i+1,0,a,dp,cap)));
        }
     return dp[i][buy][cap]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
               int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,prices,dp,k); 
    }
};