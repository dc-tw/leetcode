class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return dfs(N, nums);
    }
private:
    int dfs(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (n % nums[i] == 0 || nums[i] % n == 0) {
                swap(nums[i], nums[n - 1]);
                res += dfs(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};