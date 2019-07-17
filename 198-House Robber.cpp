class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int dp2 = 0;
        int dp1 = 0;
        for (int i = 0; i < nums.size() ; ++i) {
            int dp = max(dp2 + nums[i], dp1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp1;
    }
};