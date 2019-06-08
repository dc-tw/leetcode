class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)return 0;
        vector<int> v(256,-1);
        int len=s.length(),res=0,start=-1;

        for(int i=0; i<len; i++){//decrease times of calling s.length function
            if(v[s[i]] > start)//Slding window
                start = v[s[i]];
            v[s[i]] = i;
            res=max(res, i-start);
        }
        return res;
    }
};
