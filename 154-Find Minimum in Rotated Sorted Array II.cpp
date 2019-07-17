class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
    int findMin(const vector<int>& num, int l, int r)
    {
        if (l+1 >= r) return min(num[l], num[r]);
        if (num[l] < num[r])return num[l];
        int m = l + (r-l)/2;
        return min(findMin(num, l, m - 1),findMin(num, m, r));
    }
};