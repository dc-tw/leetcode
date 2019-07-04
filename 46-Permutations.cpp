class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
		backtracking(nums, res, 0);
		return res;
	}

	void backtracking(vector<int>& nums, vector<vector<int>>& res,int begin) {
		if (begin>=nums.size()) {
			res.push_back(nums);
		}
		else {
			for (int i = begin; i < nums.size(); ++i) {
				swap(nums[begin], nums[i]);
				backtracking(nums, res, begin + 1);
				swap(nums[begin], nums[i]);
			}
		}
    }
};//tree traversal