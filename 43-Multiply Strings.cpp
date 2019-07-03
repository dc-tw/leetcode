class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size() + num2.size(), '0');
        for (int i = num1.size() - 1; i >= 0; i--) {//start from tail, for each digit
            for (int j = num2.size() - 1; j >= 0; j--) {
                int ii = num1[i] - '0';//convert to demical
                int jj = num2[j] - '0';
                int tmp = (result[(i+j+1)] - '0') + ii * jj;
                result[i+j+1] = tmp % 10 + '0';
                result[i+j] += tmp / 10;
            }
        }
        size_t startpos = result.find_first_not_of("0");
        if (string::npos != startpos) {
            return result.substr(startpos);
        }
        return "0";
    }
};