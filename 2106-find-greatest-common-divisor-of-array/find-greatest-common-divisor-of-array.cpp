class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i: nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        int res = gcd(mini, maxi);
        return res;
    }
};