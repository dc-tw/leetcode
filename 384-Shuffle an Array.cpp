class Solution {
public:
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(vec.size()==0) return vec;
        vector<int> tem=vec;
        int len = vec.size();
        for(int i = 0; i < len; i++)
        {
            int pos = rand()%(len-i);
            swap(tem[i+pos], tem[i]);
        }
        return tem;
    }
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */