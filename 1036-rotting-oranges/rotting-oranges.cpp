class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {
                        
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};