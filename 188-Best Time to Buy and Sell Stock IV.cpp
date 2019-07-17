class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        int len = prices.size(), ans =0;
        if(k>=len/2)
        {
            for(int i=1; i<len; i++) 
                if(prices[i]-prices[i-1]>0) ans += prices[i]-prices[i-1];
            return ans; 
        }
        vector<int> buy(len+1, INT_MIN), sell(len+1, 0);
        for(auto val: prices)
        {
            for(int i=1; i<= k; i++)
            {
                buy[i] = max(sell[i-1]-val, buy[i]);
                sell[i] = max(buy[i]+val, sell[i]);
            }
        }
        return sell[k];
    }
};