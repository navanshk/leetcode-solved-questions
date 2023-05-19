class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
        if(i==0&&j==0)
            return grid[i][j];
        if(i<0||j<0)
            return (1e+7);
        if(dp[i][j]!=-1)
            return dp[i][j];
      long long int up=grid[i][j]+f(i-1,j,grid,dp);
       long long int left=grid[i][j]+f(i,j-1,grid,dp);
        return dp[i][j]= min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};