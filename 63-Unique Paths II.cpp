class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector<long long> dp(m, 0);
		for (int j = 0; j < m; ++j) {
			if (!obstacleGrid[0][j])
				dp[j] = 1;
			else
				break;
		}
		for (int i = 1; i < n; ++i) {
			if (obstacleGrid[i][0])
				dp[0] = 0;
			for (int j = 1; j < m; ++j) {
				if (!obstacleGrid[i][j]) {
					dp[j] += dp[j - 1];
				}
				else
					dp[j] = 0;
			}
		}
		return dp[m-1];
    }
};