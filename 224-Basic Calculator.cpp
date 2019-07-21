class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                num = 10 * num + (c - '0');
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
             } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};