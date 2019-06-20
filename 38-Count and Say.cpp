class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n;i++){
            string tmp = "";
            int cnt = 0;
            char s = res[0];
            int j = 0;
            int len = res.size();
            while(j < len){
                if(res[j] != s){
                    tmp += to_string(cnt);
                    tmp += s;
                    s = res[j];
                    cnt = 1;
                }else{
                    cnt++;
                }
                if(j == len-1){
                    tmp += to_string(cnt);
                    tmp += s;
                }

                j++;
            }
            res = tmp;
        }
        return res;
    }
};