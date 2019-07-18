class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int Min = INT_MAX, left = 0, cnt = 0, len = nums.size();
        for(int i = 0; i< nums.size(); i++)
        {
            cnt += nums[i];
            while(cnt >= s)
            {
                Min = min(Min, i-left+1);
                cnt -= nums[left++];
            }
        }
        return Min==INT_MAX?0:Min;
    }
};