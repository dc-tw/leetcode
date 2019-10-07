class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!M[i][i]) continue;
            ++ans;
            dfs(M, i, n);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& M, int curr, int n) {        
        for (int i = 0; i < n; ++i) {
            if (!M[curr][i]) continue;
            M[curr][i] = 0;
            M[i][curr] = 0;
            dfs(M, i, n);
        }
    }
};