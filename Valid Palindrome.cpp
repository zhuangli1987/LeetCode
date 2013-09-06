class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string m = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                m += s[i];
            }
            if (s[i] >= '0' && s[i] <= '9') {
                m += s[i];
            }
        }

        int low = 0, high = m.size() - 1;
        while (low < high) {
            if (m[low] != m[high]) {
                return false;
            }
            ++low, --high;
        }
        return true;
    }
};