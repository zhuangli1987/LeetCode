class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int now = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                now = i;
                break;
            }
        }
        int now2 = n - 1;
        for (int i = n - 1; i > now; --i) {
            if (num[i] > num[now]) {
                now2 = i;
                break;
            }
        }
        swap(num[now], num[now2]);
        sort(num.begin() + now + 1, num.end());
    }
};