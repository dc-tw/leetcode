class NumArray {
public:
    NumArray(vector<int>& nums) {
        data = nums;
    }
    
    void update(int i, int val) {
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; ++k) {
            sum += data[k];
        }
        return sum;
    }
private:
    vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */