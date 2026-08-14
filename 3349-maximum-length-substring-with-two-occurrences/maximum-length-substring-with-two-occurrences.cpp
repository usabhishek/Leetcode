class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<int, int> mp;

        int i = 0, j = 0;
        while(i < n){
            mp[s[i]]++;
            
            while(mp[s[i]] > 2){
                mp[s[j]]--;
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};