class TrieNode {
  public: 
    TrieNode* child[2] ; 
    
    TrieNode() {
        this->child[0] = this->child[1] = 0 ; 
    }
};

class Solution {
public:
    TrieNode *nd ; 
    
    void insert(int x) {
        TrieNode* t = nd ; 
        bitset<32> b(x) ; 
        for(int i = 31; i >=0 ; i--) {
            if(!t->child[b[i]])
                t->child[b[i]] = new TrieNode() ; 
            t = t->child[b[i]] ;   
        }
    }
    
    int solve(int n) {
        TrieNode* t = nd ; 
        bitset<32> b(n) ; 
        int ct =0 ; 
        for(int i = 31; i >=0 ; i--) {
            if(t->child[!b[i]])
                ct += (1 << i) , t = t->child[!b[i]] ; 
            else 
                t = t->child[b[i]] ;   
        }
        return ct ; 
    }
    
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& queries) {
        vector<pair<pair<int, int>, int> > q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({{queries[i][0], queries[i][1]}, i});
        sort(q.begin(), q.end(), [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
            return a.first.second < b.first.second;
        });
        sort(a.begin(), a.end()) ; 
        vector<int> ans(q.size(), -1) ; 
        nd = new TrieNode() ; 
        int idx = 0 ; 
        for(int i =0 ; i < q.size() ; i++) {
            int comp = q[i].first.first, lim = q[i].first.second, ptr = q[i].second ; 
            while(idx < a.size() and a[idx] <= lim)
                insert(a[idx++]) ; 
            if(idx>0)
                ans[ptr] = solve(comp) ; 
        }
        return ans ; 
    }
};
