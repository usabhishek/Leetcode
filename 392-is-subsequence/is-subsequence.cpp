class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.length();
        
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[t[i]].push_back(i);
        }

        int j = -1;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (mp.find(ch) != mp.end()) {

                vector<int> vec = mp[ch];

                auto it = upper_bound(vec.begin(), vec.end(), j);

                if (it != vec.end()) j = *it;
                else return false;
            } 
            else return false;
        }

        return true;
    }
};