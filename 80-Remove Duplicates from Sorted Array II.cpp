class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int pre = 0, cur = 1, count = 1;
        while (cur < nums.size()) {
            if (nums[pre] == nums[cur] && count == 0) ++cur;
            else {
                if (nums[pre] == nums[cur]) --count;
                else count = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return pre + 1;
    }
};