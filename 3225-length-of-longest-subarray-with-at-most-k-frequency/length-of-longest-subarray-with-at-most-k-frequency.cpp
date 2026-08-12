class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        int i = 0, j = 0, n = nums.size();
        int res = 0;

        while(i < n){
            mp[nums[i]]++;

            while(mp[nums[i]] > k){
                mp[nums[j]]--;
                j++;
            }

            res = max(res, i - j + 1);
            i++;
        }

        return res;
    }
};