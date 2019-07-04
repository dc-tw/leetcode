class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len ==1)return 0;
        int G = nums[0],Gstep = G, R=1;
        for(int i=1; i<len-1; i++){
            G = max(( nums[i]+i ),G);
            if(i >= Gstep){
                Gstep = G;
                R++;
            }
            if(Gstep > len) return R;
        }
        return R;
    }
};