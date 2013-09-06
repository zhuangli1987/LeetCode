class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.size() < b.size()) {
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < b.size(); ++i) {
            a[i] += (b[i] - '0');
        }
        int add = 0;
        
        for (int i = 0; i < a.size(); ++i) {
            a[i] += add;
            if (a[i] >= '2') {
                a[i] -= 2;
                add = 1;
            } else {
                add = 0;
            }
        }
        if (add) {
            a = a + "1";
        }
        reverse(a.begin(), a.end());
        return a;
    }
};