class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cnt = 0, left = 0;
        vector<string> result;
        for(int i =0; i< words.size(); i++)//each word
        {
            cnt += words[i].size();
            if(cnt+i-left > maxWidth || i+1==words.size())//each Maxsize or last
            {
                if(cnt+i-left > maxWidth) cnt -= words[i--].size();
                string str = words[left];
                for(int j = left+1; j<= i; j++)
                {
                    int m = maxWidth-cnt, n = i-left;
                    if(i+1==words.size()) str += " ";
                    else str.append(m/n + (j-left-1<m % n), ' ');
                    str += words[j];
                }
                str.append(maxWidth-str.size(), ' ');
                result.push_back(str);
                left = i+1, cnt = 0;
            }
        }
        return result;
    }
};