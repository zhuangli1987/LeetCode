class Solution {
public:
    bool ret;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    void dfs(int i, int j, int pos, string &word, vector<vector<char> > &board) {
        if (pos == word.size()) {
            ret = true;
            return;
        }
        if (i == board.size() || j == board[0].size() || i < 0 || j < 0) {
            return;
        }
        if (ret || board[i][j] != word[pos]) {
            return;
        }
        char ch = board[i][j];
        for (int d = 0; d < 4; ++d) {
            board[i][j] = '.';
            dfs(i + dx[d], j + dy[d], pos + 1, word, board);
            board[i][j] = ch;
        }
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret = false;
        int n = board.size();
        if (word.size() == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, 0, word, board);
            }
        }
        return ret;
    }
};