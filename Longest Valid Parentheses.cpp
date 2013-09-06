class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> ss;
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (!ss.empty() && s[ss.top()] == '(' && ch == ')') {
                ss.pop();
                ret = max(ret, ss.empty() ? i + 1: i - ss.top()); 
            } else {
                ss.push(i);
            }
        }
        return ret;
    }
};