class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string a = s1;
        string b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) {
            return false;
        }
        
        if (s1 == s2) {
            return true;
        }
        
        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }
            string s32 = s1.substr(0, s1.size() - i);
            string s31 = s1.substr(s1.size() - i);
            if (isScramble(s21, s31) && isScramble(s22, s32)) {
                return true;
            }
        }
        return false;
    }
};