class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_ind = 0, max_ind = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[min_ind])
                min_ind = i;

            if (nums[i] > nums[max_ind])
                max_ind = i;
        }

        int left = min(min_ind, max_ind);
        int right = max(min_ind, max_ind);

        // Delete both from the left
        int option1 = right + 1;

        // Delete both from the right
        int option2 = n - left;

        // Delete min/max from opposite sides
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};