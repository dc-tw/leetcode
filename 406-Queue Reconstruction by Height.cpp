class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size()==0) return {};
        auto cmp = [](vector<int> a, vector<int> b) 
            {return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];};
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for(auto val: people)
            ans.insert(ans.begin() + val[1], val);
        return ans;
    }
};