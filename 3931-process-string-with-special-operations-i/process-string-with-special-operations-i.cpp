class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c: s){
            if(c >= 'a' && c <= 'z') res.push_back(c);
            if(c == '#') res += res;
            if(c == '%') reverse(res.begin(), res.end());
            else if(c == '*' && !res.empty()) res.pop_back();
        }

        return res;
    }
};