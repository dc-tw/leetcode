class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(k, n, 1, cur, ans);
        return ans;
    }
private:
    // Use k numbers (>= s) to sum up to n
    void dfs(int k, int n, int s, vector<int>& cur, vector<vector<int>>& ans) {
        if (k == 0) {
            if (n == 0) ans.push_back(cur);
            return;
        }
        
        for (int i = s; i <= 9; ++i) {
            if (i > n) return;
            cur.push_back(i);
            dfs(k - 1, n - i, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};