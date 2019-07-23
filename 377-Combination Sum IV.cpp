class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        res = vector<int>(target + 1, -1);
        res[0] = 1;
        return dp(nums, target);
    }    
private:
    int dp(const vector<int>& nums, int target) {
        if (target < 0) return 0;
        if (res[target] != -1) return res[target];
        int ans = 0;
        for (const int num : nums)
            ans += dp(nums, target - num);
        return res[target] = ans;
    }
    vector<int> res;
};
/*
vector<int> dp(target + 1, 0); // dp[i] # of combinations sum up to i
dp[0] = 1;
for (int i = 1; i <= target; ++i)
    for (const int num : nums)
        if (i - num >= 0)
            dp[i] += dp[i - num];
return dp[target];
*/