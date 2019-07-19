class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k <= 0) return false;
        if(nums.size()<2) return false;
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i ++){
            if(hash.find(nums[i]) == hash.end())
                hash.insert({nums[i], i});
            else{
                if(i - hash[nums[i]] <= k)return true;
                else hash[nums[i]] = i;
            }
        }
        return false;
    }
};