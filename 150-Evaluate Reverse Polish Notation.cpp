class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
    	string operators = "+-*/";
    	int num1 = 0;
    	int num2 = 0;
 
    	for(int i = 0; i < tokens.size(); ++i)
    	{
    		int pos = operators.find(tokens[i]);
    		if(pos == string::npos)s.push(atoi(tokens[i].c_str()));
    		else
    		{
    			num2 = s.top();
    			s.pop();
    			num1 = s.top();
    			s.pop();
 
    			if(tokens[i] == "+")s.push(num1 + num2);
    			else if(tokens[i] == "-")s.push(num1 - num2);
    			else if(tokens[i] == "*")s.push(num1 * num2);
    			else{
					if(num2 != 0)s.push(num1 / num2);
				}
    			
    		}
    	}
 
    	return s.top();
    }
};