class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        if (s.size() < 3) return *max_element(s.begin(), s.end());
        s.erase(*max_element(s.begin(), s.end()));
        s.erase(*max_element(s.begin(), s.end()));
        return *max_element(s.begin(), s.end());
    }
};