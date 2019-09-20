class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int n=S.length();
        vector<string> res{""};
        for(int i=0;i<n;i++)
        {
            int len=res.size();
            if(S[i]>='0' && S[i]<='9')
                for(int j=0;j<len;j++)res[j].push_back(S[i]);
            else
                for(int j=0;j<len;j++){
                    res.push_back(res[j]);
                    res[j].push_back(tolower(S[i]));
                    res[j+len].push_back(toupper(S[i]));
                }
        }
        return res;
    }
};