class Solution {
public:
    long long gcd(long long a, long long b){
        while(b != 0){
            long long temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        long long res = 0;
        long long mx = INT_MIN;
        vector<long long> prefixGcd;

        for(long long i: nums){
            mx = max(mx, i);
            prefixGcd.push_back(gcd(i, mx));
        }

        sort(prefixGcd.begin(), prefixGcd.end());
        int n = prefixGcd.size();
        if(n == 1) return 0;
        
        int left = 0, right = n-1;
        while(left <= right){
            long long ans = gcd(prefixGcd[left], prefixGcd[right]);
            res += ans;
            left++;
            right--;

            if(left == right){
                break;
            }
        }

        return res;
    }
};