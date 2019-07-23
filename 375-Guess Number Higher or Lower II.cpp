class Solution {
public:
    int getMoneyAmount(int n) {
        if(n ==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1; i > 0; i--)
        {
            for(int j = i+1; j <=n; j++)
            {
                int ans = INT_MAX;
                for(int k = i; k <j; k++)
                    ans = min(ans, k + max(dp[i][k-1], dp[k+1][j]));
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};