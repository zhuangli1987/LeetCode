class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        vector< vector<bool> > table;
        table.resize(n);
        for (int i = 0; i < n; ++i) {
            table[i].resize(n);
            for (int j = 0; j < n; ++j) {
                table[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i, k = i; j >= 0 && k < n; --j, ++k) {
                if (s[j] == s[k]) {
    				table[j][k] = true;
				} else {
    			    break;   
				}
            }
            for (int j = i, k = i + 1; j >= 0 && k < n; --j, ++k) {
                if (s[j] == s[k]) {
					table[j][k] = true;
				} else {
    			    break;   	
                }
            }
        }
        vector<int> dp;
        dp.resize(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = i;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (table[j][i]) {
                    if (j == 0) {
                        dp[i] = 0;
                        break;
                    } else {
                        dp[i] = min(dp[j - 1] + 1, dp[i]);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};