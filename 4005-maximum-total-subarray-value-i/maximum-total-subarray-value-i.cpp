class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long res;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i: nums){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }

        res = 1LL * (maxi - mini ) * k;
        return res;
    }
};