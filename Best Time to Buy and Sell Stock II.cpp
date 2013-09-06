class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, ret + (prices[i] - prices[i - 1]));
        }
        return ret;
    }
};