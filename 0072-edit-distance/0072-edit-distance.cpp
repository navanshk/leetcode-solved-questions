class Solution {
public:
    int f(int i,int j,string &s, string &t,vector<vector<int>>&dp)
    {
         int n=s.length();
        int m=t.length();
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
           return dp[i][j]=0+f(i-1,j-1,s,t,dp);
        else
        {   int insertion=1+f(i,j-1,s,t,dp);
            int del=1+f(i-1,j,s,t,dp);
          int replace=1+f(i-1,j-1,s,t,dp);
            return dp[i][j]=min(insertion,min(del,replace));
        }
        
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};