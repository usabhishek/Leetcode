class Solution {
public:
    int missingInteger(vector<int>& arr) {
        int sum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1] + 1) {
                break;
            } else
                sum += arr[i];
        }

        while (find(arr.begin(), arr.end(), sum) != arr.end()) {
            sum++;
        }

        return sum;
    }
};