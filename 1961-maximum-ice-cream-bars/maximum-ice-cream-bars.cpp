class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;

        for(int i : costs){
            if(i <= coins){
                cnt++;
            }else break;
            coins -= i;
        }
        return cnt;
    }
};