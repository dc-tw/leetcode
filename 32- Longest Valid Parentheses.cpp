class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0)
            return 0;
        int res = 0;
        stack<int> stack1;
        stack1.push(-1);
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '('){
                stack1.push(i);
            }
            else{//')'
                stack1.pop();
                if(!stack1.empty()){
                    res = max(res, i-stack1.top());
                }
                else{//empty
                    stack1.push(i);
                }
            }
        }
        return res;
    }
};