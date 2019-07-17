class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        int remain = 0;
        while(n>0){
            remain = (n-1) % 26;
            res = (char)(remain + 'A') + res;
            n = (n-1) / 26;
        }
        return res;
    }
};