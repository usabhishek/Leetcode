class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first, second;

        for(int i: nums){
            if(i > first){
                second = first;
                first = i;
            }

            else if(i > second && (i != first || i == first)){
                second = i;
            }
        }

        return (first-1) * (second - 1);
    }
};