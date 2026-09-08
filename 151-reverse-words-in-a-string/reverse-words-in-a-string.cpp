class Solution {
public:
    string reverseWords(string s) {
        vector<string> res;
        string curr = "";
        for(char c: s){
            if(c != ' ') curr += c;
            else{
                if(curr != "") res.push_back(curr);
                curr = "";
            }
        }

        if(curr != "") res.push_back(curr);

        reverse(res.begin(), res.end());
        string ans = "";

        for(int i=0; i<res.size(); i++){
            ans += res[i];

            if(i != res.size() - 1) ans += " ";
        }

        return ans;
    }
};