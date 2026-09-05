class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> count(maxi + 1, 0);

        for (int x : nums) count[x]++;

        int smaller = 0;

        for (int i = 0; i <= maxi; i++) {
            int frequency = count[i];
            count[i] = smaller;

            smaller += frequency;
        }

        vector<int> res;
        for (int i: nums) {
            res.push_back(count[i]);
        }

        return res;
    }
};