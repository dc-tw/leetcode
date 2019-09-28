class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, val = 0;
        for (int i = 0; i < S.size(); i ++) {
            if (S[i] == '(')
                ++val;
            else{
                --val;
                if (S[i - 1] == '(')
                    res += 1 << val;
            }
        }
        return res;
    }
};