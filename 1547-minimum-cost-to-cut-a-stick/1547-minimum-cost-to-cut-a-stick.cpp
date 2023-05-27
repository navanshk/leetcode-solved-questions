class Solution {
public:
  int pre(int i,int j,vector<int>& cuts,vector<vector<int>> & dp){
                if(i > j) return 0;
                if(dp[i][j] != -1) return dp[i][j];
                long mini = 1e9;
                for(int ind=i;ind<=j;ind++){
                    long cost = cuts[j+1] - cuts[i-1] + pre(i,ind-1,cuts,dp) + pre(ind+1,j,cuts,dp);
                    mini = min(mini,cost);
                }
                return dp[i][j] = mini;
            }
            int minCost(int n, vector<int>& cuts) {
                int c = cuts.size();
                // cuts size missing  ⭐
                cuts.insert(cuts.begin(),0);
                cuts.push_back(n);
                sort(cuts.begin(),cuts.end());
                
                // vector<vector<int>> dp(n+4,vector<int> (n+4,-1)); ⭐
                vector<vector<int>> dp(c+1,vector<int> (c+1,-1));
                // return pre(1,cuts.size()-2,cuts,dp); ⭐    
                return pre(1,c,cuts,dp);
            }
};