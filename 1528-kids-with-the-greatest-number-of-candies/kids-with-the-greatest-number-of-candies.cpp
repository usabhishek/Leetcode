class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxi = INT_MIN;

        for(int i: candies){
            if(i > maxi) maxi = i;
        }

        for(int i: candies){
            if(i + extraCandies >= maxi) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};