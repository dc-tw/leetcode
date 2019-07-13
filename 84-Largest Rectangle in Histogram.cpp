class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
                continue;
            }
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};