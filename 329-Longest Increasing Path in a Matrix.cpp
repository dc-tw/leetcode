class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1)); 
        int ans = 0;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
                ans = max(ans, dfs(matrix, x, y));
        return ans;
    }
private:
    int dfs(const vector<vector<int>>& mat, int x, int y) {
        if (dp[y][x] != -1) return dp[y][x];
        static int dirs[] = {0, -1, 0, 1, 0};
        dp[y][x] = 1;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dirs[i];
            int ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || mat[ty][tx] <= mat[y][x])continue;
            dp[y][x] = max(dp[y][x], 1 + dfs(mat, tx, ty));
        }
        return dp[y][x];
    }
  
    int m;
    int n;
    // dp[i][j]: max length start from (j, i)
    vector<vector<int>> dp;  
    
};