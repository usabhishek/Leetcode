class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix_min(n);

        int mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < mini) mini = nums[i];
            suffix_min[i] = mini;
        }

        int maxi = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) maxi = nums[i];
            if (maxi - suffix_min[i] <= k) return i;
        }

        return -1;
    }
};