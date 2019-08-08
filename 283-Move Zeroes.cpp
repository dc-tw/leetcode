class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int num: nums){
            if(num == 0)continue;
            else{
                nums[i] = num;
                ++i;
            }
        }
        for(int j=0; j<nums.size()-i; ++j)nums[i+j] = 0;
    }
};