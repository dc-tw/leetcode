class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        int ans = -1;
        queue<pair<int, int> > q;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 1) q.push({i, j});
        vector<int> dirs{0, -1, 0, 1, 0};
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front(); q.pop();
                int x = p.second;
                int y = p.first;
                if (grid[y][x] == 2) ans = max(ans, steps);
                for (int i = 0; i < 4; ++i) {
                    int tx = x + dirs[i];
                    int ty = y + dirs[i + 1];
                    if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0) continue;
                    grid[ty][tx] = 2;
                    q.push({ty, tx});
                }
            }
            ++steps;
        }
        return ans;
    }
};