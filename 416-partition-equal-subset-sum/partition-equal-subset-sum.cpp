class Solution {
public:
    bool check(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum == 0) return true; 
        if(i == 0) return nums[0] == sum;

        if(dp[i][sum] != -1) return dp[i][sum];

        int take = false;
        if(nums[i] <= sum){
            take = check(i-1, sum - nums[i], nums, dp);
        }

        bool nottake = check(i-1, sum, nums, dp);

        return dp[i][sum] = take | nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i: nums) sum += i;

        if(sum % 2 != 0) return false;
        sum /= 2;

        vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));

        return check(n-1, sum, nums, dp);
    }
};