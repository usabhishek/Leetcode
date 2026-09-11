class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, cnt = 0;

        for(int i: nums){
            if(cnt == 0){
                    candidate = i;
                    cnt += 1;
            }

            else if (i == candidate) cnt++;
            else cnt--;
        }

        return candidate;
    }
};