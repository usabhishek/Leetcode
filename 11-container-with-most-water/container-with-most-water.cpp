class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxi = INT_MIN;

        int start = 0, end = n-1;
        while(start <= end){
            int len = min(height[start], height[end]);
            int b = end- start;

            maxi = max(maxi, len * b);
            if(height[start] < height[end]) start++;
            else end--;
        }

        return maxi;
    }
};