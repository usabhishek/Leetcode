class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int i: nums){
            int sum = 0;

            while(i > 0){
                sum+=i%10;
                i /= 10;
            }

            mini = min(sum, mini);
        }

        return mini;
    }
};