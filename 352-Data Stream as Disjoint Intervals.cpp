class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> newInterval{val, val};
        vector<vector<int>> res;
        int cur = 0;
        for (auto interval : intervals) {
            if (newInterval[1] + 1 < interval[0]) {
                res.push_back(interval);
            } else if (newInterval[0] > interval[1] + 1) {
                res.push_back(interval);
                ++cur;
            } else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        intervals = res;
    }
    vector<vector<int>> getIntervals() {
        return intervals;
    }
private:
    vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */