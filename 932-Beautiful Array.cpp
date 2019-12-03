class Solution {
private:
    vector<int> dfs(int N) {
        if (N == 1) return {1};
        vector<int> left = dfs((N+1) /2);//odd
        vector<int> right = dfs(N/2);//even
        vector<int> res;
        for (int x: left)
            res.push_back(x*2 - 1);
        for (int x: right)
            res.push_back(x*2);
        return res;
    }
public:
    vector<int> beautifulArray(int N) {
        if (N == 1) return {1};
        return dfs(N);
    }
};
