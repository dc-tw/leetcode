class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Map;
        for (int num : nums1) {
            nums1Map[num]++;
        }
        vector<int> res;
        for (int num : nums2) {
            if (nums1Map.find(num) != nums1Map.end() && nums1Map[num] != 0) {
                res.push_back(num);
                nums1Map[num]--;
            }
        }
        return res;
    }
};