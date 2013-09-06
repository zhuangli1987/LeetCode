class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(num1.size() & 3) {
            num1 = "0" + num1;
        }
        while(num2.size() & 3) {
            num2 = "0" + num2;
        }
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        vector<int> n1, n2, res;

        for (int i = 0, x = 0; i < num1.size(); ) {
            int t = 0;
            ++x;
            for (int j = 0; j < 4; ++j, ++i) {
                t = 10 * t + num1[num1.size()  - 4 * x + j] - '0';
            }
            n1.push_back(t);
        }

        for (int i = 0, x = 0; i < num2.size(); ) {
            int t = 0;
            ++x;
            for (int j = 0; j < 4; ++j, ++i) {
                t = 10 * t + num2[num2.size() - 4 * x + j] - '0';
            }
            n2.push_back(t);
        }

        res.resize(n1.size() + n2.size() + 10);
        const int MAXN = 10000;
        const int D = 4;

        for (int i = 0; i < n2.size(); ++i) {
            for (int j = 0; j < n1.size(); ++j) {
                res[j + i] += n2[i] * n1[j];
            }
            for (int j = 0; j < n1.size() + i; ++j) {
                int b = res[j + i];
                res[j + i] = b % MAXN;
                res[j + i + 1] += b / MAXN;
            }
        }
        int i = res.size() - 1;
        for (; i >= 0; --i) {
            if (res[i] != 0) {
                break;
            }
        }
        string rt = "";
        for (; i >= 0; --i) {
            char x[20];
            sprintf(x, "%04d", res[i]);
            rt += string(x);
        }
        i = 0;
        string rt2;
        for (; i < rt.size(); ++i) {
            if (rt[i] != '0') {
                break;
            }
        }
        for (; i < rt.size(); ++i) {
            rt2 += rt[i];
        }
        if (rt2 == "") {
            return "0";
        }
        return rt2;
    }
};