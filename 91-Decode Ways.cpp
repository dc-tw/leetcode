class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s.empty()) return 0;
        if(s[0]=='0') return 0;
        vector<int> info(n+1,0);
        info[0]=1;
        info[1]=1;
        for(int i=2;i<n+1;++i)
        {
            if(s[i-1]!='0') info[i]+=info[i-1];
            if(s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") info[i]+=info[i-2];
        }
        return info[n];
    }
};