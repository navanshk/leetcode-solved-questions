class Solution {
public:
     int longestCommonSubsequence(string &a, string &b) {
    int m[1001][1001] = {};
    for (auto i = 0; i < a.size(); ++i)
        for (auto j = 0; j < b.size(); ++j)
            m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
    return m[a.size()][b.size()];

    }
    int longestPalindromeSubseq(string s) {
      string s1=s;
          reverse(s1.begin(),s1.end()); 
        return longestCommonSubsequence(s,s1);
    }
};