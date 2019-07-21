class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n=input.size();
        int i;
        vector<int> lRes;
        vector<int> rRes;
        vector<int> res;
        string lStr;
        string rStr;
        if(!myMap[input].empty())
            return myMap[input];
        else{
            for(i=0;i<n;i++){
              if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                lStr=input.substr(0,i);
                rStr=input.substr(i+1);
                lRes=diffWaysToCompute(lStr);
                rRes=diffWaysToCompute(rStr);
                for(auto n1:lRes){
                    for(auto n2:rRes){
                        if(input[i]=='+')
                           res.push_back(n1+n2);
                        if(input[i]=='-')
                           res.push_back(n1-n2);
                        if(input[i]=='*')
                           res.push_back(n1*n2);
                        }
                    }
               }       
            }    
        }
        if(res.empty()){
            res.push_back(atoi(input.c_str()));
            return res;
        }        
        myMap[input]=res;
        return res;   
    }
private:
    unordered_map<string,vector<int>> myMap;
};