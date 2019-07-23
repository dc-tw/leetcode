class Solution {
public:
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */