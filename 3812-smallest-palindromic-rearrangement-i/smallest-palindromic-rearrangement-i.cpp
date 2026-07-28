class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> c(26,0);

        for(auto it: s){
            c[it - 'a']++;
        }

        int i=0, j=n-1;
        for(int k=0; k<26; k++){
            while(i < j && c[k] > 1){
                s[i++] = (char)('a' + k);
                s[j--] = (char)('a' + k);
                c[k] -= 2;
            }
        }

        return s;
    }
};
      