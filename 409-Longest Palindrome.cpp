class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freqs(128, 0);
        for (const char c : s)            
            ++freqs[c];
 
        int ans = 0;
        int odd = 0;
        for (const int freq : freqs) {            
            // same as: ans += freq % 2 == 0 ? freq : freq - 1;
            // same as: ans += freq / 2 * 2;
            // same as: ans += ((freq >> 1) << 1);            
            // same as: ans += freq & (INT_MAX - 1);
            ans += freq & (~1); // clear the last bit
            odd |= freq & 1;
        }
        
        ans += odd;
        
        return ans;
    }
};