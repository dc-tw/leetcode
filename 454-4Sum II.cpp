class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sums;
        for (int a : A)
            for (int b : B)
                ++sums[a + b];
        int ans = 0;
        for (int c : C)
            for (int d : D) {
                auto it = sums.find(- c - d);
                if (it != sums.end()) ans += it->second;          
            }
        return ans;
    }
};