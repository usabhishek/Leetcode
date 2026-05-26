class Solution {
public:
    int numberOfSpecialChars(string word) {
        char lower[26] = {};
        char upper[26] = {};

        int cnt = 0;

        for(char c: word){
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = c;
            }
            else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = c;
            }
        }

        for(int i=0; i<26; i++){
            if(lower[i] != '\0' && upper[i] != '\0') cnt++;
        }

        return cnt;
    }
};