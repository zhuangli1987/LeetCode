class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string now = "1";
        for (int i = 0; i < n - 1; ++i) {
            string tp = "";
            int x = -1;
            char ch = '\0';
            for (int j = 0; j < now.size(); ++j) {
                if (x == -1) {
                    x = 1;
                    ch = now[j];
                    continue;
                }
                if (ch == now[j]) {
                    ++x;
                } else {
                    char xx[30];
                    sprintf(xx, "%d", x);
                    tp += xx;
                    tp += ch;
                    x = 1;
                    ch = now[j];
                }
            }
            if (x != -1) {
                char xx[30];
                sprintf(xx, "%d", x);
                tp += xx;
                tp += ch;
            }
            now = tp;
        }
        return now;
        
    }
};