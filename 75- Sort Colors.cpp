class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len,i;
        len = nums.size();
        int max=0;
        for(i = 0; i<len; i++){
            if(max<nums[i])max = nums[i];
        }
        int range[max+1] = {0};
        //for(i = 0; i<max+1; i++)range[i]=0;
        for(i = 0; i<len; i++){
            range[nums[i]]++;
        }
        int pivot=0;
        for(i = 0; i<max+1; i++){
            while(range[i]>=1){
                --range[i];
                nums[pivot] = i;
                ++pivot;
            }
        }
    }
};
