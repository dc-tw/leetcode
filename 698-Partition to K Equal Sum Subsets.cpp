class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int mean = 0;
        for(auto n : nums)mean += n;
        sort(nums.rbegin(), nums.rend());   
        if(!mean%k)return 0;
        mean /= k;
        return dfs(nums, mean, 0, k, 0);
    }
private:
  bool dfs(const vector<int>& nums, int target, int cur, int k, int used) {
        if (k == 0) return used == (1 << nums.size()) - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (used & (1 << i)) continue;
            int t = cur + nums[i];
            if (t > target) break; // Important
            int new_used = used | (1 << i);
            if (t == target && dfs(nums, target, 0, k - 1, new_used)) return true; 
            else if (dfs(nums, target, t, k, new_used)) return true;
        }
        return false;
    }
};