class NumArray {
public:
    NumArray(vector<int>& nums) {
        vec = nums;
    }
    
    int sumRange(int i, int j) {
        ans = 0;
        for(int cnt = i; cnt <= j; ++cnt){
            ans += vec[cnt];
        }
        return ans;
    }
private:
    vector<int> vec;
    int ans;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */