class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, t = 0, f = 0;
        int ans = 0;

        for (int right = 0; right < answerKey.size(); right++) {

            if (answerKey[right] == 'T') t++;
            else f++;

            while (min(t, f) > k) {
                
                if (answerKey[left] == 'T')
                    t--;
                else
                    f--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};