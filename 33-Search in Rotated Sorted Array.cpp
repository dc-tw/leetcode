class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), left = 0, right = len-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] >= nums[0])
            {
                if(target < nums[mid] && target >= nums[0]) right = mid-1;
                else left = mid+1;
            }
            else
            {
                if(target > nums[mid] && target < nums[0]) left = mid+1;
                else right = mid-1;
            }
        }
        return -1;
    }
};