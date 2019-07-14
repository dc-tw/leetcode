class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n < 1) return 0;
        int tmp;
        int res = 0;
        for (int i = 1; i < n; ++i) {
            tmp = prices[i] - prices[i-1]; 
            if(tmp > 0) res += tmp;
        }
        return  res;
    }
};