class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i = 0; i <= num; ++i)
            for(int h : nums(i, 12))
                for(int m : nums(num - i, 60))
                    ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));//int to str
        return ans;
    }

private:
  // Return numbers in [0,r) that has b 1s in their binary format.
    vector<int> nums(int b, int r) {    
    vector<int> ans;
    for(int n = 0; n < r; ++n)
        if(__builtin_popcount(n) == b) ans.push_back(n);//count bits in binary
    return ans;
    } 
};