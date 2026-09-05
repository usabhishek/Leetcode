class Solution {
public:
    // If required TC is O(nlogn) we can use 
    // std::sort() -- If allowed
    // Merge sort(Stable) and Heap sort(In-place)
    // Counting sort - O(n+k) -- In all cases,  
    // Quick sort (very common, can try if avg case works) -- Unstable and in-place sorting
    // Bucket sort -O(n2 in worst case and O(n+k) in avg and best case)    

    vector<int> sortArray(vector<int>& nums) {
        // Couting sort with handling negative numbers

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> count(maxi - mini + 1, 0);

        for (int x : nums)
            count[x - mini]++;

        int idx = 0;

        for (int i = 0; i < count.size(); i++) {
            while (count[i]--) {
                nums[idx++] = i + mini;
            }
        }

        return nums;
    }
};