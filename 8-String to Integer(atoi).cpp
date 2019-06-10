class Solution {
public:
    int myAtoi(string str) {
    	int i = 0;
    	while(str[i] == ' ')++i;

		int sign = 1;
		if(str[i] == '-')
		{
			sign = -1;
			++i;
		}
		else if(str[i] == '+')
		{
			++i;
		}

		long long res = 0;
    	while(str[i] != '\0')
    	{
    		if(str[i] >= '0' && str[i] <= '9')
    		{
    			res = res * 10 + (str[i] - '0');

    			if(res > INT_MAX)
    			{
    				return sign == -1 ? INT_MIN : INT_MAX;
    			}
    		}
    		else
    		{
    			break;
    		}
    		++i;
    	}
		return sign * res;
    }
};
