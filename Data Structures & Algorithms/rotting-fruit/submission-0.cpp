class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If there are no fresh oranges
        if (fresh == 0) {
            return 0;
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            // Process one level (one minute)
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int j = 0; j < 4; j++) {
                    int nrow = row + dr[j];
                    int ncol = col + dc[j];

                    if (nrow >= 0 && nrow < n &&
                        ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {

                        // Make fresh orange rotten
                        grid[nrow][ncol] = 2;
                        fresh--;

                        q.push({nrow, ncol});
                    }
                }
            }

            minutes++;
        }

        // If some fresh oranges are still left
        return (fresh == 0) ? minutes : -1;
    }
};