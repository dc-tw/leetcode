class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for(int i=1;i<=n;i++) nums+=i+'0';
        string res;
        vector<int> multi(n,1);
        for(int i=1;i<n;i++) multi[i]=multi[i-1]*i;
        for(int i=n-1;i>=0;--i){
            int a = k / multi[i];
            k = k % multi[i];
            if(k==0){
                res.push_back(nums[a-1]);
                nums.erase(a-1,1);
                reverse(nums.begin(),nums.end());
                res+=nums;
                return res;
            }
            else if(k==1){
                res.push_back(nums[a]);
                nums.erase(a,1);
                res+=nums;
                return res;
            }
            else{
                res.push_back(nums[a]);
                nums.erase(a,1);
            }
        }
        return res;
    }
};