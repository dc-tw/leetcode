class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
    }
};