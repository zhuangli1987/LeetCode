class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        vector<int> dp;
        int n = prices.size();
        if (n< 2) {
            return ret;
        }
        int now = prices[0];
        for (int i = 1; i < n; ++i) {
            ret = max(ret, prices[i] - now);
            now = min(now, prices[i]);
        } 
        return ret;
        
    }
};