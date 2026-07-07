class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;

        while(n > 0){
            if(n%10 != 0){
                num = num * 10 + n%10;
                sum += n%10;
            }
             n /= 10;
        }

        long long rev = 0;
        while(num > 0){
            rev = rev * 10 + num%10;
            num /= 10;
        }

        return (long long) rev * sum;

    }
};