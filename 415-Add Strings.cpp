class Solution {
public:
    string addStrings(string num1, string num2) {
        string num;
        int length1 = num1.length();
        int length2 = num2.length();
        int carry = 0;

        for(int i = length1 - 1, j = length2 - 1; i >= 0 || j >= 0; --i, --j)
        {
            int temp = 0;
            if(i >= 0)
            {
                temp += num1[i] - '0';
            }
            if(j >= 0)
            {
                temp += num2[j] - '0';
            }
            if(carry)
            {
                ++temp;
            }
            carry = temp / 10;
            temp = temp % 10;

            num = char(temp + '0') + num;
        }
        if(carry)
        {
            num = char(carry + '0') + num;
        }

        return num;
    }
};