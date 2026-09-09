class Solution {
public:
    long long countCommas(long long n) {
        vector<long long> nums = {999, 999999, 999999999, 999999999999, 999999999999999};
        long long cnt = 0;

        for(auto i=0; i<nums.size(); i++){
            if(n > nums[i]) cnt += (n - nums[i]);
        }

        return (cnt < 0) ? 0 : cnt;
    }
};

// 1,000,000,000,000,000
// [1000: 1,000,000 : 1,000,000,000, 1,000,000,000,000: 1,000,000,000,000,000]
