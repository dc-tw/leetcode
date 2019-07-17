class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, min = INT_MAX;
        while(l<r){
            if(nums[l]<nums[r])return nums[l];
            l++;
        }
        return nums[l];
    }
};
