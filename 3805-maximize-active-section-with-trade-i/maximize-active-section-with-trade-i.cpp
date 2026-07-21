class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        string t = "1" + s + "1";

        vector<int> len;
        vector<char> ch;

        int cnt = 1;
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == t[i - 1]) {
                cnt++;
            } else {
                len.push_back(cnt);
                ch.push_back(t[i - 1]);
                cnt = 1;
            }
        }
        len.push_back(cnt);
        ch.push_back(t.back());

        int gain = 0;

        for (int i = 1; i + 1 < len.size(); i++) {
            if (ch[i] == '1' && ch[i - 1] == '0' && ch[i + 1] == '0') {

                gain = max(gain, len[i - 1] + len[i + 1]);
            }
        }

        return ones + gain;
    }
};

// 1. Add 1 at both ends.
// 2. Make blocks.
// 3. For every 0 | 1 | 0:
//       gain = left0 + right0
// 4. ans = totalOnes + max(gain)