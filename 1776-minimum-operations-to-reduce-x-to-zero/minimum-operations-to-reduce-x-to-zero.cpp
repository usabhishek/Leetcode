class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long target = total - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int l = 0;
        long long curr = 0;
        int maxLen = -1;

        for (int r = 0; r < n; r++) {
            curr += nums[r];

            while (curr > target && l <= r) {
                curr -= nums[l];
                l++;
            }

            if (curr == target) {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};