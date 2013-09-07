class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> s;
        int n = height.size();
        vector<int> ll, rr;
        ll.resize(n);
        rr.resize(n);
        for (int i = 0; i < n; ++i) {
            ll[i] = 0;
            rr[i] = n - 1;
        }
        for (int i = 0; i < n; ++i) {
            while (!s.empty()) {
                int now = s.top();
                if (height[now] >= height[i]) {
                    s.pop();
                } else {
                    ll[i] = now + 1;
                    break;
                }
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty()) {
                int now = s.top();
                if (height[now] >= height[i]) {
                    s.pop();
                } else {
                    rr[i] = now - 1;
                    break;
                }
            }
            s.push(i);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            ret = max(ret, ( (i - ll[i] + 1) + (rr[i]- i + 1) - 1)  * height[i]);
        }
        return ret;
    }
};