class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int r = 0;
        if(!K%2 || !K%5) return -1;
        for(int i=0; i<=K; ++i){
            r = (r *10 +1)%K;
            if(!r)return i+1;
        }
        return -1;
    }
};