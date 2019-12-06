class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int i, ds=0, cur=0;
        vector<int> res(seq.size(), 0);
        for(i=0; i<seq.length(); i++){
            if(seq[i] == '('){
                ++cur;
                ds = cur>ds? cur: ds;
            }
            else{
                --cur;
            }
        }
        ds /= 2;
        for(i=0; i<seq.length(); i++){
            if(seq[i] == '('){
                ++cur;
                if(cur>ds)res[i] = 1;
            }
            else{
                if(cur>ds)res[i] = 1;
                --cur;
            }
        }
        return res;
    }
};