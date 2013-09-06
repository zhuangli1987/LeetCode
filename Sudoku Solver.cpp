struct node {
  int row, col, block;  
};
class Solution {
public:
    bool ret;
    void dfs(vector<vector<char> > &board, vector<node> &res, int pos, vector<vector <bool> > &row, vector<vector <bool> > &col, vector<vector <bool> > &block) {
        if (pos == res.size()) {
            ret = true;
            return;
        }
        if (ret) {
            return;
        }
        for (int i = '1'; i <= '9' && !ret; ++i) {
            int x = i - '0';
            if (row[res[pos].row][x] || col[res[pos].col][x] || block[res[pos].block][x]) {
                continue;
            }
            row[res[pos].row][x] = col[res[pos].col][x] = block[res[pos].block][x] = true;
            board[res[pos].row][res[pos].col] = i;
            dfs(board, res, pos + 1, row, col, block);
            row[res[pos].row][x] = col[res[pos].col][x] = block[res[pos].block][x] = false;
        }
        
    }
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> res;
        int n = board.size();
        vector<vector <bool> > rows, cols, blocks;
        rows.resize(n + 1);
        cols.resize(n + 1);
        blocks.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            rows[i].resize(n + 1);
            cols[i].resize(n + 1);
            blocks[i].resize(n + 1);
            for (int j = 0; j <= n; ++j) {
                rows[i][j] = false;
                cols[i][j] = false;
                blocks[i][j] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int row = i;
                int col = j;
                int block = i / 3 * 3 + j / 3;
                if (board[i][j] == '.') {
                    node t;
                    t.row = row;
                    t.col = col;
                    t.block = block;
                    res.push_back(t);
                } else {
                    int x = board[i][j] - '0';
                    rows[row][x] = true;
                    cols[col][x] = true;
                    blocks[block][x] = true;
                }
            }
        }
        ret = false;
        dfs(board, res, 0, rows, cols, blocks);
    }
};