class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
                int n = graph.size();
        vector<int> vis(n, -1);
        queue<int> q; 
        for (int i = 0; i < n; i++) 
        {
            if (vis[i] == -1)
            {
                vis[i] = 0;
                q.push(i);
                while (!q.empty())
                {
                    int u = q.front(); q.pop();
                    for (int v : graph[u]) 
                    {
                        if (vis[v] == -1)
                        { 
                            vis[v] = vis[u] ^ 1; 
                            q.push(v); 
                        } 
                        else if (vis[v] == vis[u])
                        {
                            return false;
                        }
                    }
                }
            } 
        }
        return true;

    }
};