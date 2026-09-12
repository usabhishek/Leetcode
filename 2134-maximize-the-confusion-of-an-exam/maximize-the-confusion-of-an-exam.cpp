class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int left = 0, f = 0, ansT = 0; // Everything T
        
        for (int right = 0; right < n; right++) {

            if (answerKey[right] == 'F')
                f++;

            while (f > k) {
                if (answerKey[left] == 'F')
                    f--;

                left++;
            }

            ansT = max(ansT, right - left + 1);
        }

        left = 0;
        int t = 0, ansF = 0;  // Everything F

        for (int right = 0; right < n; right++) {

            if (answerKey[right] == 'T')
                t++;

            while (t > k) {
                if (answerKey[left] == 'T')
                    t--;

                left++;
            }

            ansF = max(ansF, right - left + 1);
        }

        return max(ansT, ansF);
    }
};