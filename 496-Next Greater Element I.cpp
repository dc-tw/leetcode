class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> next;
        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                next[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
      
        vector<int> ans;
        for (int num : nums1)
            ans.push_back(next.count(num) ? next[num] : -1);
        return ans;
    }
};