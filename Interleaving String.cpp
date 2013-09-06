class Solution {
public:
    bool ret;
    void dfs(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<bool> > &dp) {
        if (ret) {
            return;
        }
        if (dp[i][j]) {
            return;
        }
        dp[i][j] = true;
        if (k == s3.size()) {
            if (i == s1.size() && j == s2.size()) {
                ret = true;
            }
            return;
        }
        
        if (i < s1.size() && s1[i] == s3[k]) {
            dfs(s1, s2, s3, i + 1, j, k + 1, dp);            
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            dfs(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        ret = false;

        if (s1 == "") {
            return s2 == s3;
        }
        if (s2 == "") {
            return s1 == s3;
        }
        vector< vector<bool> > dp;
        dp.resize(s1.size() + 1);
        for (int i = 0; i <= s1.size(); ++i) {
            dp[i].resize(s2.size() + 1);
        }
        
        
        dfs(s1, s2, s3, 0, 0, 0, dp);
        return ret;
    }
};