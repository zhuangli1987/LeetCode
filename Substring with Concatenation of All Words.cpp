class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = S.size();
        int l = L.size();
        vector<int> ret;
        
        if (n == 0 || l == 0) {
            return ret;
        }   
        
        unordered_map<string, int> m;
        for (int i = 0; i < l; ++i) {
            ++m[L[i]];
        }
        int len = L[0].size();

        if (len * l > n) {
            return ret;
        }
        
        for (int i = 0; i < n - len * l + 1; ++i) {
            unordered_map<string, int> ct = m;
            bool flag = true;
            for (int j = 0; j < l; ++j) {
                string x = S.substr(j * len + i, len);
                if (ct[x]) {
                    --ct[x];
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret.push_back(i);
            }
        }
        return ret;
        
        
    }
};