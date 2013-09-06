class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(digits.begin(), digits.end());
        int add = 1;
        for (int i = 0; i < digits.size(); ++i) {
            digits[i] += add;
            if (digits[i] >= 10) {
                digits[i] -= 10;
                add = 1;
            }  else {
                add = 0;
            }
        }
        if (add) {
            digits.push_back(add);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};