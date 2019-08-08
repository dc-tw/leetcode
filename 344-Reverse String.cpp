class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> res = s;
        int len = s.size();
        for(int i=0; i<len; ++i){
            res[len-i-1]= s[i];
        }
        s = res;  
    }
};