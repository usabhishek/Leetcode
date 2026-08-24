class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long maxsum = 0;

        for (int i = 1; i <= n; i++) {
            long long currentsum = 0;
            for (int x = 1; i * x * x <= n; x++) {
                int idx = i * x * x;
                currentsum += nums[idx-1];
            }
            maxsum = max(maxsum, currentsum);
        }
        return maxsum;
    }
};