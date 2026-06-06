class Solution {
public:
    vector<int> operations(int start, int end, vector<int>& nums,
                           vector<int>& res) {
        int num = 0;

        for (int i = start; (start < end) ? i < end : i > end;
             i = (start < end) ? i + 1 : i - 1) {

            int temp = nums[i];
            res.push_back(num);
            num += temp;
        }

        return res;
    }
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> lnums, rnums;
        
        lnums = operations(0, nums.size(), nums, lnums);
        rnums = operations(nums.size() - 1, -1, nums, rnums);
        reverse(rnums.begin(), rnums.end());

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(lnums[i] - rnums[i]);
        }

        return nums;
    }
};