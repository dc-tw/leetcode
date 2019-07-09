class Solution {
public:
    int mySqrt(int x) {
        unsigned int ans = 1;
        if(x < 1) return 0;
        while(x > ans*ans) ++ans;
        if(x == ans*ans)++ans;
        return ans-1;
    }
};