class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int ret = INT_MAX;
        int rs = INT_MAX;
        sort(num.begin(), num.end());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int low = 0, high = n - 1;
                int t = target - num[i] - num[j];
                int res = 0;
                
                while(low <= high) {
                    int mid = (low + high) / 2;
                    if (num[mid] <= t) {
                        low = mid + 1;
                        res = mid;
                    } else {
                        high = mid -1;
                    }
                }
                
                for (int k = 0; k < 3; ++k) {
                    int ll = res - k;
                    int rr = res + k;
                    if (ll != i && ll != j && ll >= 0) {
                        int now = num[i] + num[j] + num[ll];
                        if (abs(now - target) < ret) {
                            ret = abs(now - target);
                            rs = now;
                        }
                    }
                    if (rr != i && rr != j && rr < n) {
                        int now = num[i] + num[j] + num[rr];
                        if (abs(now - target) < ret) {
                            ret = abs(now - target);
                            rs = now;
                        }
                    }
                }
            }
        }
        return rs;
    }
};