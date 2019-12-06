class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        const int n = nums.size();
        int r, l;
        vector<int> moves(2);    
        for (int i = 0; i < n; i++) {
            l = i == 0 ? INT_MAX : nums[i - 1];
            r = i == n - 1 ? INT_MAX : nums[i + 1];
            moves[i % 2] += max(0, nums[i] - min(l, r) + 1);
        }    
        return min(moves[0], moves[1]);
    }
};