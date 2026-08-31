/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next == nullptr)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        vector<int> idx;
        int ind = 1;

        while (curr->next != NULL) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val))
            {
                idx.push_back(ind);
            }

            ind++;
            prev = curr;
            curr = curr->next;
        }

        if (idx.size() < 2) return {-1, -1};

        int mini = INT_MAX;

        for (int i = 1; i < idx.size(); i++) {
            mini = min(mini, idx[i] - idx[i - 1]);
        }

        int maxi = idx.back() - idx.front();
        return {mini, maxi};
    }
};