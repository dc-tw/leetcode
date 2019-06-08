class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, s=0;
        for(i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[s++] = nums[i];
            }

        }
        return s;
    }
};
