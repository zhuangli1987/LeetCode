class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n = s.size();
        vector<string> v;
        v.resize(nRows);
        int big = (n * 2 + nRows )/ nRows;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < big; ++j) {
                v[i].push_back(' ');
            }
        }
        int x = 0, y = 0;
        for (int i = 0; i < n;) {
            int g = y % 2;
            if (g == 0) {
                for (int j = 0; j < nRows && i < n; ++j, ++i) {
                    v[j][y] = s[i];
                }
                ++y;
            } else {
                for (int j = nRows - 2; j > 0 && i < n; --j, ++i) {
                    v[j][y] = s[i];
                }
                ++y;
            }
        }
        string ret = "";
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
               if (v[i][j] != ' ') {
                   ret+=v[i][j];
               }
            }
        }
        
        return ret;
    }
};