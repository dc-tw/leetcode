class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        int num = t.size(), len=INT_MAX, start =0, left = 0;
        for(auto val: t) hash[val]++;
        for(int i =0; i < s.size(); i++)
        {
            if(hash[s[i]]-- >0) num--;
            while(num ==0)
            {
                len = (i-left+1)<len?(i-(start=left)+1):len;
                if(hash[s[left++]]++ ==0) num++;
            }
        }
        return len==INT_MAX?"":s.substr(start, len);
    }
};