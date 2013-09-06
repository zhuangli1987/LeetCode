class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        int mm = INT_MAX;
        vector<int> p1, p2;
        p1.resize(n);
        p2.resize(n + 1);
        for (int i = 0; i < n; ++i) {
            mm = min(mm, prices[i]);
            p1[i] = max(prices[i] - mm, 0);
            if (i > 0) {
                p1[i] = max(p1[i - 1], p1[i]);
            }
        }
        mm = 0;
        for (int i = n - 1; i >= 0; --i) {
            mm = max(mm, prices[i]);
            p2[i] = max(0, mm - prices[i]);
            p2[i] = max(p2[i], p2[i + 1]);
        }
        mm = 0;
        for (int i = 0; i < n; ++i) {
            mm = max(mm, p1[i] + p2[i + 1]);
        }
        return mm;
    }
};