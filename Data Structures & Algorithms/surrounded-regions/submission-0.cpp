class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size() &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Left and right boundaries
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }

        // Top and bottom boundaries
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[n - 1][j] == 'O')
                dfs(n - 1, j, board);
        }

        // Final conversion
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};