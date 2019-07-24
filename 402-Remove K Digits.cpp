class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int n = k, len = num.size(), cnt = 0;
        for(auto val: num)
        {
            while(!ans.empty() && n > 0 && val < ans.back())
            {
                n--;
                ans.pop_back();
            }
            ans.push_back(val);
        }
        while(ans[cnt]=='0') cnt++;
        ans = ans.substr(cnt, len-k-cnt);
        return !ans.size()?"0":ans;
    }
};