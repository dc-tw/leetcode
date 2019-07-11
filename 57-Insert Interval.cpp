class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end()); 
        
        for (int i=0; i < intervals.size(); i++) {
            if (res.size() > 0 && res.back()[1] >= intervals[i][0]){
                vector<int> tmp{min(res.back()[0], intervals[i][0]), max(res.back()[1], intervals[i][1])};
                res.back() = tmp;
            }    
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};