class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned s = 8 * sizeof(n);
        uint32_t mask = ~0;
        while ((s = s >> 1) > 0) {
            mask ^= mask << s;
            n = ((n >> s) & mask) | ((n << s) & (~mask));
        }
        return n;
    }
};