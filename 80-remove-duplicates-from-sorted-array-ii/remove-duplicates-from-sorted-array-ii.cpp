class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, j = 1;

        for(int i=1; i<nums.size(); i++){

            if(nums[i] == nums[i-1]) cnt++;
            else cnt = 1;

            if(cnt <= 2){
                nums[j++] = nums[i];
            }
        }

        for(int i: nums) cout << i << " ";
        return j;
    }
};