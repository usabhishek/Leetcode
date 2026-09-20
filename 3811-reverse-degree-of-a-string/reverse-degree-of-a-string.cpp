class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;

        for(auto i=1; i<=s.size(); i++){
            int rev_ind = 26 - (int)(s[i - 1] - 'a');
            res += (i * rev_ind);
        }
        
        return res;
    }
};