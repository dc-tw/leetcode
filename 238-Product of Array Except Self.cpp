class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,len;
        len = nums.size();
        vector<int> arr,left,right;
        int tmp;
        tmp = 1;
        for(i=0;i<len;i++){
            tmp = tmp * nums[i];
            left.push_back(tmp);
        }
        tmp = 1;
        for(i=len-1;i>=0;i--){
            tmp = tmp * nums[i];
            right.push_back(tmp);
        }
        arr.push_back(right.at(len-2));
        for(i=1;i<len-1;i++){
            arr.push_back(right[len-2-i]*left[i-1]);
        }
        arr.push_back(left.at(len-2));
        return arr;
    }
};
