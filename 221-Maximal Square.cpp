class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> sizes(m, vector<int>(n, 0));
        
        int ans = 0;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                sizes[i][j] = matrix[i][j] - '0';
                if (!sizes[i][j]) continue;                            
                
                if (i == 0 || j == 0) {
                    // do nothing
                } 
                else if (i == 0)
                    sizes[i][j] = sizes[i][j - 1] + 1;
                else if (j == 0)
                    sizes[i][j] = sizes[i - 1][j] + 1;
                else
                    sizes[i][j] = min(min(sizes[i - 1][j - 1], sizes[i - 1][j]), sizes[i][j - 1]) + 1;
                
                ans = max(ans, sizes[i][j]*sizes[i][j]);
            }
        return ans;
    }
};