class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)return 1;
        long res = 1, tmp = 2;
        while(tmp!=n){
            tmp = tmp << 1;
            ++res;
            if(tmp>n)return 0;
        }
        return 1;
    }
};