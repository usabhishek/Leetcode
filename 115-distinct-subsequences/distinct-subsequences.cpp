class Solution {
public:

    int solve(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        // j tells us how much of t we have already matched.
        if (j == t.size()) return 1;

        // s is finished but t is still remaining
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int pick = 0;

        if (s[i] == t[j]) {
            pick = solve(i + 1, j + 1, s, t, dp);
        }
        
        int notPick = solve(i + 1, j, s, t, dp); //skip s[i] -- 

        return dp[i][j] = pick + notPick;
    }


    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, s, t, dp);
    }
};