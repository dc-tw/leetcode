class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1,end = -1;
        for(int i = 0;i<nums.size();i++){
            if (nums[i] == target)
            {
                if(start == -1)start = i;
                end = i;
            }
        }
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};