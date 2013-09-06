class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = board.size();
        int m = board[0].size();
        vector< set<char> > row, col, bol;
        row.resize(n);
        col.resize(m);
        bol.resize(n * m / 9);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (row[i].find(board[i][j]) != row[i].end()) {
                    return false;
                } else {
                    row[i].insert(board[i][j]);
                }
                if (col[j].find(board[i][j]) != col[j].end()) {
                    return false;
                } else {
                    col[j].insert(board[i][j]);
                }
                if (bol[i / 3 * 3 + j / 3].find(board[i][j]) != bol[i / 3 * 3 + j / 3].end()) {
                    return false;
                } else {
                    bol[i / 3 * 3 + j / 3].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};