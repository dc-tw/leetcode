class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        for(int i=0;i<gas.size();i++)
        {
		    gas[i]=gas[i]-cost[i];
		    sum+=gas[i];
        }
        if(sum<0)return -1;
        int ans=0,tot=0;
        for(int i=0;i<gas.size();i++)
        {
        	tot+=gas[i];
        	if(tot<0)
        	{
	        	ans=i+1;
	        	tot=0;
	        }
        }
        return ans;
    }
};