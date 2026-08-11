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

        auto it = find(arr.begin(), arr.end(), sum);
        if (it == arr.end()) {
            return sum;
        } else {
            sort(arr.begin(), arr.end());
            auto new_it = find(arr.begin(), arr.end(), sum);

            int index = new_it - arr.begin();

            for (int i = index + 1; i < arr.size(); i++) {
                if (arr[i] == sum + 1) sum += 1;
            }
        }
        return sum + 1 ;
    }
};