class Solution {
public:
    int f(int i,int j,string &a, string &b,vector<vector<int>>&dp)
    {
         int n=a.length();
      int m=b.length();
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j] =1 +f(i-1,j-1,a,b,dp);
        
        return dp[i][j]=max(f(i-1,j,a,b,dp),f(i,j-1,a,b,dp));
        
    }
  int longestCommonSubsequence(string &a, string &b) {
   int n=a.length();
      int m=b.length();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return f(n-1,m-1,a,b,dp);

    }
};