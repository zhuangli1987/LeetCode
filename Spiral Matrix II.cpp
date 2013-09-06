class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        ret.resize(n);
        for (int i = 0; i < n; ++i) {
            ret[i].resize(n);
            for (int j = 0; j < n; ++j) {
                ret[i][j] = -1;
            }
        }
        int i = 0, j = 0;
        int d = 0;
        int now = 1;
        while (now <= n * n) {
            if (i < 0 || j < 0 || i >= n || j >= n || ret[i][j] != -1) {
                i -= dx[d];
                j -= dy[d];
                d = (d + 1) % 4;
            } else {
                ret[i][j] = now;
                ++now;
            }
            i = i + dx[d];
            j = j + dy[d];
        }
        return ret;
    }
};