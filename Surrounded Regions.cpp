class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<int> q;
        int n = board.size();
        if (n == 0) {
            return;
        }
        int m = board[0].size();
        if (m == 0) {
            return;
        }
        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                q.push(0);
                q.push(i);
            }
            if (board[n - 1][i] == 'O') {
                q.push(n - 1);
                q.push(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                q.push(i);
                q.push(0);
            }
            if (board[i][m - 1] == 'O') {
                q.push(i);
                q.push(n - 1);
            }
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            board[x][y] = 'P';
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx >= 0 && tx < board.size() && ty >= 0 && ty < board.size() && board[tx][ty] == 'O') {
                    q.push(tx);
                    q.push(ty);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'P') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};