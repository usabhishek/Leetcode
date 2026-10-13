class Solution {
public:
    static long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int h = (n + 1) / 2;

        vector<long long> arr;
        arr.reserve(n);

        for (int x : nums) {
            long long v = x;
            arr.push_back(v * v);
        }

        nth_element(arr.begin(), arr.begin() + h, arr.end(),
                    greater<long long>());

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (i < h ? 1LL : -1LL) * arr[i];
        }

        return ans;
    }
};