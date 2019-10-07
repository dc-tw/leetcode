class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(S)) return 0;
        int ans = 0;
        dfs(nums, 0, S, ans);
        return ans;
    }
private:
    void dfs(vector<int>& nums, int d, int S, int& ans) {
        if (d == nums.size()) {
            if (S == 0) ++ans;
            return;
        }    
        dfs(nums, d + 1, S - nums[d], ans);
        dfs(nums, d + 1, S + nums[d], ans);
    }
};