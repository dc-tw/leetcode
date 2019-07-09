class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
    	int i = digits.size() - 1;
    	for(; i >= 0; --i)
    	{
    		digits[i] += carry;
    		if(digits[i] >= 10)
    		{
    			digits[i] -= 10;
    			carry = 1;
    		}
    		else
    		{
    			carry = 0;
    			break;
    		}
    	}
    	if(i == -1 && carry == 1)digits.insert(digits.begin(), 1);
    	return digits;
    }
};