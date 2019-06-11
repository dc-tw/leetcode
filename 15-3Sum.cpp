class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int i=0, j=0, k=nums.size()-1;
		int num1 = 0;
		vector<int> t(3);
		vector<vector<int> > vt;

		for (i=0; i < k-1; )
		{
			num1 = 0-nums[i];
			t[0] = nums[i];
			for (j = i+1, k=nums.size()-1; j < k;)
			{
  		    if (nums[j] + nums[k] == num1){
					       t[1] = nums[j++];
                 t[2] = nums[k--];
                 vt.push_back(t);
                 while (j<k && nums[j] == nums[j-1]){
                    j++;
                  }
                  while (j<k && nums[k] == nums[k+1]){
                    k--;
                  }
          }
          else if (nums[j] + nums[k] < num1)j++;
          else k--;
      }
			i++;
			while (i<k-1 && nums[i] == nums[i-1])i++;
		}//for(; i<k-1; i++)
		return vt;
    }
};
/*
step1 sort
step2 pick the smallest
step3 find the others
*/
