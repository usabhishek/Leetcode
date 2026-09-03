class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcnt = 0;
        int n = nums1.size();
        int minOdd = INT_MAX;

        for (int i=0; i<n; i++) {
            if (nums1[i]%2 != 0) {
                oddcnt++;
                minOdd = min(minOdd, nums1[i]);
            }
        }

        if (oddcnt == 0 || oddcnt == n) return true;

        for (int i=0; i<n; i++) {
            if (nums1[i] % 2 == 0 && nums1[i] <= minOdd) {
                return false;
            }
        }

        return true;
    }
};