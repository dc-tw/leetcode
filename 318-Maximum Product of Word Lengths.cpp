class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        vector<int> vec(len, 0);
        int res = 0;
        for (int i = 0; i < len; ++i)
        {
            for (auto c : words[i])
            {
                vec[i] |= 1 << (c - 'a');
            }
        }

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if ((vec[i] & vec[j]) == 0)
                {
                    res = max(res, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};