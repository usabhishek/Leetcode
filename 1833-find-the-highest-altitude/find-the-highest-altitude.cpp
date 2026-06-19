class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = INT_MIN;
        int curr = 0;
        for(int i: gain){
            curr += i;
            maxi = max(maxi, curr);
        }        

        return maxi < 0 ? 0 : maxi;
    }
};