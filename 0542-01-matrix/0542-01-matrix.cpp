class Solution {
private:
    queue<pair<pair<int,int>,int>> getStartingPoint(vector<vector<int>>&mat,vector<vector<int>>&vis){
        int n = mat.size(), m = mat[0].size();
        queue<pair<pair<int,int>,int>>  q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }
        return q;
    }
    vector<vector<int>> bfs(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> movements {{0,1},{0,-1},{1,0},{-1,0}};
        auto isValid = [&](int x,int y){return x>=0 && x<n && y>=0 && y<m;};
        vector<vector<int>> dist(n,vector<int>(m,0)), vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>  q = getStartingPoint(mat,vis);
        while(!q.empty()){
            int i = q.front().first.first, j = q.front().first.second, d = q.front().second;
            q.pop();
            for(auto [x,y]: movements){
                x += i, y += j;
                if(isValid(x,y) && !vis[x][y]){
                    if(mat[x][y]) q.push({{x,y},d+1});
                    else q.push({{x,y},d});
                    mat[x][y] ? dist[x][y] = d + 1 : dist[x][y] = 0;
                    vis[x][y] = true;
                }
            }
        }
        return dist;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }
};