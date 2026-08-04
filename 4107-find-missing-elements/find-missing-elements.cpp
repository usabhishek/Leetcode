class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        vector<int> res;
        sort(nums.begin(), nums.end());

        int j = 0;

        for (int i = mini; i <= maxi; i++) {
            if (nums[j] == i) j++;
            else{
                res.push_back(i);
            }
        }

        return res;
    }
};