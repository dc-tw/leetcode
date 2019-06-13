class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (target > 0 && target > 4 * nums.back()) return {};
        if (target < 0 && target < 4 * nums.front()) return {};
    
        unordered_map<int, int> index;//hash table
        for (int i = 0; i < nums.size(); ++i)//initialize
            index[nums[i]] = i;

        set<vector<int>> h;    
        int n = nums.size();
 
        for (int i = 0; i < n; i++) {   
            for (int j = i + 1; j < n; j++) {                
                for(int k = j + 1; k < n; k++) {
                    int t = target - nums[i] - nums[j] - nums[k];//find 3 first
                    if (t < nums[k]) break;
                    auto it = index.find(t);
                    if (it == index.end() || it->second <= k) continue;
                    h.insert({nums[i], nums[j], nums[k], t});
                }           
            }
        }
    return vector<vector<int>>(begin(h), end(h));
    }
};