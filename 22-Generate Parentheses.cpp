class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
    	generate(n, n, "", res);//recursive
    	return res;
    }
 
    void generate(int left, int right, string str, vector<string>& res)
    {
    	if(left == 0 && right == 0)
    	{
    		res.push_back(str);
    		return;
    	}
    	if(left > 0)
    	{
    		generate(left - 1, right, str + '(', res);
    	}
    	if(right > left)
    	{
    		generate(left, right - 1, str + ')', res);
    	}
    }
};