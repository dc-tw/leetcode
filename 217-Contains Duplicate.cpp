class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        unordered_map<int, int> hash;
        for(int i=0; i<nums.size(); i++){
            if(!hash.count(nums[i]))hash[nums[i]]++;
            else return true;
        }
        return false;
    }
};