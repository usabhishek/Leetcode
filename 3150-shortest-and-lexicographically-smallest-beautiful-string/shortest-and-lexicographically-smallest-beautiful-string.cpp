class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        set<string> st;

        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int curr = 0;
            int j = i;

            while (j < n && curr < k) {
                if (s[j] == '1') curr++;
                j++;
            }

            if (curr == k) {
                int len = j - i;

                if (len < mini) {
                    mini = len;

                    st.clear();
                    st.insert(s.substr(i, len));
                } 
                
                else if (len == mini) st.insert(s.substr(i, len));
            }
        }

        return st.empty() ? "" : *st.begin();
    }
};