class Solution {
public:
    int countCommas(int n) {
        int cnt = n - 1000;

        if(cnt < 0) return 0;
        else return cnt + 1;
    }
};