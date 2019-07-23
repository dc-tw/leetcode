class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int len = nums.size(), ans = len, flag = 0;
        for(int i = 1; i < len; i++)
        {
            if(nums[i]-nums[i-1] == 0) ans--;
            else if(nums[i]-nums[i-1]>0) flag==1?ans--:flag=1;
            else if(nums[i]-nums[i-1]<0) flag==-1?ans--:flag=-1;
        }
        return ans;
    }
};