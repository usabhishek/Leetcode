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
    int pairSum(ListNode* head) {
        stack<int> st;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        int maxi = INT_MIN;
        cout<<slow->val<<endl;
        while(slow != NULL){
            int x = st.top(); st.pop();
            maxi = max(maxi, x+slow->val);
            slow = slow->next;
        }

        return maxi;
    }
};