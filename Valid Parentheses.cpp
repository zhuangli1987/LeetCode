class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> st;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                st.push(s[i]);
            }
            if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                if (ch == '[' && s[i] != ']') {
                    return false;
                }
                if (ch == '{' && s[i] != '}') {
                    return false;
                }
                if (ch == '(' && s[i] != ')') {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};