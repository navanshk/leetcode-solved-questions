class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
    int m[1001][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];

    }
    int minDistance(string word1, string word2) {
       int n=word1.length()-longestCommonSubsequence(word1,word2);;
        int m=word2.length()-longestCommonSubsequence(word1,word2);
        
        return n+m;
    }
};