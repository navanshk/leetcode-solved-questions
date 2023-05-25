class Solution {
   public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        if(i<0 and j<0) return true;
        if(j<0 and i>=0) return false;
        if(i<0 and j>=0) {
			
            for(int k=0; k<=j; k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
    
        if(s[i]==p[j] or p[j]=='?')
            return dp[i][j] = solve(s,p,i-1,j-1,dp);
            
		
        if(p[j]=='*')
            return dp[i][j] = solve(s,p,i-1,j,dp) or solve(s,p,i,j-1,dp);
            
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};