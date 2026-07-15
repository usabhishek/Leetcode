class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    int gcdOfOddEvenSums(int n) {
        int sum1 = 0, sum2 = 0;
        for(int i=1; i<=n; i++){
            sum1 += 2*i;
        }
        
        for(int i=0; i<n; i++){
            sum2 += (2*i) + 1;
        }

        int res = gcd(sum1 , sum2);
        return res;
    }
};