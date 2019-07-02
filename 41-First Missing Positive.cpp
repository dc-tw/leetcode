class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0||nums[i]>n||(nums[nums[i]-1]==nums[i])) continue;
            swap(nums[nums[i]-1],nums[i]);
            i--;
        }//reorder
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};