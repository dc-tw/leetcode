class Solution {
public:
    int reverse(int x) {
        if (x == 0)return 0;
        long long sum = 0;
        while (x)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
            if (sum > INT_MAX || sum < INT_MIN)
                return 0;
        }
        return int(sum);
    }
};