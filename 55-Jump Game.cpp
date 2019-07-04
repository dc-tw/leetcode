class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (!len)return false;
        int G = nums[0];
        for(int i =1; i<len;i++){
            if(G<i)return false;
            G = max(G,nums[i]+i);
            if(G>len)return true;
        }
        return G>=len-1;
    }
};