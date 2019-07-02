class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,temp,res);
        vector<vector<int>> result;
        for(auto mem:res)
        {
            result.push_back(mem);
        }
        return result;
    }
    
    void dfs(const vector<int> &candidates,int target,int index,vector<int> &temp,set<vector<int>> &res)
    {
        if(target<0) return;
        if(target==0)
        {
            res.insert(temp);
            return;
        }
        while(index<candidates.size())
        {
            temp.push_back(candidates[index]);
            dfs(candidates,target-candidates[index],index+1,temp,res);
            temp.pop_back();
            ++index;
        }
    }
};