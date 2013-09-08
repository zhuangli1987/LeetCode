class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int hash[256];
        hash['I'] = 1;
        hash['V'] = 5;
        hash['X'] = 10;
        hash['L'] = 50;
        hash['C'] = 100;
        hash['D'] = 500;
        hash['M'] = 1000;
        int n = s.size();
        int ret = 0;
        int mm = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (hash[s[i]] >= mm) {
                mm = hash[s[i]];
                ret += hash[s[i]];
            } else {
                ret -= hash[s[i]];
            }
        }
        return ret;
    }
};