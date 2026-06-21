class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxcost = 0;
        for(int i: costs){
            maxcost = max(maxcost, i);
        }

        vector<int> count(maxcost+1 , 0);
        for(int cost: costs){
            count[cost]++;
        }

        int bars = 0;
        int remainingcoins = coins;

        for(int i=1; i<=maxcost; i++){
            if(count[i] > 0){
                int canbuy = min(count[i], remainingcoins/i);
                bars += canbuy;
                remainingcoins -= canbuy * i;

                if(canbuy == 0) break;
            }
        }

        return bars;
    }
};