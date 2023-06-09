class Solution {
public:
        unordered_map<int, vector<int>> adj;
    vector<bool> vis, rec;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto x: prerequisites) adj[x[1]].push_back(x[0]);
        vis = vector<bool> (numCourses);
        rec = vector<bool> (numCourses);

        for (int i=0; i<numCourses; i++)
            if (!vis[i] and dfs(i)) return false;

        return true;
    }

    bool dfs(int i) {
        vis[i] = true;
        rec[i] = true;
        
        for (auto x: adj[i])
            if ((!vis[x] && dfs(x)) || rec[x]) 
                return true;
        
        rec[i] = false;
        
        return false;
    }

};