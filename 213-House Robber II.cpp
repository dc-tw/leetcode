class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int> info(n,0);
        for(int i=0;i<n-1;++i)
        {
            if(i==0) info[i]=nums[i];
            else if(i==1) info[i]=max(info[i-1],nums[i]);
            else
            {
                info[i]=max(info[i-1],nums[i]+info[i-2]);
            }
        }
        int tmp1=(n==1)?nums[0]:info[n-2];
        info[0]=0;
        info[1]=nums[1];
        for(int i=2;i<n;++i)
        {
            info[i]=max(info[i-1],nums[i]+info[i-2]);
        }
        int tmp2=info[n-1];
        return max(tmp1,tmp2);
    }
};